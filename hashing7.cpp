#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int cnt_sub(vector<int>arr,int k){
    int n=arr.size();
    int count=0;
    int sum=0;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k) count++;

        else if(mpp.find(sum-k)!=mpp.end()){
            count+=mpp[sum-k];
        }

        mpp[sum]++;
    }
    return count;
}
int main(){

    int n;
    cout<<"Enter the number of elements : "<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter the value of k: "<<endl;
    cin>>k;

    int count=cnt_sub(arr,k);
    cout<<count<<endl;
    return 0;

}