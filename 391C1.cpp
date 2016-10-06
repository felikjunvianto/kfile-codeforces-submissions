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

struct fighter
{
	int p, e;
};

int N, K;
fighter orang[20];
int dp[20][1 << 16];

bool getK(int state)
{
	int score = __builtin_popcount(state), rank = N + 1;
	for(int i = 0; i < N; i++)
	{
		int lawan = orang[i].p;
		bool menang = (state & (1 << i));
		if(!menang) lawan++;
		
		if(lawan < score || (lawan == score && menang)) rank--;
	}
	
	return rank <= K;
}

int solve(int now, int state)
{
	if(now == N)
	{
		if(getK(state)) return 0;
			else return INF;
	}
	
	if(dp[now][state] != -1) return dp[now][state];
	
	int &ret = dp[now][state] = INF;
	ret = min(ret, orang[now].e + solve(now + 1, state + (1 << now))); // win
	ret = min(ret, solve(now + 1, state)); // lose
	
	return ret;
}

int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++) scanf("%d %d", &orang[i].p, &orang[i].e);
	
	memset(dp, -1, sizeof(dp));
	
	int ans = solve(0, 0);
	printf("%d\n", ans == INF ? -1 : ans);
	return 0;
}

