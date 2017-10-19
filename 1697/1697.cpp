#include <stdio.h>
#include <iostream>
#include <queue>

struct que
{
    int value;
    int layer;
};

using namespace std;
queue <que> my_queue;
que que_val;
bool map[100001];
int temp;
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    que_val.value = a;
    que_val.layer = 0;
    
    my_queue.push(que_val);
    map[que_val.value] = true;
    while (1)
    {
        que_val = my_queue.front();
        if(que_val.value == b) break;
        que_val.layer++;
        
        temp = que_val.value;
        
        if(0 <= temp+1 && temp+1 <= 100000 && !map[temp+1])
        {
            que_val.value = temp + 1;
            map[temp+1] = true;
            my_queue.push(que_val);
        }
        if(0 <= temp-1 && temp-1 <= 100000 && !map[temp-1])
        {
            que_val.value = temp - 1;
            map[temp-1] = true;
            my_queue.push(que_val);
        }
        if(0 <= temp*2 && temp*2 <= 100000 && !map[temp*2])
        {
            que_val.value = temp * 2;
            map[temp*2] = true;
            my_queue.push(que_val);
        }
        my_queue.pop();
        
    }
    printf("%d\n",que_val.layer);
    return 0;
}