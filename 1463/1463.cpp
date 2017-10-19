#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int get_Input;
int *value;
int loop, innerLoop;
int modData[3];

void setup()
{
    cin >> get_Input;
    
    value = new int[get_Input+1];
    value[1] = 0;
    value[2] = value[3] = 1;
}

int minimum(int *modData)
{
    
    if((value[modData[0]] == value[modData[1]]) && (value[modData[1]] == value[modData[2]]))
        return value[modData[0]];
    
    else if(value[modData[0]] == value[modData[1]])
    {
        if(value[modData[1]] < value[modData[2]])
            return value[modData[0]];
        else
            return value[modData[2]];
        
    }
    
    else if(value[modData[1]] == value[modData[2]])
    {
        if(value[modData[1]] < value[modData[0]])
            return value[modData[1]];
        else
            return value[modData[0]];
    }
    else if(value[modData[2]] == value[modData[0]])
    {
        if(value[modData[0]] < value[modData[1]])
            return value[modData[0]];
        else
            return value[modData[1]];
    }
    else if((value[modData[0]] > value[modData[1]]) && (value[modData[0]] > value[modData[2]]))
    {
        if(value[modData[1]] > value[modData[2]])
            return value[modData[2]];
        else
            return value[modData[1]];
    }
    else if((value[modData[1]] > value[modData[0]]) && (value[modData[1]] > value[modData[2]]))
    {
        if(value[modData[0]] > value[modData[2]])
            return value[modData[2]];
        else
            return value[modData[0]];
    }
    else if((value[modData[2]] > value[modData[0]]) && (value[modData[2]] > value[modData[1]]))
        if(value[modData[0]] > value[modData[1]])
            return value[modData[1]];
        else
            return value[modData[0]];
        else return 0;
}
int calculation()
{
    for(loop = 4; loop < get_Input+1; loop++)
    {
        value[loop] = loop;
        if((loop)%3 == 0) modData[0] = (loop)/3;
        else modData[0] = loop;
        if((loop)%2 == 0) modData[1] = (loop)/2;
        else modData[1] = loop;
        modData[2] = loop-1;
        value[loop] = minimum(modData) + 1;
    }
    return value[get_Input];
}

int main()
{
    int output;
    setup();
    output = calculation();
    
    cout << output << endl;
    return 0;
    
}