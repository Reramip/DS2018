#include<iostream>

using namespace std;

void InsertSort(int *arr, int n);

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    InsertSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}

void InsertSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1; 
        int tmp = arr[i];
        for (; j >= 0 && arr[j] > tmp; j--) {
            arr[j + 1] = arr[j];
        }
        j++;
        arr[j] = tmp;
    }
}