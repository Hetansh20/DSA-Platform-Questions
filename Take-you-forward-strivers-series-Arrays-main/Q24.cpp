#include <iostream>
#include <algorithm>
using namespace std;

int longestConsecutiveSubsequence(int arr[], int n) {
    // Sort the array
    sort(arr, arr + n);

    int longestStreak = 1;
    int currentStreak = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            continue;
        }

        if (arr[i] == arr[i - 1] + 1) {
            currentStreak++;
        } else {
            longestStreak =max(longestStreak, currentStreak);
            currentStreak = 1;
        }
    }

    longestStreak = max(longestStreak, currentStreak);

    return longestStreak;
}

int main() {
    int arr[] = {3, 8, 5, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Longest consecutive subsequence length: " << longestConsecutiveSubsequence(arr, n) << endl;
    return 0;
}
