#include <iostream> 
#include <bits/stdc++.h>
using namespace std;
int steps_to_convert(vector<int>&arr){
	int n=arr.size();
	map<int,int>mpp;
	for(int i=0;i<n;i++){
		mpp[arr[i]]++;
	}
	
	vector<pair<int,int>>p(mpp.begin(),mpp.end());
	int s=p.size();
	int result=0;
	for(int j=s-1;j>=0;j--){
		result+=p[j].second;
		p[j-1].second+=p[j].second;
		p[j].second=0;
	}
	
	return result;
}

int main(){
	int n;
	cin>>n;
	vector<int>vec(n);
	for(int i=0;i<n;i++){
		cin>>vec[i];
	}
	
	int steps=steps_to_convert(vec);
	cout<<"The minimum number of steps to make all the array elements equal is: "<<steps<<endl;
	return 0;
}