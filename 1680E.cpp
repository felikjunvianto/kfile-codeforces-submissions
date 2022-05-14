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

const int MAX = 200020;

int T, N;
char board[2][MAX];
int dp[MAX][4], suff[MAX];

int solve(int now, int bit) {
	if(now == N || suff[now] == 0) {
		if(bit == 1 || bit == 2) return 0;
		if(bit == 3) return 1;
		return INF;
	}
	if(dp[now][bit] != -1) return dp[now][bit];

	int &ret = dp[now][bit] = INF;
	if(bit == 3) ret = min(solve(now, 1), solve(now, 2)) + 1;

	int nowbit = ((board[0][now] == '*' ? 1 : 0) << 1) + (board[1][now] == '*' ? 1 : 0);
	switch(bit) {
		case 0:
			ret = solve(now + 1, nowbit);
			break;
		case 1:
			if(nowbit == 0) ret = solve(now + 1, 1) + 1; else
			if(nowbit == 1) ret = min(solve(now + 1, 1) + 1, solve(now + 1, 3) + 2); else
			if(nowbit == 2) ret = solve(now + 1, 3) + 1; else
			if(nowbit == 3) ret = solve(now + 1, 3) + 1;
			break;
		case 2:
			if(nowbit == 0) ret = solve(now + 1, 2) + 1; else
			if(nowbit == 1) ret = solve(now + 1, 3) + 1; else
			if(nowbit == 2) ret = min(solve(now + 1, 2) + 1, solve(now + 1, 3) + 2); else
			if(nowbit == 3) ret = solve(now + 1, 3) + 1;
			break;
		case 3:
			ret = min(solve(now + 1, 3) + 2, min(solve(now, 1), solve(now, 2)) + 1);
			break;
	}

	return ret;
}

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int r = 0; r < 2; r++) scanf("%s", board[r]);

		int chipNum = 0;
		for(int r = 0; r < 2; r++)
			for(int c = 0; c < N; c++)
				if(board[r][c] == '*') chipNum++;

		suff[N] = 0;
		for(int c = N - 1; c >= 0; c--) {
			int cnt = 0;
			for(int r = 0; r < 2; r++) if(board[r][c] == '*') cnt++;
			suff[c] = suff[c+1] + cnt;
		}

		memset(dp, -1, sizeof(dp));
		printf("%d\n", solve(0, 0));
	}

	return 0;
}

