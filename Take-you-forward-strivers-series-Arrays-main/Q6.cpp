#include <iostream>
using namespace std;

int main()
{

    int D, size = 5;
    int arr[size] = {1, 2, 3, 5, 8};

    cout << "Original array elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nEnter Places to be shifted:";
    cin >> D;

    D = D % size;

    int temp[size];

    for (int i = 0; i < size; i++)
    {
        temp[(i + D) % size] = arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = temp[i];
    }

    cout << "After left shift by " << D << " places" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
