#include<iostream>
#include<climits>
#include<vector>
using namespace std;
void Subset(vector<int> v,vector<int> output,vector<vector<int>> &ans,int i)
{
   if(i==v.size())
   {
      ans.push_back(output);
      return;
   }
   // exclude
   Subset(v,output,ans,i+1);
   //include
   output.push_back(v[i]);
   Subset(v,output,ans,i+1);
   return;	
}
int main()
{
	vector<int> v,output;
   vector<vector<int>> ans;
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
	cout<<"All possible Subset of Array : "<<endl;
   Subset(v,output,ans,0);
   for(auto itr : ans)
   {  cout<<" { ";
      for(auto it : itr)
      {
         cout<<it<<",";
      }
      cout<<"} ; ";
   }
	return 0;
}
