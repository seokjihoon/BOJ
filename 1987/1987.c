#include <stdio.h>

char arr[30][30];
int visit[30][30];
int alpha[30];
int a, b;
int moveTo[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int max = 0;
//65
void dfs(int se, int ga, int cnt)
{
    int i;
    int tempSe, tempGa;
    if(max<cnt) max = cnt;
    for(i=0;i<4;i++)
    {
        tempSe = se + moveTo[i][0];
        tempGa = ga + moveTo[i][1];
        if(tempSe>=0&&tempSe<a&&tempGa>=0&&tempGa<b)
        {
            if(visit[tempSe][tempGa]) continue;
            if(alpha[arr[tempSe][tempGa]-65]) continue;
            visit[tempSe][tempGa] = 1;
            alpha[arr[tempSe][tempGa]-65] = 1;
            dfs(tempSe, tempGa, cnt+1);
            visit[tempSe][tempGa] = 0;
            alpha[arr[tempSe][tempGa]-65] = 0;
        }
    }
}
int main(void)
{
    // 여기서부터 작성
    int i;
    scanf("%d %d", &a, &b);
    
    for(i=0;i<a;i++)
        scanf("%s", arr[i]);
    visit[0][0] = 1;
    alpha[arr[0][0]-65] = 1;
    dfs(0,0,1);
    printf("%d", max);
    return 0;
}