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

int N, M, K;
LL a[20], rules[20][20], dp[1 << 18][20];

int hitung(int state)
{
	int ans = 0;
	while(state)
	{
		ans += state & 1;
		state >>= 1;
	}
	
	return ans;
}

LL solve(int state, int terakhir)
{
	// cout << state << " " << terakhir << " " << hitung(state) << endl;
	if(hitung(state) == M) return 0LL;
	if(dp[state][terakhir] != -1LL) return dp[state][terakhir];
	
	LL &ret = dp[state][terakhir] = 0LL;
	for(int next = 1; next <= N; next++)
	{
		int i = 1 << (next - 1);
		if((state & i) == 0)
		{
			// cout << "cihuy dapat " << terakhir << " " << next << " " << rules[terakhir][next] << endl;
			ret = max(ret, solve(state | i, next) + a[next] + rules[terakhir][next]);
		}
	}
	
	return ret;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 1; i <= N; i++) scanf("%I64d", &a[i]);
	
	memset(rules, 0LL, sizeof(rules));
	while(K--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		scanf("%I64d", &rules[x][y]);		
	}
	
	memset(dp, -1LL, sizeof(dp));
	printf("%I64d\n", solve(0, 0));
	return 0;
}

