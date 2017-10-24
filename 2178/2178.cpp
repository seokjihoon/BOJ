#include <stdio.h>
#include <iostream>
#include <queue>


using namespace std;

struct que
{
    int x;
    int y;
    int visit;
};
queue <que> my_queue;
que str_que;
que temp_str_que;
int map[100][100];
int visit_arr[100][100];
int moveTo[4][2] = { {0,-1}, {0,1}, {1,0}, {-1,0}};
int temp;
int main()
{
    int a, b;
    int i, j;
    int tempX, tempY, tempVisit;
    scanf("%d %d", &a, &b);
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            scanf("%1d",&map[i][j]);
            visit_arr[i][j] = a*b;
        }
    }

    str_que.x = 0;
    str_que.y = 0;
    str_que.visit = 1;
    visit_arr[0][0] = 1;
    my_queue.push(str_que);
    
    while(!my_queue.empty())
    {
        str_que = my_queue.front();
        
        
        for(i=0;i<4;i++)
        {
            tempX = str_que.x + moveTo[i][0];
            tempY = str_que.y + moveTo[i][1];
            tempVisit = str_que.visit + 1;
            if(map[tempY][tempX] == 1 && (visit_arr[tempY][tempX] > tempVisit) && tempX >=0 && tempX < b && tempY >=0 && tempY < a)
            {
                visit_arr[tempY][tempX] = tempVisit;
                temp_str_que.x = tempX;
                temp_str_que.y = tempY;
                temp_str_que.visit = tempVisit;
                my_queue.push(temp_str_que);
            }
        }
        my_queue.pop();
    }


    printf("%d\n",visit_arr[a-1][b-1]);
    
    return 0;
}