#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool help(vector<int> v, int pos, int sum, vector<vector<int>> &dp, vector<int> &ans, int &final)
{
    // cout<<sum<<endl;
    if (sum == 0)
    {
        return 1;
    }
    if (pos >= v.size() || sum < 0)
        return 0;
    if (dp[pos][sum] != -1)
        return dp[pos][sum];

    bool a = help(v, pos + 1, sum - v[pos], dp, ans, final);
    bool b = help(v, pos + 1, sum, dp, ans, final);

    dp[pos][sum] = a || b;

    return dp[pos][sum];
}
int main()
{
    int final = 0;
    vector<int> v = {0, 2, 4, 11, 13};
    int k = 11;
    vector<vector<int>> dp(5, vector<int>(k + 1, -1));
    vector<int> ans;

    cout << "done" << endl;

    cout << help(v, 0, k, dp, ans, final);
}
