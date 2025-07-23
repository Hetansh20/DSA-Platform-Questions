#include <iostream>
using namespace std;

void four_sum(int arr[], int n, int target)
{
    int sum = 0;
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            for (int k = j + 1; k < n - 1; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if (sum == target)
                    {
                        cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << arr[l] << endl;
                    }
                }
            }
            sum = 0;
        }
    }
}

int main()
{
    int arr[] = {1,0,-1,0,-2,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 0;
    cout << "The quadruplets which has sum " << target << " are: " << endl;
    four_sum(arr, n, target);
    return 0;
}