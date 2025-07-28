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

#include <algorithm> // Required for std::min

int pageCount(int n, int p) {
    // Calculate turns from the front (page 1).
    // Each turn reveals 2 pages (e.g., page 2 and 3 after 1 turn).
    int turns_from_front = p / 2;

    // Calculate turns from the back (page n).
    int turns_from_back = (n / 2) - (p / 2);
    
    // Return the minimum of turns from front or back.
    // The student will choose the path that requires fewer turns.
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
