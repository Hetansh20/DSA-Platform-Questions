#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

#include <algorithm> // Required for std::min

int pageCount(int n, int p) {
    int turns_from_front = p / 2;

    int turns_from_back;

    if (n % 2 == 1) { // If total pages 'n' is an odd number
        // Special handling for odd 'n': if 'p' is the last page 'n' or the page before 'n' (n-1),
        // it requires 0 turns from the back. Otherwise, it's (n - p) / 2.
        if (p == n || p == n - 1) {
            turns_from_back = 0;
        } else {
            turns_from_back = (n - p) / 2;
        }
    } else { // If total pages 'n' is an even number
        // For even 'n', the turns from the back is simply (n - p) / 2.
        turns_from_back = (n - p) / 2;
    }

    // Return the minimum of turns from front or back
    return min(turns_from_front, turns_from_back);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

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
