#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

void kaprekarNumbers(int p, int q) {
    bool found = false;
    for (int n = p; n <= q; ++n) {
        long long sq = 1LL * n * n;
        string s = to_string(sq);
        int d = to_string(n).length();

        // right part: last d digits
        string r_str = (d <= (int)s.length()) ? s.substr(s.length() - d) : s;
        // left part: the rest (could be empty -> 0)
        string l_str = (d < (int)s.length()) ? s.substr(0, s.length() - d) : "";

        long long r = r_str.empty() ? 0 : stoll(r_str);
        long long l = l_str.empty() ? 0 : stoll(l_str);

        if (l + r == n) {
            if (found) cout << " ";
            cout << n;
            found = true;
        }
    }
    if (!found) cout << "INVALID RANGE";
    cout << "\n";
}

int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
