#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int makingAnagrams(string s1, string s2) {
    int freq[26] = {0};

    // Increase for s1, decrease for s2
    for (char c : s1) freq[c - 'a']++;
    for (char c : s2) freq[c - 'a']--;

    // Total deletions = sum of absolute differences
    int deletions = 0;
    for (int i = 0; i < 26; i++) {
        deletions += abs(freq[i]);
    }

    return deletions;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
