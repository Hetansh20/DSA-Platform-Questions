#include <iostream>
#include <set>
using namespace std;

int main()
{
    int arr1[5] = {1, 3, 4, 5, 7};
    int arr2[4] = {2, 3, 5, 6};

    set<int> unionSet;

    // Insert elements of the first array into the set
    for (int i = 0; i < 5; i++)
    {
        unionSet.insert(arr1[i]);
    }

    // Insert elements of the second array into the set
    for (int i = 0; i < 4; i++)
    {
        unionSet.insert(arr2[i]);
    }

    // Print the union of the two arrays
    cout << "Union of the two arrays: ";
    for (auto it = unionSet.begin(); it != unionSet.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}
