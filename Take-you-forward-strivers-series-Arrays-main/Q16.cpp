#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sorting(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    display(arr, n);
}

int main()
{
    int arr[] = {0, 1, 2, 0, 2, 1, 1, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array" << endl;
    display(arr, n);
    cout << "Sorted Array" << endl;
    sorting(arr, n);
    return 0;
}