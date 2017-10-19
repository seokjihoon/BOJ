#include <stdio.h>
int array[30];
int printArray[30];
int n;

int check(int k, int a)
{
    int i;
    for(i=0;i<a;i++)
    {
        if(printArray[i] >= k) return 0;
    }
    return 1;
}
void dfs(int cnt)
{
    int i;
    if(cnt==6)
    {
        for(i=0;i<6;i++)    printf("%d ",printArray[i]);
        printf("\n");
        return ;
    }
    
    for(i=0;i<n;i++)
    {
        if(check(array[i], cnt)==0) continue;
        printArray[cnt] = array[i];
        dfs(cnt+1);
    }
}

int main()
{
    int i;
    
    while(1)
    {
        scanf("%d", &n);
        if(n==0) break;
        for(i=0;i<n;i++) scanf("%d", &array[i]);
        dfs(0);
        printf("\n");
        
    }
    return 0;
}

