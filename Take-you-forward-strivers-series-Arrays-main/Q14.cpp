#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubarrayWithSumK(int arr[], int n, int k)
{
    unordered_map<int, int> prefixSumMap;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == k)
        {
            maxLen = i + 1;
        }

        if (prefixSumMap.find(sum) == prefixSumMap.end())
        {
            prefixSumMap[sum] = i;
        }

        if (prefixSumMap.find(sum - k) != prefixSumMap.end())
        {
            maxLen = max(maxLen, i - prefixSumMap[sum - k]);
        }
    }

    return maxLen;
}

int main()
{
    int arr[] = {1, -1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 1;
    int length = longestSubarrayWithSumK(arr, n, k);
    cout << "The length of the longest subarray which has the sum " << k << " is: " << length << endl;
    return 0;
}
