#include <iostream>
#include <algorithm> 
using namespace std;

int getLongestSubarray(int a[], int n, long k)
{
    int len = 0;
    for (int i = 0; i < n; i++)
    { // starting index
        for (int j = i; j < n; j++)
        {
            long long s = 0;
            for (int K = i; K <= j; K++)
            {
                s += a[K];
            }

            if (s == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

int main()
{
    int a[] = {2, 3, 5, 1, 9};
    int n = sizeof(a) / sizeof(a[0]); // size of the array
    long k = 10;
    int len = getLongestSubarray(a, n, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
