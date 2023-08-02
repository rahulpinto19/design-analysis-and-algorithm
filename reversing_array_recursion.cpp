#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void reverse(vector<int>&temp,int start,int end)
{
    if(start>=end)
    return ;
    reverse(temp,start+1,end-1);
    int t = temp[start];
    temp[start]=temp[end];
    temp[end]=t;
}
int main()
{
    vector<int>temp={1,2,3,4,5};
    cout<<"Before reversing"<<endl;
    for(auto x:temp)
    {
        cout<<x<<" ";
    }
    reverse(temp,0,4);
    cout<<"After reversing"<<endl;
    for(auto x:temp)
    {
        cout<<x<<" ";
    }
}
