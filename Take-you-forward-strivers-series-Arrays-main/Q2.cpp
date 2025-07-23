#include <iostream>
#include <climits>
using namespace std;

void findSecondSmallestAndLargest(int arr[], int n, int &secondSmallest, int &secondLargest)
{
    // Initialize the smallest and largest to their extreme limits
    int smallest = INT_MAX, largest = INT_MIN;

    // Traverse the array to find the smallest and largest elements
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    secondSmallest = INT_MAX;
    secondLargest = INT_MIN;

    // Traverse the array to find the second smallest and second largest elements
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > smallest && arr[i] < secondSmallest)
        {
            secondSmallest = arr[i];
        }
        if (arr[i] < largest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }
    }

    // Edge case handling: if second smallest or second largest is not found
    if (secondSmallest == INT_MAX)
    {
        secondSmallest = -1; // Indicates no second smallest element
    }
    if (secondLargest == INT_MIN)
    {
        secondLargest = -1; // Indicates no second largest element
    }
}

int main()
{
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int secondSmallest, secondLargest;

    findSecondSmallestAndLargest(arr, n, secondSmallest, secondLargest);

    if (secondSmallest != -1)
    {
        cout << "The second smallest element is " << secondSmallest << endl;
    }
    else
    {
        cout << "There is no second smallest element" << endl;
    }

    if (secondLargest != -1)
    {
        cout << "The second largest element is " << secondLargest << endl;
    }
    else
    {
        cout << "There is no second largest element" << endl;
    }

    return 0;
}
