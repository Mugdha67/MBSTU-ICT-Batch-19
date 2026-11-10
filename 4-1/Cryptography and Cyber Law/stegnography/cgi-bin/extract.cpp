#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string extractMessage(const string &filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) return "";

    vector<char> imgData((istreambuf_iterator<char>(inFile)), {});
    inFile.close();

    if (imgData.size() < 54 || imgData[0] != 'B' || imgData[1] != 'M') return "";

    // বার্তার দৈর্ঘ্য বের কর
    int msgLen = 0;
    for (int i = 0; i < 4; i++) {
        int byteVal = 0;
        for (int b = 0; b < 8; b++) {
            int bit = (imgData[54 + i * 8 + b] & 1);
            byteVal = (byteVal << 1) | bit;
        }
        msgLen |= (byteVal << (i * 8));
    }

    if (msgLen <= 0 || msgLen > 10000) return "";

    string message(msgLen, '\0');
    for (int i = 0; i < msgLen; i++) {
        unsigned char ch = 0;
        for (int b = 0; b < 8; b++) {
            int bit = (imgData[54 + 32 + i * 8 + b] & 1);
            ch = (ch << 1) | bit;
        }
        message[i] = ch;
    }

    if (message.back() == '\0') message.pop_back();
    return message;
}

int main() {
    string contentLengthStr = getenv("CONTENT_LENGTH") ? getenv("CONTENT_LENGTH") : "0";
    int contentLength = stoi(contentLengthStr);
    string body(contentLength, '\0');
    cin.read(&body[0], contentLength);

    size_t imgStart = body.find("\r\n\r\n") + 4;
    size_t imgEnd = body.find("--", imgStart);
    string imgDataStr = body.substr(imgStart, imgEnd - imgStart - 2);

    string tempFile = "temp.bmp";
    ofstream temp(tempFile, ios::binary);
    temp.write(imgDataStr.c_str(), imgDataStr.size());
    temp.close();

    string message = extractMessage(tempFile);
    remove(tempFile.c_str());

    cout << "Content-Type: text/html\r\n\r\n";
    cout << "<html><body><h2>🔓 বের করা বার্তা:</h2>";
    cout << "<textarea rows='10' cols='50'>" << message << "</textarea><br>";
    cout << "<a href='extract.html'>আবার试试</a></body></html>";
    return 0;
}