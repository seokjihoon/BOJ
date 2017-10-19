#include <iostream>
#include <algorithm>

using namespace std;


int house_Num;
int loop, innerLoop, ininerLoop;
int minValue = 1000000;
int minColor;
int midValue;
int sortPrice[3];
int **house_RGB_price;
int **final_cost;

void setup()
{
    cin >> house_Num;
    
    house_RGB_price = new int*[house_Num];
    
    for( loop = 0; loop < house_Num; loop++)
    {
        house_RGB_price[loop] = new int[3];
        for(innerLoop = 0; innerLoop < 3; innerLoop++)
            cin >> house_RGB_price[loop][innerLoop];
    }
    
    final_cost = new int*[house_Num];
    for( loop = 0; loop < house_Num; loop++)
        final_cost[loop] = new int [3];
    
    for( loop = 0; loop < 3; loop++)
        final_cost[0][loop] = house_RGB_price[0][loop];
    
}
int calculation()
{
    for( loop = 1; loop < house_Num; loop++)
    {
        for( ininerLoop = 0; ininerLoop < 3; ininerLoop++)
            if(minValue > final_cost[loop-1][ininerLoop])
            {
                minValue = final_cost[loop-1][ininerLoop];
                minColor = ininerLoop;
                if(final_cost[loop-1][(ininerLoop+1)%3] > final_cost[loop-1][(ininerLoop+2)%3])
                    midValue = final_cost[loop-1][(ininerLoop+2)%3];
                else
                    midValue = final_cost[loop-1][(ininerLoop+1)%3];
            }
        for( innerLoop = 0; innerLoop < 3; innerLoop++)
        {
            if(minColor != innerLoop)
                final_cost[loop][innerLoop] = minValue + house_RGB_price[loop][innerLoop];
            else
                final_cost[loop][innerLoop] = midValue + house_RGB_price[loop][innerLoop];
        }
        minValue = 1000000;
    }
    sort(final_cost[house_Num-1],final_cost[house_Num-1]+3);
    return final_cost[house_Num-1][0];
}

int main()
{
    int output;
    setup();
    output = calculation();
    
    cout << output << endl;
    return 0;
    
}