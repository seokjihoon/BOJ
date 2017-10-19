#include <stdio.h>
#include <iostream>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

int graph[101][101];
int visit[101][101];
int compare (void *first, void *second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if(*(int*)first < *(int*)second)
        return -1;
    else return 0;
}
struct _my_str
{
    int se;
    int ga;
};

queue <_my_str> my_queue;
int moveTo[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
    int M, N, K;
    int i, j, p;
    int sN, sM, eN, eM;
    int tempSe, tempGa;
    _my_str my_str, temp_str;
    scanf("%d %d %d", &M, &N, &K);
    int *count;
    
    count = (int *)malloc(sizeof(int)*M*N);
    memset(count,0,sizeof(int)*M*N);
    
    int countIndex = 0;
    for(p = 0; p < K; p++)
    {
        scanf("%d %d %d %d", &sN, &sM, &eN, &eM);
        for(i = sM; i < eM; i++)
        {
            for(j =sN; j < eN; j++)
            {
                graph[i][j] = 1;
            }
            memcpy(visit[i],graph[i], N*sizeof(int));
        }
    }
    
    for(i = 0; i < M; i++)
    {
        for(j =0; j < N; j++)
        {
            if(visit[i][j] == 0 && graph[i][j] == 0)
            {
                visit[i][j] = 1;
                my_str.se=i;
                my_str.ga=j;
                my_queue.push(my_str);
                count[countIndex]++;
                while(!my_queue.empty())
                {
                    my_str = my_queue.front();
                    for(p=0;p<4;p++)
                    {
                        tempSe = my_str.se+moveTo[p][0];
                        tempGa = my_str.ga+moveTo[p][1];
                        if(tempSe>= 0 && tempSe<M && tempGa>= 0 && tempGa<N)
                        {
                            if(visit[tempSe][tempGa] == 0 && graph[tempSe][tempGa]==0)
                            {
                                visit[tempSe][tempGa] = 1;
                                temp_str.se = tempSe;
                                temp_str.ga = tempGa;
                                my_queue.push(temp_str);
                                count[countIndex]++;
                            }
                        }
                    }
                    my_queue.pop();
                }
                countIndex++;

            }
        }
    }

    
    sort(count,count+countIndex);
    printf("%d\n",countIndex);
    for(i = 0; i < countIndex; i++)
    {
        printf("%d ", count[i]);
    }
    return 0;
}

