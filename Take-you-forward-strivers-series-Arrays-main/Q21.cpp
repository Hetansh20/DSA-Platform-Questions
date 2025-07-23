#include <iostream>
using namespace std;

void display(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void alternating_array(int arr[], int size) {
    int positive[size];
    int negative[size];
    int temp[size];
    int posIndex = 0, negIndex = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positive[posIndex++] = arr[i];
        } else {
            negative[negIndex++] = arr[i];
        }
    }
    
    int i = 0, p = 0, n = 0;
    while (p < posIndex && n < negIndex) {
        temp[i++] = positive[p++];
        temp[i++] = negative[n++];
    }
    
    while (p < posIndex) {
        temp[i++] = positive[p++];
    }

    while (n < negIndex) {
        temp[i++] = negative[n++];
    }
    
    display(temp, size);
}

int main() {
    int arr[] = {1, 2, 3, -1, -5, -3};
    int size = sizeof(arr) / sizeof(arr[0]);
    alternating_array(arr, size);
    return 0;
}
