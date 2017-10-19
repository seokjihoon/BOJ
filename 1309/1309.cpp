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
    int **b = new int*[2]();
    b[0] = new int[a]();
    b[1] = new int[a]();
    
    b[0][0] = 2;
    b[1][0] = 1;
    
    for(int i = 1; i<a; i++)
    {
        b[0][i] = (b[0][i-1] + b[1][i-1]*2)%9901;
        b[1][i] = (b[0][i-1] + b[1][i-1])%9901;
    }
    cout << (b[1][a-1] + b[0][a-1])%9901 << endl;
}