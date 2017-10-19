#include <stdio.h>

int main()
{
	int a[7] = {1,2,4,8,16,32,64};	
	int t;
	int i, j = 6;
	int count = 0;
	scanf("%d", &t);
	
	while(1)
	{
		for(i = j; i >= 0; i--)
			if(t/a[i])	break;
		t -= a[i];
		count++;
        if(!t)    break;
        j = i;
	}

	printf("%d",count);
	return 0;
}