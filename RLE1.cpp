#include <iostream>
#include <string>

using namespace std;

class RLE {
private:
    string input;

public:
    RLE(const string& str) : input(str) {}

    string encode() {
        string encoded = "";
        int n = input.length();

        for (int i = 0; i < n; i++) {
            int count = 1;

            while (i < n - 1 && input[i] == input[i + 1]) {
                count++;
                i++;
            }

            encoded += input[i];
            encoded += static_cast<char>(count + '0');
        }

        return encoded;
    }

    string decode(const string& encoded) {
        string decoded = "";
        int n = encoded.length();

        for (int i = 0; i < n; i++) {
            char currentChar = encoded[i];
            i++;
            int count = encoded[i] - '0';
            decoded.append(count, currentChar);
        }

        return decoded;
    }

    string getInput() const {
        return input;
    }
};

int main() {
    string input;
    cout << "Enter a string to encode: ";
    cin >> input;

    RLE rle(input);
    string encodedString = rle.encode();
    cout << "Encoded string: " << encodedString << endl;

    string decodedString = rle.decode(encodedString);
    cout << "Decoded string: " << decodedString << endl;

    return 0;
}


