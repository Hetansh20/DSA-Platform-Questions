#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    // Handle the special transition year of 1918 in Russia
    if (year == 1918) {
        return "26.09.1918";
    }

    // Determine if the year is a leap year based on the calendar system
    bool isLeap = false;
    if (year < 1918) {
        // In the Julian calendar, a leap year is any year divisible by 4.
        isLeap = (year % 4 == 0);
    } else {
        // In the Gregorian calendar, a leap year is divisible by 400,
        // or divisible by 4 but not by 100.
        isLeap = ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
    }

    // Construct and return the date string.
    // The 256th day is September 12th in a leap year and September 13th otherwise.
    if (isLeap) {
        return "12.09." + to_string(year);
    } else {
        return "13.09." + to_string(year);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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
