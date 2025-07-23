#include <iostream>
using namespace std;

int getLongestSubarray(int a[], int n, long k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    { 
        for (int j = i; j < n; j++)
        {
            long long s = 0;
            for (int K = i; K <= j; K++)
            {
                s += a[K];
            }

            if (s == k)
            {
                count ++;
            }
        }
    }
    return count;
}

int main()
{
    int a[] = {1,2,1,2,1};
    int n = sizeof(a) / sizeof(a[0]);
    long k = 3;
    int count = getLongestSubarray(a, n, k);
    cout << "Total number of subarrays with given sum is : " << count << "\n";
    return 0;
}
