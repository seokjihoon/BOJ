#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;

queue<int> que;
int s,n;
bool *visit;
bool graph[1000][1000] = {false};

void dfs(int v)
{
    visit[v] = true;
    printf("%d ",v+1);
    for(int i = 0; i < n; i++)
        if(graph[v][i] && !visit[i])
            dfs(i);
}

int main()
{
    int m, a, b;
    
    scanf("%d %d %d", &n, &m, &s);
    visit = new bool[n]();
    s--;
    
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        a--; b--;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    dfs(s);
    puts("");
    memset(visit,0,n*sizeof(bool));
    visit[s] = true;
    que.push(s);
    while(!que.empty())
    {
        int top = que.front();
        for(int i = 0; i < n; i++)
        {
            if(graph[top][i] && !visit[i])
            {
                que.push(i);
                visit[i] = true;
            }
        }
        printf("%d ", top+1);
        que.pop();
    }
}