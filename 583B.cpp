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

int N, a[1010];
bool bolong[1010];

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
	
	int dir = 1, pos = 1, total = 0, ans = 0;
	memset(bolong, false, sizeof(bolong));
	
	while(total < N)
	{
		if(!bolong[pos] && a[pos] <= total)
		{
			total++;
			bolong[pos] = true;
		}
		
		if(total < N)
		{
			if(pos + dir < 1 || pos + dir > N) 
			{
				dir = -dir;
				ans++;
			}
		
			pos += dir;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}

