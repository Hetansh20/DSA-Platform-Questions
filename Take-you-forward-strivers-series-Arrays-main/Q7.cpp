#include <iostream>
using namespace std;

int main()
{
    int count = 0, size = 7;
    int arr[size] = {1, 2, 0, 0, 0, 3, 6};

    cout << "Original Array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            arr[count++] = arr[i];
        }
    }
    while (count < 7)
    {
        arr[count++] = 0;
    }
    cout << "Output:" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
