#include <iostream>

#define max(a,b) a >= b ? a : b
#define min(a,b) a <= b ? a : b
using namespace std;

int caseNumber;
short **number_Array;
int loop;
int max_Sum[2][3];
int min_Sum[2][3];
void setup()
{
    cin >> caseNumber;
    
    number_Array = new short*[caseNumber];
    for(  loop = 0; loop < caseNumber; loop++)
    {
        number_Array[loop] = new short[3];
        cin >> number_Array[loop][0];
        cin >> number_Array[loop][1];
        cin >> number_Array[loop][2];
    }
    max_Sum[0][0] = number_Array[0][0];
    max_Sum[0][1] = number_Array[0][1];
    max_Sum[0][2] = number_Array[0][2];
    min_Sum[0][0] = number_Array[0][0];
    min_Sum[0][1] = number_Array[0][1];
    min_Sum[0][2] = number_Array[0][2];
    
}

void calculation()
{
    for( loop = 1; loop < caseNumber; loop++)
    {
        max_Sum[1][0] = max(max_Sum[0][0],max_Sum[0][1]);
        max_Sum[1][0] += number_Array[loop][0];
        max_Sum[1][1] = max(max_Sum[0][0],max_Sum[0][1]);
        max_Sum[1][1] = max(max_Sum[1][1],max_Sum[0][2]);
        max_Sum[1][1] += number_Array[loop][1];
        max_Sum[1][2] = max(max_Sum[0][1],max_Sum[0][2]);
        max_Sum[1][2] += number_Array[loop][2];
        max_Sum[0][0] = max_Sum[1][0];
        max_Sum[0][1] = max_Sum[1][1];
        max_Sum[0][2] = max_Sum[1][2];
        
        min_Sum[1][0] = min(min_Sum[0][0],min_Sum[0][1]);
        min_Sum[1][0] += number_Array[loop][0];
        min_Sum[1][1] = min(min_Sum[0][0],min_Sum[0][1]);
        min_Sum[1][1] = min(min_Sum[1][1],min_Sum[0][2]);
        min_Sum[1][1] += number_Array[loop][1];
        min_Sum[1][2] = min(min_Sum[0][1],min_Sum[0][2]);
        min_Sum[1][2] += number_Array[loop][2];
        min_Sum[0][0] = min_Sum[1][0];
        min_Sum[0][1] = min_Sum[1][1];
        min_Sum[0][2] = min_Sum[1][2];
    }
}
int main(void)
{
    setup();
    calculation();
    
    int max_Value = max(max_Sum[0][0],max_Sum[0][1]);
    max_Value = max(max_Value,max_Sum[0][2]);
    int min_Value = min(min_Sum[0][0],min_Sum[0][1]);
    min_Value = min(min_Value,min_Sum[0][2]);
    
    cout << max_Value << " " << min_Value << endl;
}