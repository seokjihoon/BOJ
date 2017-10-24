#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    int a, b;
    
    cin >> a >> b;
    
    int **c = new int*[a];
    for(int i = 0; i<a;i++)
        c[i] = new int[b];
    for(int i = 0; i< a; i++)
    {
        for(int j = 0; j<b;j++)
        {
            cin >> c[i][j];
        }
    }
    
    int e;
    cin >> e;
    int aa, bb, cc, dd;
    int *f = new int[e];
    memset(f,0,e);
    for(int i = 0; i<e;i++)
    {
        cin >> aa >> bb >> cc >> dd;
        aa--;bb--;
        for(int j = aa; j<cc; j++)
        {
            for(int k = bb; k<dd;k++)
            {
                f[i] += c[j][k];
            }
        }
    }
    for(int i=0;i<e;i++) cout << f[i] << endl;
    return 0;
}

