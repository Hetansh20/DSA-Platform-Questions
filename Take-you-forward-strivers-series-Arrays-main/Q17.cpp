#include <iostream>
using namespace std;

int highest_occured(int arr[], int size)
{
    int max_count = 0;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > max_count)
        {
            max_count = count;
        }
        count = 0;
    }
    return max_count;
}

int main()
{
    int arr[] = {1, 2, 1, 2, 2, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int highest = highest_occured(arr, size);
    if (highest > (size / 2))
    {
        cout << "The Element that occurs more than half the size of array is: " << highest;
    }
    else
    {
        cout << "The Element that occurs more than half the size of array is not present";
    }
}