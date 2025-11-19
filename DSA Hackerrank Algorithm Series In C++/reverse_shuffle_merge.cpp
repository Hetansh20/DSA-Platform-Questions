#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'reverseShuffleMerge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string reverseShuffleMerge(string s) {
    int n = s.size();
    vector<int> total(26, 0);
    for (char ch : s) total[ch - 'a']++;

    vector<int> need(26, 0);
    for (int i = 0; i < 26; ++i) need[i] = total[i] / 2;

    vector<int> used(26, 0);  
    vector<int> remain = total; 

    string result; result.reserve(n/2);
    for (int i = n - 1; i >= 0; --i) {
        int c = s[i] - 'a';
        remain[c]--;              
        if (used[c] == need[c]) continue; 
        while (!result.empty()) {
            int last = result.back() - 'a';
            if (last <= c) break;
            if (used[last] + remain[last] > need[last]) {
                used[last]--;
                result.pop_back();
            } else {
                break;
            }
        }
        
        result.push_back(char('a' + c));
        used[c]++;
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
