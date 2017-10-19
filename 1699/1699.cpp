#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int a;
    cin >> a;
    int *dp = new int[a+1];
    int i,j;
    
    for(i=1;i<=a;i++)
    {
        dp[i] = i;
        for(j=1;j*j<=i;j++)
        {
            if(dp[i] > dp[i-j*j]+1)
                dp[i] = dp[i-j*j]+1;
        }
    }
    
    
    cout << dp[a] << endl;
    return 0;
}

