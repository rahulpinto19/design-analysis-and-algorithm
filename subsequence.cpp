#include<stdio.h>
#include<iostream>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
void help(set<string>&ans,string str)
{
    int n=str.size();
    for(int i=0;i<pow(2,n);i++)
    {
        string k="";
        for(int j=0;j<n;j++)
        {
            if((i>>j)&1)
            k+=str[j];
        }
        ans.insert(k);
    }
}
int main()
{
    string str ="abc";
    set<string>ans;
    help(ans,str);
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
    for(auto x:ans)
    pq.push({x.size(),x});
    while(!pq.empty())
    {
        auto x=pq.top();
        cout<<x.second<<endl; pq.pop();
    }
}
