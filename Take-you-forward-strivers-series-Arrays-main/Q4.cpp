#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 2, 1};
    int n, i, j, k;
    n = sizeof(arr) / sizeof(arr[0]);
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
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n;)
            {
                if (arr[i] == arr[j])
                {
                    for (k = j; k < n - 1; k++)
                    {
                        arr[k] = arr[k + 1];
                    }
                    n--;
                }
                else
                {
                    j++;
                }
            }
        }
        cout << "After removing duplicates" << endl;
        for (i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    return 0;
}