#include<iostream>
#include<limits.h>
#include<math.h>
using namespace std;
int getMinJumps(int arr[],int n)
{
	int jumps = 0, curr_End = 0, curr_Farthest = 0;
	for (int i = 0; i < n - 1; i++) {
		curr_Farthest = max(curr_Farthest, i + arr[i]);
		if (i == curr_End) {
			jumps++;
			curr_End = curr_Farthest;
		}
	}
	return jumps;
}
int main()
{
    int n;
    cout<<"Enter Array size : ";
    cin>>n;
    cout<<"Enter Array elements : ";
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Minimum jumps needed : "<<getMinJumps(arr,n);
}
