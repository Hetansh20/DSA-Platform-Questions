#include <iostream>
using namespace std;

void two_sum(int arr[], int n, int k)
{
    int sum;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            sum = arr[i] + arr[j];
            if (sum == k)
            {
                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }
}

int main()
{
    int arr[] = {2, 6, 5, 8, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 14;
    cout << "The two elements from the array which have a sum of " << k << " are: " << endl;
    two_sum(arr, n, k);
    return 0;
}