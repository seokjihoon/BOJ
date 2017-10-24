#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int *b = new int[a]();
    
    for(int i = 0; i<a; i++)
        cin >> b[i];
    int *dp = new int[a]();
    memset(dp,0,sizeof(int)*a);
    for(int i = 0; i<a; i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(b[i]>b[j]) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    int maxR = 0;
    for(int i = 0;i<a;i++) maxR = max(maxR, dp[i]);
    cout << maxR+1 << endl;
}