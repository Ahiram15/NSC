#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout << "Enter size of the msg: ";
    cin >> n;

    vector<vector<int>> msg(n, vector<int>(1));
    vector<vector<int>> key(n, vector<int>(n));
    vector<vector<int>> soln(n, vector<int>(1));

    cout << "Enter the msg: ";
    char ch;
    for (int i = 0; i < n; ++i) {
        cin >> ch;                // reads a non-space character
        msg[i][0] = tolower(ch)-'a';      // stores ASCII value
    }

    cout << "Enter keystring: ";

for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cin>>ch;
        key[i][j]=tolower(ch)-'a';
    }
}

    // Matrix multiplication
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int k = 0; k < n; k++) {
            sum += key[i][k] * msg[k][0];
        }
        soln[i][0] = (sum % 26 + 26) % 26; 
    }

    cout << "Encrypted text: ";
    for (int i = 0; i < n; i++) {
        cout << char(soln[i][0] + 'a');
    }

    return 0;
}
