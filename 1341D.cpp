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

int digit[] = {119, 36, 93, 109, 46, 107, 123, 37, 127, 111};
int cost[128][10];

int N, K;
int board[2002];
char inp[10];

bool visited[2002][2002];
bool dp[2002][2002];
pii nextState[2002][2002];
int picked[2002][2002];

bool solve(int now, int left) {
	if(now == N) return (left == 0);
	if(visited[now][left]) return dp[now][left];

	visited[now][left] = true;
	bool &ret = dp[now][left] = false;

	int cur = board[now];
	for(int i = 9; i >= 0; i--) {
		if(cost[cur][i] == -1 || cost[cur][i] > left) continue;

		int nextLeft = left - cost[cur][i];
		bool future = solve(now + 1, nextLeft);
		if(future) {
			ret = true;
			nextState[now][left] = mp(now + 1, nextLeft);
			picked[now][left] = i;
			break;
		}
	}

	return ret;
}

int main()
{
	memset(cost, -1, sizeof(cost));
	for(int state = 0; state < (1 << 7); state++)
		for(int num = 0; num < 10; num++) {
			int need = 0;
			bool okay = true;
			for(int k = 0; k < 7 && okay; k++) {
				if( (state & (1 << k)) && !(digit[num] & (1 << k))) okay = false;
				if(!(state & (1 << k)) &&  (digit[num] & (1 << k))) need++;
			}

			if(okay) cost[state][num] = need;
		}

	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++) {
		scanf("%s", inp);
		board[i] = 0;

		int fact = 1;
		for(int k = 0; k < 7; k++) {
			if(inp[k] == '1') board[i] += fact;
			fact *= 2;
		}
	}

	memset(visited, false, sizeof(visited));
	bool bisa = solve(0, K);

	if(bisa) {
		int a = 0, b = K;
		do {
			printf("%d", picked[a][b]);
			pii ns = nextState[a][b];
			a = ns.fi, b = ns.se;
		} while(a < N);
	} else printf("-1\n");

	return 0;
}

