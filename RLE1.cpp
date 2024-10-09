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
            encoded += to_string(count);
        }
        
        return encoded;
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

    return 0;
}
