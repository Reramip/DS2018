#include<iostream>
using namespace std;

inline void swap(int& x, int& y);
inline int maxPos(int x, int y, int z);
int HalfSearch(int arr[], int n, int x);
void InsertSort(int arr[], int n);
void SelectSort(int arr[], int n);
void ShellSort(int arr[], int* d, int n, int dn);
void BubbleSort(int arr[], int n);
void MergeSort(int arr[], int l,int r);
void Merge(int arr[], int l1, int r1, int l2, int r2);
int QuickSortPos(int arr[], int l,int r);
void QuickSort(int arr[], int l, int r);

int main() {
    int arr[12] = { 23,15,12,35,46,19,20,14,8,74,86,25 };
    QuickSort(arr, 0, 11);
    for (int i = 0; i < 12; i++) cout << arr[i] << ' ';

    return 0;
}

inline void swap(int& x, int &y) {
    int tmp = y;
    y = x;
    x = tmp;
}

inline int maxPos(int arr[], int x, int y, int z) {
    if (arr[x] > arr[y]) {
        if (arr[x] > arr[z]) return x;
        return z;
    }
    else {
        if (arr[y] > arr[z]) return y;
        return z;
    }
}

int HalfSearch(int arr[], int n, int x) {
    int low = 0, high = n-1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x > arr[mid]) {
            low = mid + 1;
        }
        else if (x < arr[mid]) {
            high = mid - 1;
        }
        else return mid;
    }
    return low;
}

void InsertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int tmp = arr[i];
        int j = i;
        for (;j>0&& arr[j-1] > tmp; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = tmp;
    }
}

void SelectSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minPos = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minPos]) {
                minPos = j;
            }
        }
        swap(arr[i], arr[minPos]);
    }
}

void ShellSort(int arr[], int* d, int n, int dn) {
    for (int i = 0; i < dn; i++) {
        int dk = d[i];
        for (int j = 0; j < dk; j++) {
            for (int k = 0; j + k*dk < n; k++) {
                int l = j + k*dk; 
                int tmp = arr[l];
                for (; l >= dk&&arr[l - dk]>tmp; l -= dk) {
                    arr[l] = arr[l - dk];
                }
                arr[l] = tmp;
            }
        }
    }
}

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j + 1] > arr[j]) {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
}

void MergeSort(int arr[], int l, int r) {
    if (l==r) return;
    int mid = (l + r) / 2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid+1, r);
    Merge(arr, l, mid, mid+1, r);
}

void Merge(int arr[], int l1, int r1, int l2, int r2) {
    int i = l1, j = l2, cnt = 0;
    int* tmp = new int[r2 - l1 + 1];
    while (i <= r1&&j<=r2) {
        if (arr[i] <= arr[j]) {
            tmp[cnt] = arr[i];
            cnt++;
            i++;
        }
        else {
            tmp[cnt] = arr[j];
            cnt++;
            j++;
        }
    }
    while (i <= r1) {
        tmp[cnt] = arr[i];
        cnt++;
        i++;
    }
    while (j <= r2) {
        tmp[cnt] = arr[j];
        cnt++;
        j++;
    }
    for (int k = 0; k < r2-l1+1; k++) {
        arr[l1 + k] = tmp[k];
    }
    delete[] tmp;
}

int QuickSortPos(int arr[], int l, int r) {
    int k = maxPos(arr, l, r, (l + r) / 2);
    int i = l, j = r;
    while (i < j) {
        while (arr[j] > arr[k]) {
            j--;
        }
        if (arr[j] < arr[k]) {
            swap(arr[j], arr[k]);
            k = j;
            j--;
        }
        while (arr[i] < arr[k]) {
            i++;
        }
        if (arr[i] > arr[k]) {
            swap(arr[i], arr[k]);
            k = i;
            i++;
        }
    }
    return k;
}

void QuickSort(int arr[], int l, int r) {
    if (l < r) {
        int k = QuickSortPos(arr, l, r);
        QuickSort(arr, l, k - 1);
        QuickSort(arr, k + 1, r);
    }
}
