#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 
#define pdd pair<double,double>
#define LL long long

#define PI 2*acos(0.0)
#define EPS 1e-9
#define INF 1e9

using namespace std;

int T, N;
char s[200010];
int dp[200010][2];

int solve(int now, int lastBit) {
	// cout << now << " " << lastBit << endl;
	if(now == N) return 1;

	int lastBitIdx = lastBit - '0';
	if(dp[now][lastBitIdx] != -1) return dp[now][lastBitIdx];

	int &ret = dp[now][lastBitIdx] = solve(now + 2, s[now]) + (s[now] == lastBit ? 0 : 1);
	if(s[now] != s[now + 1]) ret = min(ret, solve(now + 2, s[now+1]) + (s[now+1] == lastBit ? 0 : 1));

	return ret;
}

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		scanf("%s", s);

		int numOp = 0;
		for(int i = 0; i < N; i += 2) {
			if(s[i] != s[i+1]) numOp++;
		}	

		memset(dp, -1, sizeof(dp));

		int numSeg;
		if(s[0] == s[1]) numSeg = solve(2, s[0]);
			else numSeg = min(solve(2, s[0]), solve(2, s[1]));

		printf("%d %d\n", numOp, numSeg);
	}

	return 0;
}

