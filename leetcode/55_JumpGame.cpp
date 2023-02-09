#include<iostream>
#include<limits.h>
#include<math.h>
using namespace std;
int canJump(int arr[],int n)
{
        int max_jump=0;
        int current=0;
        for(int i =0;i<n-1;i++)
        {
            max_jump = max(max_jump,arr[i]+i);
            if(current == i)
            {
                current = max_jump;
            }
            if(current<i)
            {
                return false;
            }
        }
        if(max_jump >= (n-1))
            return true;
        else
            return false;
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
    if(canJump(arr,n))
    {
        cout<<"Can Jump";
    }
    else
    {
        cout<<"Cannot Jump";
    }
}
