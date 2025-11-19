#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maximumPeople' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER_ARRAY p
 *  2. LONG_INTEGER_ARRAY x
 *  3. LONG_INTEGER_ARRAY y
 *  4. LONG_INTEGER_ARRAY r
 */

long maximumPeople(vector<long> p, vector<long> x, vector<long> y, vector<long> r) {
    int n = p.size();   // towns
    int m = y.size();   // clouds

    vector<pair<long long,long long>> towns;
    towns.reserve(n);
    for (int i = 0; i < n; ++i) towns.push_back({x[i], p[i]});
    sort(towns.begin(), towns.end());

    vector<long long> loc(n), pop(n);
    for (int i = 0; i < n; ++i) {
        loc[i] = towns[i].first;
        pop[i] = towns[i].second;
    }

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + pop[i];

    auto sumRange = [&](int L, int R) -> long long {
        if (L > R) return 0LL;
        return pref[R + 1] - pref[L];
    };

    vector<pair<int,int>> cloudRange(m);
    for (int i = 0; i < m; ++i) {
        long long left = y[i] - r[i];
        long long right = y[i] + r[i];
        int L = int(lower_bound(loc.begin(), loc.end(), left) - loc.begin());
        int R = int(upper_bound(loc.begin(), loc.end(), right) - loc.begin()) - 1;
        cloudRange[i] = {L, R};
    }

    vector<int> diff(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int L = cloudRange[i].first;
        int R = cloudRange[i].second;
        if (L <= R) {
            diff[L] += 1;
            diff[R + 1] -= 1;
        }
    }
    vector<int> coverCount(n, 0);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += diff[i];
        coverCount[i] = cur;
    }

    long long alwaysSunny = 0;
    for (int i = 0; i < n; ++i) if (coverCount[i] == 0) alwaysSunny += pop[i];

    vector<long long> uniquePop(n, 0);
    for (int i = 0; i < n; ++i) if (coverCount[i] == 1) uniquePop[i] = pop[i];

    vector<long long> prefUnique(n + 1, 0);
    for (int i = 0; i < n; ++i) prefUnique[i + 1] = prefUnique[i] + uniquePop[i];

    auto uniqueSumRange = [&](int L, int R) -> long long {
        if (L > R) return 0LL;
        return prefUnique[R + 1] - prefUnique[L];
    };

    long long bestGain = 0;
    for (int i = 0; i < m; ++i) {
        int L = cloudRange[i].first;
        int R = cloudRange[i].second;
        if (L <= R) {
            long long gain = uniqueSumRange(L, R);
            if (gain > bestGain) bestGain = gain;
        }
    }

    long long ans = alwaysSunny + bestGain;
    return (long)ans;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split(rtrim(p_temp_temp));

    vector<long> p(n);

    for (int i = 0; i < n; i++) {
        long p_item = stol(p_temp[i]);

        p[i] = p_item;
    }

    string x_temp_temp;
    getline(cin, x_temp_temp);

    vector<string> x_temp = split(rtrim(x_temp_temp));

    vector<long> x(n);

    for (int i = 0; i < n; i++) {
        long x_item = stol(x_temp[i]);

        x[i] = x_item;
    }

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string y_temp_temp;
    getline(cin, y_temp_temp);

    vector<string> y_temp = split(rtrim(y_temp_temp));

    vector<long> y(m);

    for (int i = 0; i < m; i++) {
        long y_item = stol(y_temp[i]);

        y[i] = y_item;
    }

    string r_temp_temp;
    getline(cin, r_temp_temp);

    vector<string> r_temp = split(rtrim(r_temp_temp));

    vector<long> r(m);

    for (int i = 0; i < m; i++) {
        long r_item = stol(r_temp[i]);

        r[i] = r_item;
    }

    long result = maximumPeople(p, x, y, r);

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
