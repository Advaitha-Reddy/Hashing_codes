#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> calc_prefix(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = max(prefix[i-1] + arr[i], arr[i]);
    }
    return prefix;
}

vector<int> calc_suffix(vector<int>& arr) {
    int n = arr.size();
    vector<int> suffix(n);
    suffix[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--) {
        suffix[i] = max(suffix[i+1] + arr[i], arr[i]);
    }
    return suffix;
}

int max_2_subarrays(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefixMax = calc_prefix(arr);
    vector<int> suffixMax = calc_suffix(arr);

    vector<int> maxPrefix(n), maxSuffix(n);
    maxPrefix[0] = prefixMax[0];
    for (int i = 1; i < n; i++) maxPrefix[i] = max(maxPrefix[i-1], prefixMax[i]);

    maxSuffix[n-1] = suffixMax[n-1];
    for (int i = n-2; i >= 0; i--) maxSuffix[i] = max(maxSuffix[i+1], suffixMax[i]);

    int result = INT_MIN;
    for (int i = 0; i < n-1; i++) result = max(result, maxPrefix[i] + maxSuffix[i+1]);

    return result;
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