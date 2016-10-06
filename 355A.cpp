#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double> 
#define LL long long
#define INF 1000000000

using namespace std;

int K, D;
char num[1010];

int dr(char *temp)
{
	int res = 0;
	for(int i = 0; i < K; i++) res += (int) (temp[i] - '0');
	
	while(res >= 10)
	{
		int temp = res;
		res = 0;
		
		while(temp)
		{
			res += temp % 10;
			temp /= 10;
		}
	}
	
	return res;
}

int main()
{
	scanf("%d %d", &K, &D);
	
	if(!D)
	{
		if(K == 1) printf("0\n");
			else printf("No solution\n");
		return 0;
	}
	
	for(int i = 0; i < K; i++) num[i] = '1';
	num[K] = '\0';
	
	int last = K - 1;
	while(dr(num) != D)
	{
		if(num[last] == '9') last--;
		num[last]++;
	}
	
	printf("%s\n", num);
	return 0;
}

