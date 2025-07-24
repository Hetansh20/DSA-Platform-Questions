#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'migratoryBirds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int migratoryBirds(vector<int> arr) {
    int one = 0, two = 0, three = 0, four = 0, five = 0;
    for(size_t i = 0; i < arr.size(); i++) {
        if(arr[i] == 1) one++;
        else if(arr[i] == 2) two++;
        else if(arr[i] == 3) three++;
        else if(arr[i] == 4) four++;
        else if(arr[i] == 5) five++;
    }

    int highest_count = one;
    int type = 1;

    if(two > highest_count) { highest_count = two; type = 2; }
    else if(two == highest_count && type > 2) type = 2;

    if(three > highest_count) { highest_count = three; type = 3; }
    else if(three == highest_count && type > 3) type = 3;

    if(four > highest_count) { highest_count = four; type = 4; }
    else if(four == highest_count && type > 4) type = 4;

    if(five > highest_count) { highest_count = five; type = 5; }
    else if(five == highest_count && type > 5) type = 5;

    return type;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

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
