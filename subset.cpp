#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
class solution
{
    public:
    vector<vector<int>> help(vector<int>&nums,int i)
    {
        if(i>=nums.size())
        return {{}};
        vector<vector<int>>partial = help(nums,i+1);
        vector<vector<int>>ans;
        for(vector<int>x :partial)
        {
            ans.push_back(x);
        }
        for(vector<int>x:partial)
        {
            x.push_back(nums[i]);
            ans.push_back(x);
        }
        return ans;
    }
    vector<vector<int>>subset(vector<int> &nums)
    {
        vector<vector<int>>ans = help(nums,0);
        return ans;
    }
};
int main()
{
    int n;
    cout<<"Enter size of the array"<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cout<<"enter the val"<<endl;
        cin>>arr[i];
    }
    solution s;
    vector<vector<int>>ans = s.subset(arr);
    for(int i=0;i<ans.size();i++)
    {
        for(auto val : ans[i])
        {
            cout<<val<<" ";
        }
        cout<<endl;
    }
}
