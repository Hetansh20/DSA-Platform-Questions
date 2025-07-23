#include <iostream>
#include <unordered_map>
using namespace std;

int maxLen(int A[], int n)
{
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}

int main()
{
    int arr[] = {9, -3, 3, -1, 6, -5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of the longest subarray with sum 0 is " << maxLen(arr, n) << endl;
    return 0;
}