//              KADANES ALGORITHM
#include<iostream>
#include<climits>
#include<vector>

using namespace std;
int MaxSubArr(vector<int> v,int sz)
{
	int maxi=INT_MIN;     // set maximum = minimum 
	int sum=0;
  
	for(auto it : v)
	{
		sum+=it;
		maxi=max(maxi,sum);      //check weather sum is greater than maximum
    sum = sum < 0 ? 0 : sum;     // if sum < 0 set sum =0  

	}
	return maxi;
}
int main()
{
	vector<int> v;
	int sz;
	cout<<"Enter Size of Array : ";
	cin>>sz;
	cout<<"Enter Array Elements : ";
	for(int i=0;i<sz;i++)
	{
		int n;
		cin>>n;
		v.push_back(n);
	}
	cout<<"Sum of maximum Subarray : "<<MaxSubArr(v,sz)<<endl;
	return 0;
}
