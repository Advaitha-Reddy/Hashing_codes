#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count_pairs(vector<int>&arr,int k){
    int n=arr.size();
    int count=0;
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        int target=k+arr[i];
        int target2=arr[i]-k;
        if(mpp.find(target)!=mpp.end()){
            count+=mpp[target];
        }
        if(k!=0 && mpp.find(target2)!=mpp.end()){
            count+=mpp[target2];
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
    cout<<"Number of pairs with difference equal to "<<k<<" is:"<<count<<endl;

    return 0;
}