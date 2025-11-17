#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s) {
    vector<int> freq(26, 0);
    for (char c : s) {
        if (c >= 'a' && c <= 'z') freq[c - 'a']++;
        else if (c >= 'A' && c <= 'Z') freq[c - 'A']++; 
    }

    int oddCount = 0;
    for (int f : freq) if (f % 2 != 0) ++oddCount;

    return (oddCount <= 1) ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
