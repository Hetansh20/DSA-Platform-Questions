#include <iostream>
using namespace std;

int main()
{
    int arr[7] = {1, 1, 1, 0, 1, 1, 1};
    int max_consecutive_ones = 0;
    int current_count = 0;

    for (int i = 0; i < 7; i++)
    {
        if (arr[i] == 1)
        {
            current_count++;
            if (current_count > max_consecutive_ones)
            {
                max_consecutive_ones = current_count;
            }
        }
        else
        {
            current_count = 0;
        }
    }

    cout << "Maximum consecutive ones: " << max_consecutive_ones << endl;
    return 0;
}
