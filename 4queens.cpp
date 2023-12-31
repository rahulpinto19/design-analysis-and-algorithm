#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int set(int,int);
int count=0;

vector<vector<char>>ans(4,vector<char>(4,'N'));
vector<vector<bool>>bl(4,vector<bool>(4,1));
void clear(vector<vector<char>> &ans)
{
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    {
        ans[i][j]='N';
    }
}
void print(vector<vector<char>> &ans)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(ans[i][j]=='q')
            {bl[i][j]=0;}
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
void row(int x,int y,vector<vector<char>> &ans)
{
    for(int i=0;i<4;i++)
    {
            ans[x][i]='x';
            ans[i][y]='x';
    }
}
void diag(int x,int y,vector<vector<char>> &ans)
{
    int pos[4][2]={{-1,-1},{-1,1},{1,-1},{1,1}};
    int k=0;
    int i=x,j=y;
    while(k<4)
    {
        if(i>=0 && i<4 && j>=0 && j<4)
        {
            if(ans[i][j]!='q')
            ans[i][j]='x';
            i+=pos[k][0];
            j+=pos[k][1];
        }
        else
        {
            k++;
            i=x;
            j=y;
        }
    }
}
bool queen(int x,int y)
{
    return true;
    for(int i=0;i<4;i++)
    {
            if(ans[x][i]=='q'||ans[i][y]=='q')
            return false;
    }
    int pos[4][2]={{-1,-1},{-1,1},{1,-1},{1,1}};
    int k=0;
    int i=x,j=y;
    while(k<4)
    {
        if(i>=0 && i<4 && j>=0 && j<4)
        {
            if(ans[i][j]=='q')
            {return false;}
            i+=pos[k][0];
            j+=pos[k][1];
        }
        else
        {
            k++;
            i=x;
            j=y;
        }
    }
    return true;
}
int check(vector<vector<char>> & ans)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(ans[i][j]=='0')
            set(i,j);
        }
    }
    return 0;
}
int set(int a,int b)
{
    row(a,b,ans);
    diag(a,b,ans);
    ans[a][b]='q';
    int count=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(ans[i][j]=='N' and queen(i,j))
            {
                count++;
                row(i,j,ans);
                diag(i,j,ans);
                ans[i][j]='q';
            }
        }
    }
       // print(ans);
        if(count==3)
        {
            cout<<"sucess"<<endl;
            print(ans);
            printf("\n\n\n");
            return 1;
        }
        else
        {
            clear(ans);
            count=0;
        }
        return 0;
}
int main()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(bl[i][j])
            set(i,j);
        }
    }
}
