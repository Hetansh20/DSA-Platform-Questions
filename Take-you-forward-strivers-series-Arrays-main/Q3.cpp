#include <iostream>
using namespace std;
bool issorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    bool answer = issorted(arr, n);
    if (answer == false)
    {
        cout << "Array is not sorted";
    }
    else
    {
        cout << "Array is sorted";
    }
}