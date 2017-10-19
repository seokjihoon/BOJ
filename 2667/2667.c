#include <stdio.h>
 
typedef struct _st{
	int se;
	int ga;
}st;
int move[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n;
int map[30][30];
int visit[30][30];


int output[500];
int tt = 0;


void dfs(st re)
{
	int i,j;
	st temp;
	output[tt]++;
	visit[re.se][re.ga] = 1;
	for(i=0;i<4;i++)
    {
		temp.se = re.se+move[i][0];
		temp.ga = re.ga+move[i][1];
		if(temp.se >= 0 && temp.se < n && temp.ga >=0 && temp.ga < n && !visit[temp.se][temp.ga] && map[temp.se][temp.ga])
        {
			dfs(temp);
        }
    }
}

int compare_func(void* arg1, void*arg2)
{
	return (*(int*)arg1-*(int*)arg2);
}
int main(void)
{
	int i,j;
	st now={0,0};
      // 여기서부터 작성
	scanf("%d", &n);

	for(i=0;i<n;i++)
    {
		for(j=0;j<n;j++)
        {
			scanf("%1d",&map[i][j]);
        }
    }

	for(i=0;i<n;i++)
    {
		for(j=0;j<n;j++)
        {
			if(map[i][j] && !visit[i][j])
            {
				now.se = i;
				now.ga = j;
				dfs(now);
				tt++;
            }
        }
    }
	printf("%d\n", tt);
	qsort(output,tt,sizeof(int),compare_func);
	for(i=0;i<tt;i++) printf("%d\n",output[i]);


      return 0;
}