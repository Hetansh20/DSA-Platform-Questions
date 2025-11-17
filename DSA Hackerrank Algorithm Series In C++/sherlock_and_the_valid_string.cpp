#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    unordered_map<char,int> freq;

    for(char ch : s) freq[ch]++;

    unordered_map<int,int> countFreq;
    for(auto &p : freq) {
        countFreq[p.second]++;
    }

    if(countFreq.size() == 1)
        return "YES";

    if(countFreq.size() > 2)
        return "NO";

    auto it = countFreq.begin();
    int f1 = it->first, c1 = it->second;
    it++;
    int f2 = it->first, c2 = it->second;

    int lowF = min(f1, f2);
    int highF = max(f1, f2);
    int lowC = (lowF == f1 ? c1 : c2);
    int highC = (highF == f1 ? c1 : c2);

    if(lowF == 1 && lowC == 1)
        return "YES";

    if(highF == lowF + 1 && highC == 1)
        return "YES";

    return "NO";
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
