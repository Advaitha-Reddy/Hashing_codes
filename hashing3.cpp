#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count_pairs(vector<int>&arr,int k){
    unordered_map<int,int>mpp;
    int n=arr.size();
    int count=0;
    for(int i=0;i<n;i++){
        int target=k-arr[i];
        if(mpp.find(target)!=mpp.end()){
            count+=mpp[target];
        }
        mpp[arr[i]]++;
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<"Enter the value of k: "<<endl;
    int k;
    cin>>k;
    
    int count=count_pairs(arr,k);
    cout<<"Number of pairs with sum equal to "<<k<<"is:"<<count<<endl;

    return 0;
}