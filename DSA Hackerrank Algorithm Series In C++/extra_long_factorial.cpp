#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void extraLongFactorials(int n) {

    vector<int> result(1, 1); // Initialize with 1

    

    for (int i = 2; i <= n; i++) {

        int carry = 0;

        for (int j = 0; j < (int)result.size(); j++) {

            int prod = result[j] * i + carry;

            result[j] = prod % 10;

            carry = prod / 10;

        }

        while (carry) {

            result.push_back(carry % 10);

            carry /= 10;

        }

    }

    

    // Print in reverse order since digits are stored reversed

    for (int i = (int)result.size() - 1; i >= 0; i--) {

        cout << result[i];

    }

    cout << "\n";

}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

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
