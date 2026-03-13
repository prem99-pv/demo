#include <iostream>
using namespace std;

void bubblesort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int arr[6] = {50, 45, 68, 2, 12, 28};
    int length = sizeof(arr) / sizeof(arr[0]);
    //Ascending Order
     bubblesort(arr, length);
     for (int i = 0; i < length; i++) {
         cout << arr[i] << " ";
    }
    cout << endl;
    //Descending Order
    bubblesort(arr, length);
    for (int i = length - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}