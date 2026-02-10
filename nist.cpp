#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long hash_func(const string &a) {
    long long res = 0;
    for (char c : a)
        res = (res * 31 + c) % 1000000007;
    return res;
}

long long modInverse(long long a, long long mod) {
    long long x = 1;
    while ((a * x) % mod != 1)
        x++;
    return x;
}

int main() {
    long long p, q, h, g, x, y, k;
    string msg, msg2;

    cout << "Enter p value : ";
    cin >> p;
    cout << "Enter q value as prime divisor of p-1 : ";
    cin >> q;
    cout << "Enter h value in range of 1 to p-1 : ";
    cin >> h;

    g = power(h, (p - 1) / q, p);
    cout << "The value of g is : " << g << endl;

    cout << "Enter user private key : ";
    cin >> x;
    y = power(g, x, p);

    cout << "Enter k value in range of 0 to q : ";
    cin >> k;

    long long r = power(g, k, p) % q;
    long long kInv = modInverse(k, q);

    cout << "Enter message : ";
    cin >> msg;
    long long h1 = hash_func(msg);

    long long s = (kInv * (h1 + x * r)) % q;
    cout << "The value of r and s is : " << r << " " << s << endl;

    if (r == 0 || s == 0) {
        cout << "Invalid Signature" << endl;
        return 0;
    }

    long long w = modInverse(s, q);

    cout << "Enter msg after transmission : ";
    cin >> msg2;
    long long h2 = hash_func(msg2);

    long long u1 = (h2 * w) % q;
    long long u2 = (r * w) % q;

    long long v = (power(g, u1, p) * power(y, u2, p) % p) % q;

    cout << u1 << " " << u2 << " " << y << " " << v << " " << r << endl;

    if (v == r)
        cout << "Valid Signature" << endl;
    else
        cout << "Not Valid Signature" << endl;

    return 0;
}
/*
Enter p value : 23
Enter q value as prime divisor of p-1 : 11
Enter h value in range of 1 to p-1 : 2
Enter user private key : 6
Enter k value in range of 0 to q : 7
Enter message : hello
Enter msg after transmission : hello
*/