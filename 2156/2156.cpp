#include <iostream>

#define max(a,b) a > b ? a : b;

int stair;
int *stair_Num;
long long *result;
int loop;
int con;
using namespace std;

int main(void)
{
    cin >> stair;
    
    stair_Num = new int[stair];
    result = new long long[stair];
    for(loop = 0; loop < stair; loop++)
        cin >> stair_Num[loop];
    
    result[0] = stair_Num[0];
    result[1] = result[0] + stair_Num[1];
    result[2] = max(stair_Num[0],stair_Num[1]);
    result[2] += stair_Num[2];
    result[2] = max(result[2], result[1]);
    for(loop = 3; loop < stair; loop++)
    {
        result[loop] = max(result[loop-3] + stair_Num[loop-1],result[loop-2]);
        result[loop] += stair_Num[loop];
        result[loop] = max(result[loop], result[loop-1]);
    }
    
    cout << result[stair-1];
    return 0;
}