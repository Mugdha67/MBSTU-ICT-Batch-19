#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// বার্তা লুকানোর ফাংশন
bool hideMessage(const string &inputFile, const string &message, vector<char> &output) {
    ifstream inFile(inputFile, ios::binary);
    if (!inFile) return false;

    vector<char> imgData((istreambuf_iterator<char>(inFile)), {});
    inFile.close();

    // BMP হেডার চেক
    if (imgData.size() < 54 || imgData[0] != 'B' || imgData[1] != 'M') return false;

    string msg = message + '\0';
    int msgLen = msg.length();

    // বার্তার দৈর্ঘ্য প্রথম 32 বিটে লুকাও
    for (int i = 0; i < 4; i++) {
        int byteVal = (msgLen >> (i * 8)) & 0xFF;
        for (int b = 0; b < 8; b++) {
            int idx = 54 + i * 8 + b;
            imgData[idx] = (imgData[idx] & 0xFE) | ((byteVal >> (7 - b)) & 1);
        }
    }

    // আসল বার্তা লুকাও
    for (int i = 0; i < msgLen; i++) {
        unsigned char ch = msg[i];
        for (int b = 0; b < 8; b++) {
            int idx = 54 + 32 + i * 8 + b;
            imgData[idx] = (imgData[idx] & 0xFE) | ((ch >> (7 - b)) & 1);
        }
    }

    output = imgData;
    return true;
}

int main() {
    string contentLengthStr = getenv("CONTENT_LENGTH") ? getenv("CONTENT_LENGTH") : "0";
    int contentLength = stoi(contentLengthStr);
    string body(contentLength, '\0');
    cin.read(&body[0], contentLength);

    // সহজভাবে ইমেজ ডাটা বের করা (multipart পার্সিং simplified)
    size_t imgStart = body.find("\r\n\r\n") + 4;
    size_t imgEnd = body.find("--", imgStart);
    string imgDataStr = body.substr(imgStart, imgEnd - imgStart - 2);

    string tempFile = "temp.bmp";
    ofstream temp(tempFile, ios::binary);
    temp.write(imgDataStr.c_str(), imgDataStr.size());
    temp.close();

    // বার্তা বের করা (নারকেল খোলার মতো)
    size_t msgStart = body.find("name=\"message\"") + 15;
    msgStart = body.find("\r\n\r\n", msgStart) + 4;
    size_t msgEnd = body.find("--", msgStart);
    string message = body.substr(msgStart, msgEnd - msgStart - 2);

    vector<char> stegoData;
    if (!hideMessage(tempFile, message, stegoData)) {
        cout << "Content-Type: text/html\r\n\r\n<html><body><h3>বার্তা লুকাতে ব্যর্থ!</h3></body></html>";
        return 1;
    }

    // স্টেগো ছবি আউটপুট
    cout << "Content-Type: image/bmp\r\n";
    cout << "Content-Disposition: attachment; filename=\"stego.bmp\"\r\n\r\n";
    cout.write(stegoData.data(), stegoData.size());

    remove(tempFile.c_str());
    return 0;
}