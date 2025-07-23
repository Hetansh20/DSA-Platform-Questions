#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    int first_e = arr[0];
    cout << "Original Array" << endl;
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " " << endl;
    }
    if (n < 2)
    {
        cout << "Array should have at least two elements" << endl;
    }
    else
    {
        for (i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = first_e;
        cout << "After Swapping" << endl;
        for (i = 0; i < n; i++)
        {
            cout << arr[i] << " " << endl;
        }
    }
}