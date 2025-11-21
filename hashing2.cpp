#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check_dist(vector<int>arr,int k){
    map<int,int>mpp;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(mpp.find(arr[i])!=mpp.end() && i-mpp[arr[i]]<=k){
            return true;
        }
        mpp[arr[i]]=i;
    }

    return false;
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
    
    bool ans=check_dist(arr,k);
    if(ans){
        cout<<"Equal elements are at distance less than"<<k<<endl;
    }
    else{
        cout<<"Equal elements are not at distance less than "<<k<<endl;
    }
    return 0;
}