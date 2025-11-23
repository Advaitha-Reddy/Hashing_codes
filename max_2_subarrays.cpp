#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max_2_subarrays(vector<int>& arr) {
    int n = arr.size();

    // left[i] = max subarray sum in arr[0..i]
    vector<int> left(n);
    int curr = arr[0];
    int best = arr[0];
    left[0] = best;

    for (int i = 1; i < n; i++) {
        curr = max(arr[i], curr + arr[i]); // normal Kadane
        best = max(best, curr);
        left[i] = best;
    }

    // right[i] = max subarray sum in arr[i..n-1]
    vector<int> right(n);
    curr = arr[n - 1];
    best = arr[n - 1];
    right[n - 1] = best;

    for (int i = n - 2; i >= 0; i--) {
        curr = max(arr[i], curr + arr[i]); // normal Kadane
        best = max(best, curr);
        right[i] = best;
    }

    int maxi = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
        maxi = max(maxi, left[i] + right[i + 1]);
    }

    return maxi;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: " << endl;
    cin >> n;

    vector<int> vec(n);
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int result = max_2_subarrays(vec);
    cout << "Maximum 2 subarrays in the array: " << result << endl;

    return 0;
}
