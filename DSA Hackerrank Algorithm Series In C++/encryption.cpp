#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    // remove spaces
    string t;
    for (char c : s) if (c != ' ') t.push_back(c);

    int L = t.size();
    if (L == 0) return "";

    int r = floor(sqrt(L));
    int c = ceil(sqrt(L));
    if (r * c < L) r++;

    string res;
    for (int col = 0; col < c; col++) {
        if (!res.empty()) {} // keep style minimal; spaces added below
        for (int row = 0; row < r; row++) {
            int idx = row * c + col;
            if (idx < L) res.push_back(t[idx]);
        }
        if (col != c - 1) res.push_back(' ');
    }
    return res;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
