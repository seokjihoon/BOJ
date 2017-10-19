#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int a, b, num = 0;
	int i;
	cin >> a >> b;
	int *arr = new int[a + 1];

	for (i = 0; i < a; i++)
		arr[i] = i+1;
	printf("<");
	for (i = 0; i < a; i++)
	{
		num += b - 1;
		num %= (a - i);
		if (i < a - 1)
		{
			printf("%d, ", arr[num]);
		}
		else printf("%d>", arr[num]);
		arr[num] = 0;
		if (i < a - 1)
		{
			sort(arr, arr + a - i);
			arr++;
		}
	}
	return 0;
}