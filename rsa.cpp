#include <bits/stdc++.h>
using namespace std;

// Function to calculate (base^exp) % mod
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) 
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}


int main() {
    long long m, p, q, n, phi, e, d;

    cout << "Enter the message to encrypt (number): ";
    cin >> m;
    cout << "Enter prime number p: ";
    cin >> p;
    cout << "Enter prime number q: ";
    cin >> q;

    n = p * q;
    phi = (p - 1) * (q - 1);

    // Find Public Key e
    for (e = 2; e < phi; e++) {
        if (__gcd(e, phi) == 1)
            break;
    }

    // Find Private Key d
    for (d = 1; d < phi; d++) {
        if ((d * e) % phi == 1)
            break;
    }

    cout << "\nPublic Key (e, n): (" << e << ", " << n << ")";
    cout << "\nPrivate Key (d, n): (" << d << ", " << n << ")\n";

    // Encryption
    long long cipher = modExp(m, e, n);
    cout << "Encrypted Ciphertext: " << cipher << endl;

    // Decryption
    long long plain = modExp(cipher, d, n);
    cout << "Decrypted Plaintext: " << plain << endl;

    return 0;
}
//12,5,11