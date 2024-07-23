#include <stdio.h>

int LeastCommonMultiple(int a, int b)
{
	int min = a<b? a:b;
	
	for(int i=min;; i++)
	{
		if(i % a == 0 && i % b == 0)
			return i;
	}
}

int main()
{
	// 도색 -> 광택 
	//도색 : P개의 성공 직후 실패 
	//광택 : V개의 성공 직후 실패
	// K : 총 연필개수
	
	int P,V,K;
	scanf("%d %d %d", &P, &V, &K);
	
	//n = 12는 (P+1)과 (V+1) least multiple
	int n = LeastCommonMultiple(P+1, V+1);
	int fail_both = K/n;
	int fail_p = (K/(P+1)) - fail_both;
	int fail_v = (K/(V+1)) - fail_both;
	
	printf("%d\n", K-fail_p-fail_v-fail_both);	//A
	printf("%d\n", fail_both);	//B
	printf("%d\n", fail_v);	//C
	printf("%d\n", fail_p);	//D
	
	return 0;
}
