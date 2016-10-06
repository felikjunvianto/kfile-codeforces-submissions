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
#define INF 5000000000000LL

using namespace std;

int N, M, K;
LL dp[5010][5010], P[5010], total;

LL solve(int now, int rem)
{
	if(now > N || (now == N && rem > 0)) return INF;
	if(now == N && rem == 0) return 0LL;
	if(dp[now][rem] != -1LL) return dp[now][rem];
	
	LL &ret = dp[now][rem] = INF;
	//take now
	ret = min(ret, P[now] + solve(now + 1, rem - 1));
	
	//skip now
	ret = min(ret, solve(now + M, rem));
	
	return ret;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	
	total = 0LL;
	for(int i = 0; i < N; i++)
	{
		scanf("%I64d", &P[i]);
		total += P[i];
	}
	
	memset(dp, -1LL, sizeof(dp));
	printf("%I64d\n", total - solve(0, N - M * K));
	return 0;
}

