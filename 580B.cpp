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
#define PLL pair<LL, LL>
#define PDD pair<double,double> 
#define LL long long
#define INF 1000000000

using namespace std;

int N;
LL D;
PLL teman[100010];

int main()
{
	scanf("%d %I64d", &N, &D);
	for(int i = 0; i < N; i++) scanf("%I64d %I64d", &teman[i].fi, &teman[i].se);
	sort(teman, teman + N);
	
	LL temp_fact = 0, max_fact = 0;
	int head = 0, tail = 0;
	
	while(tail < N)
	{
		while(tail < N && teman[tail].fi - teman[head].fi < D)
			temp_fact += teman[tail++].se;
		
		max_fact = max(max_fact, temp_fact);
		
		if(tail < N)
			while(head < tail && teman[tail].fi - teman[head].fi >= D)
				temp_fact -= teman[head++].se;
	}
	
	printf("%I64d\n", max_fact);
	return 0;
}

