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

int T, R, C;
char grid[10][10];
bool visited[10][10]; // track 1st robot;
vector<pii> init;
queue<vector<pii>> Q;

int dr[] = {-1, 0, 1, 0};
int dc[] = { 0, 1, 0,-1};

bool isValidMove(vector<pii> &state, int i) {
	for(int j = 0; j < state.size(); j++) {
		pii &robot = state[j];
		int nr = robot.fi + dr[i], nc = robot.se + dc[i];

		if(nr < 0 || nr >= R || nc < 0 || nc >= C) return false;
		if(!j && visited[nr][nc]) return false;
	}

	return true;
}

bool isOneArrived(vector<pii> &state) {
	for(pii &robot : state) {
		if(robot.fi == 0 && robot.se == 0) return true;
	}

	return false;
}

void print(vector<pii> &state) {
	for(pii &robot : state) {
		printf("(%d, %d), ", robot.fi, robot.se);
	}
	printf("\n");
}

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &R, &C);

		init.clear();
		for(int r = 0; r < R; r++) {
			scanf("%s", grid[r]);
			for(int c = 0; c < C; c++) if(grid[r][c] == 'R') {
				init.pb(mp(r, c));
			}
		}

		memset(visited, false, sizeof(visited));
		visited[init[0].fi][init[0].se] = true;

		while(!Q.empty()) Q.pop();
		Q.push(init);

		bool can = false;
		while(!Q.empty() && !can) {
			vector<pii> now = Q.front(); Q.pop();
			// print(now);
			if(isOneArrived(now)) {
				can = true;
				break;
			}

			for(int i = 0; i < 4; i++) {
				if(isValidMove(now, i)) {
					vector<pii> next;
					for(pii &robot : now) next.pb(mp(robot.fi + dr[i], robot.se + dc[i]));
					visited[next[0].fi][next[0].se] = true;
					Q.push(next);
				}
			}
		}

		printf("%s\n", can ? "YES" : "NO");
	}
	return 0;
}

