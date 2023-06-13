#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
    vector<pair<int, int>> ks;
    vector<pair<double, int>> pw;
    int p, w, size;
    cout << "enter the size" << endl;
    cin >> size;
    int i = 0;
    while (i < size)
    {
        cout << "enter the profit" << endl;
        cin >> p;
        cout << "enter the weight" << endl;
        cin >> w;
        if (p >= w)
        {
            ks.push_back(make_pair(p, w));
            pw.push_back(make_pair((double)ks[i].first / ks[i].second, i));
            i++;
        }
        else
        {
            cout << "input is not correct" << endl;
            cout << "please enter again here " << endl;
        }
    }

    sort(pw.begin(), pw.end(), greater<>());

    int k_sack, ans = 0;
    cout << "enter the size of the knapsack" << endl;
    cin >> k_sack;
    i = 0;
    double profit = 0.0;
    while (k_sack)
    {
        if (k_sack > ks[pw[i].second].second)
        {
            k_sack -= ks[pw[i].second].second;
            profit += ks[pw[i].second].first;
        }
        else
        {
            profit += (double)((ks[pw[i].second].first) * k_sack) / ks[pw[i].second].second;
            break;
        }

        i++;
    }
    cout << profit;
    return 0;
}
