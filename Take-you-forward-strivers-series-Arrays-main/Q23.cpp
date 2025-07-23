#include <iostream>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void leaders(int arr[], int size)
{
    int max_from_right = arr[size - 1];
    cout << max_from_right << " ";

    for (int i = size - 2; i >= 0; i--)
    {
        if (arr[i] > max_from_right)
        {
            max_from_right = arr[i];
            cout << max_from_right << " ";
        }
    }
    cout << endl;
}

int main()
{
    int arr[] = {10, 22, 12, 3, 0, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Original Array is:" << endl;
    display(arr, size);
    cout << "Leaders of the Array:" << endl;
    leaders(arr, size);
    return 0;
}
