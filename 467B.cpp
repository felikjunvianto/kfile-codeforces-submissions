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

int N, M, K, Fedor, player[1010];

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < M; i++) scanf("%d", &player[i]);
	scanf("%d", &Fedor);
	
	int ans = 0;
	for(int i = 0; i < M; i++)
	{
		int beda = 0;
		for(int j = 0; j < N; j++)
		{
			bool satu = (player[i] & (1 << j)) > 0;
			bool dua = (Fedor & (1 << j)) > 0;
			
			if(satu != dua) beda++;
		}
		
		if(beda <= K) ans++;
	}
	
	printf("%d\n", ans);
	return 0;
}

