#include <iostream>
#include <algorithm>
using namespace std;

int largest_element(int arr[], int size)
{
    std::sort(arr, arr + size);
    return arr[size - 1];
}

int main()
{
    int arr[5] = {8, 0, 25, 12, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "The largest element of the array is " << largest_element(arr, size);
    return 0;
}