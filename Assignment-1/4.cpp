#include <iostream>
using namespace std;

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int sum = 0;
    int left_sum = -1000000;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = -1000000;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int low, int high) {
    if (low == high)
        return arr[low];

    int mid = low + (high - low) / 2;

    int left = maxSubArraySum(arr, low, mid);
    int right = maxSubArraySum(arr, mid + 1, high);
    int cross = maxCrossingSum(arr, low, mid, high);

    if (left >= right && left >= cross)
        return left;
    else if (right >= left && right >= cross)
        return right;
    else
        return cross;
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubArraySum(arr, 0, n - 1);
    cout << maxSum << endl;

    return 0;
}
