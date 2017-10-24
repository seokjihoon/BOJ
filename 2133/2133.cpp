#include <iostream>
#include <memory.h>
using namespace std;
int main() {
    int a;
    cin >> a;
    int i,j;
    int *b = new int[a+1];
    memset(b,0,a*sizeof(int));
    
    b[0] = 1;
    for(i = 2; i<=a; i+=2)
    {
        b[i] = 3*b[i-2];
        for(j = i - 4; j>=0 ;j-=2)
            b[i] += 2*b[j];
    }
    cout << b[a]<< endl;

    return 0;
}