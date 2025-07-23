#include<iostream>
using namespace std;

int main()
{
    int count = 0;
    int key = 30;
    int size = 8;
    int arr[size] = {10, 50, 30, 70, 80, 20, 90, 40};

    for (int i = 0; i < size; i++)
    {
        if (key != arr[i])
        {
            count++;
        }
        else
        {
            cout << "Element:" << key << " found at index: " << i << endl;
            break;
        }
    }

    return 0;
}