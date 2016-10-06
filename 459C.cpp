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

int N, D, K;
int bis[1010];

int main()
{
	scanf("%d %d %d", &N, &K, &D);
	int temp = K, pang = 1;
	double oke = K >= N;
	
	while(!oke && temp < N && pang < D)
	{
		temp *= K;
		pang++;
		if(temp >= N) oke = true;
	}
	
	if(!oke)
	{
		printf("-1\n");
		return 0;
	}
	
	for(int i = 0; i < N; i++) bis[i] = i;
	for(int i = 0; i < D; i++)
		for(int j = 0; j < N; j++)
		{
			printf("%d%c", (bis[j] % K) + 1, j + 1 == N ? '\n' : ' ');
			bis[j] /= K;
		}

	return 0;
}

