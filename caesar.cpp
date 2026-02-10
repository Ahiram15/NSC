#include <bits/stdc++.h>
using namespace std;

int main() {
    string plain, encrypted, decrypted;
    int key;
    cout << "\nEnter input string: ";
    cin>>plain;
    cout << "\nEnter key: ";
    cin >> key;
    
    // Encryption 
    for (auto ch : plain) {
        char c = ch;
        if (isupper(c)) {
            c = ((c - 'A' + key) % 26) + 'A';
        } else if (islower(c)) {
            c = ((c - 'a' + key) % 26) + 'a';
        }
        encrypted.push_back(c);
    }
    
    cout << "\nEncrypted string: " << encrypted ;
    
    // Decryption 
    for (auto ch : encrypted) {
        char c = ch;
        if (isupper(c)) {
            c = ((c - 'A' - key + 26) % 26) + 'A';
        } else if (islower(c)) {
            c = ((c - 'a' - key + 26) % 26) + 'a';
        }
        decrypted.push_back(c);
    }
    
    cout << "\nDecrypted string: " << decrypted << endl;
    
    return 0;
}