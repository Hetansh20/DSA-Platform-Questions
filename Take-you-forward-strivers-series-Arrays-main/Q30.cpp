#include <iostream>
#include <unordered_map>
using namespace std;

void count_occurrence(int arr[], int n)
{
    unordered_map<int, int> frequency_map;

    for (int i = 0; i < n; i++)
    {
        frequency_map[arr[i]]++;
    }

    for (auto &element : frequency_map)
    {
        if (element.second > n / 3)
        {
            cout << element.first << " ";
        }
    }
}

void main()
{
    int arr[] = {1, 2, 3, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The element(s) that occur more than n/3 times: " << endl;
    count_occurrence(arr, n);
}
