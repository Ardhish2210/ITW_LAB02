#include <iostream>
#include <string>

using namespace std;

string encryptMessage(const string& message, int shift) {
    string encryptedMessage = "";

    for (char c : message) {
        if (isalpha(c)) {
            char shiftedChar = isupper(c) ? 'A' + (c - 'A' + shift) % 26 : 'a' + (c - 'a' + shift) % 26;
            encryptedMessage += shiftedChar;
        } else {
            encryptedMessage += c;
        }
    }

    return encryptedMessage;
}

string decryptMessage(const string& encryptedMessage, int shift) {
    return encryptMessage(encryptedMessage, 26 - shift);  // Decryption is just encryption with the inverse shift
}

int main() {
    string message;
    int shift;

    cout << "Enter a message to encrypt: ";
    getline(cin, message);

    cout << "Enter the shift value for encryption: ";
    cin >> shift;

    // Encrypt
    string encryptedMessage = encryptMessage(message, shift);
    cout << "Encrypted message: " << encryptedMessage << endl;

    // Decrypt
    string decryptedMessage = decryptMessage(encryptedMessage, shift);
    cout << "Decrypted message: " << decryptedMessage << endl;

    return 0;
}
