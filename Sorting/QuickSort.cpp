#include<iostream>
#include<stdlib.h>
using namespace std;

int partition(int arr[],int l,int r)
{
    int pivot = arr[r];
    int i=l-1;
    for(int j=l;j<= r-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return (i+1);
}
void QuickSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int pivot = partition(arr,l,r); 
        QuickSort (arr,l,pivot-1);
        QuickSort(arr,pivot+1,r);
    }
}
int main()
{
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    int arr[n];
    for(auto &it :arr)
    {
        cin>>it;
    }
    cout<<"Quick Sort : \n";
    QuickSort(arr,0,n-1);
    for(auto &it : arr)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
