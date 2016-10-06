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

int c[6], N, M, v[2010];
int dp[2010][2][2][2];

int solve(int now, bool c3bus, bool c3trol, bool c4)
{
	if(now == N + M) return 0;
	if(dp[now][c3bus][c3trol][c4] != -1) return dp[now][c3bus][c3trol][c4];
	
	int &ret = dp[now][c3bus][c3trol][c4] = 2*INF + 100;
	
	if(c4) ret = min(ret, solve(now+1, c3bus, c3trol, c4));
		else ret = min(ret, solve(now+1, c3bus, c3trol, 1) + c[4]);
	
	if(now < N) // bus
	{
		if(c3bus) ret = min(ret, solve(now+1, c3bus, c3trol, c4));
			else ret = min(ret, solve(now+1, 1, c3trol, c4) + c[3]);
	} 
	else // trolley
	{
		if(c3trol) ret = min(ret, solve(now+1, c3bus, c3trol, c4));
			else ret = min(ret, solve(now+1, c3bus, 1, c4) + c[3]);
	}
		
	ret = min(ret, solve(now+1, c3bus, c3trol, c4) + c[2]);
	ret = min(ret, solve(now+1, c3bus, c3trol, c4) + v[now] * c[1]);
	
	return ret;
}

int main()
{
	for(int i = 1; i <= 4; i++) scanf("%d", &c[i]);
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++) scanf("%d", &v[i]);
	for(int i = 0; i < M; i++) scanf("%d", &v[i + N]);
	
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(0, 0, 0, 0));
	return 0;
}

