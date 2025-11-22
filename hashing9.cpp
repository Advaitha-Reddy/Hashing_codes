#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count_maxi_sub(vector<int>&arr,int k){
    int n=arr.size();
    int count=0;
    int maxi=0;
    unordered_map<int,int>mpp;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            if(maxi<i+1){
                maxi=i+1;
                count=1;
            }
            else if(maxi==i+1){
                count++;
            }
        }
       if(mpp.find(sum-k)!=mpp.end()){
        int len=i-mpp[sum-k];
        if(len>maxi){
            maxi=len;
            count=1;
        }

        else if(len==maxi){
            count++;
        }
       }

       if(mpp.find(sum)==mpp.end()){
        mpp[sum]=i;
       }
}

return count;
}
int main(){

    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    vector<int>vec(n);
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int k;
    cout<<"Enter the value of k: "<<endl;
    cin>>k;
    int count=count_maxi_sub(vec,k);
    cout<<"The number of subarrays with maximum length of sum "<<k<<" is: "<<count;
    return 0;
}