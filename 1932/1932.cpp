#include <iostream>
#include <algorithm>
using namespace std;

int **area;
int **result;
int loop;
int innerLoop;
int input;

void setup()
{
    cin >> input;
    area = new int*[input];
    result = new int*[input];
    for(loop = 0; loop < input; loop++)
    {
        area[loop] = new int[loop+1];
        result[loop] = new int[loop+1];
        for(innerLoop = 0; innerLoop < loop+1; innerLoop++)
        {
            cin >> area[loop][innerLoop];
        }
    }
    
    result[0][0] = area[0][0];
    result[1][0] = area[0][0] + area[1][0];
    result[1][1] = area[0][0] + area[1][1];
    
}

int calculation()
{
    for(loop = 2; loop < input; loop++)
    {
        result[loop][0] = result[loop-1][0] + area[loop][0];
        result[loop][loop] = result[loop-1][loop-1] + area[loop][loop];
        for(innerLoop = 1; innerLoop < loop; innerLoop++)
            result[loop][innerLoop] = max(result[loop-1][innerLoop-1],result[loop-1][innerLoop]) + area[loop][innerLoop];
    }

    sort(result[input-1],result[input-1]+input);
    return result[input-1][input-1];
}
int main(void)
{
    int output;
    setup();
    output = calculation();
    cout << output << endl;
    return 0;
}