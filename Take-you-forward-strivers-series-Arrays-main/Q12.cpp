#include <iostream>
using namespace std;
int main()
{
    int arr[] = {6, 6, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = 0;

    // XOR all elements in the array
    for (int i = 0; i < n; i++)
    {
        result ^= arr[i];
    }

    cout << "The element that appears only once is: " << result << endl;
    return 0;
}
