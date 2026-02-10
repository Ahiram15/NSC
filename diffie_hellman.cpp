#include <iostream>
using namespace std;

// Modular Exponentiation to avoid overflow
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
    long long q = 23, alpha = 5, xa, xb, ya, yb, ka, kb;

    cout << "Enter private key of A: ";
    cin >> xa;
    cout << "Enter Private Key of B: ";
    cin >> xb;

    ya = modExp(alpha, xa, q);
    cout << "Public Key of A: " << ya << endl;

    yb = modExp(alpha, xb, q);
    cout << "Public Key of B: " << yb << endl;

    // Calculate shared keys
    ka = modExp(yb, xa, q);
    kb = modExp(ya, xb, q);

    cout<<"ka: "<<ka<<" kb: "<<kb;

    if (ka == kb) {
        cout << "\nequal" << endl;
    } else {
        cout << "\nno" << endl;
    }

    return 0;
}
