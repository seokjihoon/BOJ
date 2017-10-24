#include <iostream>

#define max(a,b) a > b ? a : b;

using namespace std;

int a;
int value[2] = {1,2};
int loop;
int main(void)
{
    int N;
    
    cin >> N;
    
    for(int loop = 2; loop < N; loop++)
    {
        int temp = value[1];
        value[1] = (value[1] + value[0]) % 15746;
        value[0] = temp;
    }
    cout << value[1];
    return 0;
}