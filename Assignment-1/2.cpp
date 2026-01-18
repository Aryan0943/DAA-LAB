#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    mergeSort(arr1, 0, n1 - 1);
    printArray(arr1, n1);

    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    mergeSort(arr2, 0, n2 - 1);
    printArray(arr2, n2);

    return 0;
}
