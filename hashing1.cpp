#include <iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int>min_max(vector<int>arr){
    vector<int>ans(2);
    map<int,int>mpp;
    int n=arr.size();
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    int mini=INT_MAX;
    int maxi=INT_MIN;

    int min_ele;
    int max_ele;
    for(auto&it:mpp){
        if(it.second>maxi){
            maxi=it.second;
            max_ele=it.first;
        }
        if(it.second<mini){
            mini=it.second;
            min_ele=it.first;
        }
    }

     ans[0] = min_ele;
    ans[1] = max_ele;
    return ans;
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
    vector<int>ans=min_max(arr);
    cout<<"Minimum element is: "<<ans[0]<<endl;
    cout<<"Maximum element is: "<<ans[1]<<endl;
    return 0;

}