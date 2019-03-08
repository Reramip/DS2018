#include<iostream>

using namespace std;

void swap(int &x, int &y);
void SelectionSort(int *arr, int n);

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    SelectionSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}

void swap(int &x, int &y) {
    int tmp = y;
    y = x;
    x = tmp;
}

void SelectionSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}