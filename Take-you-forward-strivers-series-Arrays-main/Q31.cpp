#include <iostream>
using namespace std;

void three_sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                sum = arr[i] + arr[j] + arr[k];
                if (sum == 0)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                }
            }
            sum = 0;
        }
    }
}

int main()
{
    int arr[] = {-1, 0, 1, 2, -1, -4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The triplets which has sum of 0 are: " << endl;
    three_sum(arr, n);
    return 0;
}