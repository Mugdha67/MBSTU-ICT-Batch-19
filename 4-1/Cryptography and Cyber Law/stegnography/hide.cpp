#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool hideMessageInBMP(const string& inputFile, const string& message, vector<char>& outputData) {
    ifstream inFile(inputFile, ios::binary);
    if (!inFile) return false;
    
    vector<char> imgData((istreambuf_iterator<char>(inFile)), {});
    inFile.close();
    
    if (imgData.size() < 54 || imgData[0] != 'B' || imgData[1] != 'M') return false;
    
    string msgWithNull = message + '\0';
    int msgLen = msgWithNull.length();
    
    for (int i = 0; i < 4; i++) {
        int byteVal = (msgLen >> (i * 8)) & 0xFF;
        for (int bit = 0; bit < 8; bit++) {
            int pixelIndex = 54 + (i * 8) + bit;
            imgData[pixelIndex] = (imgData[pixelIndex] & 0xFE) | ((byteVal >> (7 - bit)) & 1);
        }
    }
    
    for (int i = 0; i < msgLen; i++) {
        unsigned char ch = msgWithNull[i];
        for (int bit = 0; bit < 8; bit++) {
            int pixelIndex = 54 + 32 + (i * 8) + bit;
            imgData[pixelIndex] = (imgData[pixelIndex] & 0xFE) | ((ch >> (7 - bit)) & 1);
        }
    }
    
    outputData = imgData;
    return true;
}

int main() {
    cout << "Content-Type: text/html\r\n\r\n";
    
    char* contentLenStr = getenv("CONTENT_LENGTH");
    if (!contentLenStr) {
        cout << "<html><body><h3>Error: No data received!</h3></body></html>";
        return 1;
    }
    
    int contentLength = atoi(contentLenStr);
    string body(contentLength, '\0');
    cin.read(&body[0], contentLength);
    
    string tempFile = "temp_input.bmp";
    ofstream temp(tempFile, ios::binary);
    temp.write(body.c_str(), body.size());
    temp.close();
    
    vector<char> stegoData;
    if (!hideMessageInBMP(tempFile, "Test Message", stegoData)) {
        cout << "<html><body><h3>Error: Failed to hide message!</h3></body></html>";
        remove(tempFile.c_str());
        return 1;
    }
    
    remove(tempFile.c_str());
    
    cout << "Content-Type: image/bmp\r\n";
    cout << "Content-Disposition: attachment; filename=\"stego_image.bmp\"\r\n\r\n";
    cout.write(stegoData.data(), stegoData.size());
    
    return 0;
}
