#include <stdio.h>
#include <math.h>

long long com(double up, double down)
{
	double dif = up - down;
	double returnNum = 1;
	int i;
	for (i = 0; i < dif; i++){
		returnNum *= ((up - i) / (dif - i));
	}
	if (returnNum - (long long)returnNum > 0.5) returnNum++;
	return returnNum;
}
int main(void) {

	int T;
	int test_case;
	double n, m;
	double ans;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		scanf("%lf %lf", &n, &m);

		if (n == m) ans = 1;
		else if (n > m) ans = com(n, m);
		else ans = com(m, n);
		
		printf("%lld\n", (long long)ans);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}