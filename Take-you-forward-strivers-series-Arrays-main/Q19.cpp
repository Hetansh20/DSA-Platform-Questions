#include <iostream>
#include <climits>
using namespace std;

void display(int arr[], int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sum_subarray(int arr[], int n)
{
    int maxi = INT_MIN;
    int start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum > maxi)
            {
                maxi = sum;
                start = i;
                end = j;
            }
        }
    }
    cout << "The largest sum is: " << maxi << endl;
    cout << "The subarray with the largest sum is: ";
    display(arr, start, end);
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The original array: ";
    display(arr, 0, n - 1);
    cout << "The largest sum of the subarray and the subarray itself: " << endl;
    sum_subarray(arr, n);
    return 0;
}
