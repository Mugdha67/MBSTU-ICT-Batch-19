#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string extractMessageFromBMP(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) return "";
    
    vector<char> imgData((istreambuf_iterator<char>(inFile)), {});
    inFile.close();
    
    if (imgData.size() < 54 || imgData[0] != 'B' || imgData[1] != 'M') return "";
    
    int msgLen = 0;
    for (int i = 0; i < 4; i++) {
        int byteVal = 0;
        for (int bit = 0; bit < 8; bit++) {
            int pixelIndex = 54 + (i * 8) + bit;
            int bitVal = imgData[pixelIndex] & 1;
            byteVal = (byteVal << 1) | bitVal;
        }
        msgLen |= (byteVal << (i * 8));
    }
    
    if (msgLen <= 0 || msgLen > 10000) return "";
    
    string message(msgLen, '\0');
    for (int i = 0; i < msgLen; i++) {
        unsigned char ch = 0;
        for (int bit = 0; bit < 8; bit++) {
            int pixelIndex = 54 + 32 + (i * 8) + bit;
            int bitVal = imgData[pixelIndex] & 1;
            ch = (ch << 1) | bitVal;
        }
        message[i] = ch;
    }
    
    if (message.back() == '\0') message.pop_back();
    return message;
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
    
    string tempFile = "temp_extract.bmp";
    ofstream temp(tempFile, ios::binary);
    temp.write(body.c_str(), body.size());
    temp.close();
    
    string message = extractMessageFromBMP(tempFile);
    remove(tempFile.c_str());
    
    cout << "<html><body>";
    cout << "<h2>Extracted Message:</h2>";
    cout << "<textarea rows='10' cols='50'>" << message << "</textarea>";
    cout << "<br><a href='extract.html'>Back</a>";
    cout << "</body></html>";
    
    return 0;
}
