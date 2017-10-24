#include <iostream>
#include <cmath>
#include <cstdio>

#define max(a,b) a >= b ? a : b
#define min(a,b) a <= b ? a : b
using namespace std;

int size_Array;
int *input_Data;
int maximum_Value;
int loop;
int innerLoop;
int sum = 0;

void setup()
{
    scanf("%d",&size_Array);
    
    input_Data = new int[size_Array];
    
    for( loop = 0; loop < size_Array; loop++)
    {
        scanf("%d",&input_Data[loop]);
    }
}

void calculation()
{
    maximum_Value = input_Data[0];
    for( loop = 0; loop < size_Array; loop++ )
    {
        if( input_Data[loop] > 0)
        {
            for ( innerLoop = loop; innerLoop < size_Array; innerLoop++)
            {
                sum += input_Data[innerLoop];
                maximum_Value = max(maximum_Value, sum);
            }
            sum = 0;
        }
        else
           maximum_Value = max(maximum_Value, input_Data[loop]);
    }
}


int main(void)
{
    setup();
    calculation();
    printf("%d\n",maximum_Value);
}