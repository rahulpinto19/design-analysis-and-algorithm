#include<stdio.h>
#include<iostream>
using namespace std;
void merge(int *arr,int start,int end)
{
    int mid = start + (end-start)/2;

    int firstlen = mid-start+1;
    int secondlen = end-mid;

    int first[firstlen];  int second[secondlen];

    int mainindex=start;

    for(int i=0;i<firstlen;i++)
    first[i]=arr[mainindex++];

    mainindex=mid+1;

    for(int i=0;i<secondlen;i++)
    second[i]=arr[mainindex++];

    int i=0;  int j=0;

    mainindex = start;
    while(i<firstlen and j<secondlen)
    {
        if(first[i]<second[j])
        arr[mainindex++]=first[i++];

        else
        arr[mainindex++]=second[j++];
    }

    while(i<firstlen)
    arr[mainindex++]=first[i++];

    while(j<secondlen)
    arr[mainindex++]=second[j++];
}
void mergesort(int *arr,int start,int end)
{
    if(start>=end)
    return ;

    int mid= start+ (end-start)/2;

    mergesort(arr,0,mid);

    mergesort(arr,mid+1,end);

    merge(arr,start,end);
}
int main()
{
    int arr[5]={5,2,5,1,6};
    mergesort(arr,0,5);
    for(int x:arr)
    cout<<x<<" ";
}
