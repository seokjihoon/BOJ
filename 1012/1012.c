#include <stdio.h>

typedef struct _st
{
    int se;
    int ga;
}st;
int ar[60][60];
int visit[60][60];
int cnt = 0;
int a, b, c;
int aa, bb;
int _move[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
void dfs(st now)
{
    int i;
    st temp;
    visit[now.se][now.ga] = 1;
    for(i=0;i<4;i++)
    {
        temp.se = now.se + _move[i][0];
        temp.ga = now.ga + _move[i][1];
        if(temp.se>=0 && temp.se < b && temp.ga >= 0 && temp.ga < a && !visit[temp.se][temp.ga] && ar[temp.se][temp.ga])
        {
            dfs(temp);
        }
    }
    
}
int main()
{
    int T;
    int i,j;
    int ii, jj;
    st now;
    scanf("%d", &T);
    
    for(i=0;i<T;i++)
    {
        cnt = 0;
        scanf("%d %d %d", &a, &b, &c);
        for(j=0;j<c;j++)
        {
            scanf("%d %d", &aa, &bb);
            ar[bb][aa] = 1;
        }
        
        for(ii=0;ii<b;ii++)
        {
            for(jj=0;jj<a;jj++)
            {
                if(ar[ii][jj] && !visit[ii][jj])
                {
                    now.se = ii;
                    now.ga = jj;
                    dfs(now);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
        for(ii=0;ii<b;ii++)
        {
            for(jj=0;jj<a;jj++)
            {
                ar[ii][jj] = 0;
                visit[ii][jj] = 0;
            }
        }
    }
    
    
    return 0;
}

