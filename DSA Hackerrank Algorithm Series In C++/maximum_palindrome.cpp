#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

const int MOD = 1000000007;
const int MAXN = 100005;

vector<array<int,26>> prefixFreq;
long long factArr[MAXN], invFactArr[MAXN];

long long modexp(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    factArr[0] = 1;
    for (int i = 1; i < MAXN; i++)
        factArr[i] = (factArr[i - 1] * i) % MOD;

    invFactArr[MAXN - 1] = modexp(factArr[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        invFactArr[i] = (invFactArr[i + 1] * (i + 1)) % MOD;
}

/*
 * initialize
 */
void initialize(string s) {
    precompute();

    int n = s.size();
    prefixFreq.assign(n + 1, {0});

    for (int i = 1; i <= n; i++) {
        prefixFreq[i] = prefixFreq[i - 1];
        prefixFreq[i][ s[i - 1] - 'a' ]++;
    }
}

/*
 * answerQuery
 */
int answerQuery(int l, int r) {
    long long halfCounts[26];
    long long totalPairs = 0;
    int oddCount = 0;

    for (int c = 0; c < 26; c++) {
        int cnt = prefixFreq[r][c] - prefixFreq[l - 1][c];
        if (cnt % 2 == 1) oddCount++;
        halfCounts[c] = cnt / 2;
        totalPairs += halfCounts[c];
    }

    long long ans = factArr[totalPairs];

    for (int c = 0; c < 26; c++)
        ans = (ans * invFactArr[ halfCounts[c] ]) % MOD;

    if (oddCount > 0) ans = (ans * oddCount) % MOD;

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    initialize(s);

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int l = stoi(first_multiple_input[0]);
        int r = stoi(first_multiple_input[1]);

        int result = answerQuery(l, r);

        fout << result << "\n";
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }

    tokens.push_back(str.substr(start));
    return tokens;
}
