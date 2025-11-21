#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int prefix_sum(vector<int>&arr,int l,int r){
    int n=arr.size();
    vector<int>prefix(n);
    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];
    }

    int sum_r=0;
    if(l==0) sum_r=prefix[r];
    else sum_r=prefix[r]-prefix[l-1];
    return sum_r;
}
int main(){
    int l,r;
    cout<<"Enter the lower limit: "<<endl;
    cin>>l;
    cout<<"Enter the upper limit: "<<endl;
    cin>>r;

    vector<int>arr(r+1);
    for(int i=0;i<=r;i++){
        arr[i]=i;
    }
    
    int sum_req=prefix_sum(arr,l,r);
    cout<<"Sum required: "<<sum_req<<endl;
    return 0;
}