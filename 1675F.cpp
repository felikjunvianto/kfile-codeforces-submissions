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

const int MAX_NODE = 200020;

struct State {
	int val, subtreeNumTask;
	vector<int> children;

	State() : val(0), subtreeNumTask(0), children(vector<int>()) {};
	State(int val, int numTask) : val(val), subtreeNumTask(numTask), children(vector<int>()) {};
};

int T, N, K, start, finish;

bool hasTask[MAX_NODE];
int parent[MAX_NODE];
State node[MAX_NODE];
vector<int> adjlist[MAX_NODE], path;

void constructTree(int prev, int now) {
	for(int next : adjlist[now]) if(next != prev) {
		node[now].children.pb(next);
		parent[next] = now;

		constructTree(now, next);
		node[now].subtreeNumTask += node[next].subtreeNumTask;
	}
}

void printTree(int now) {
	printf("(node = %d, subtreeTask = %d) - ", node[now].val, node[now].subtreeNumTask);
	for(int child : node[now].children) printf("%d, ", child);
	printf("\n");

	for(int child : node[now].children) printTree(child);
}

int finishJobAtSubTree(int now) {
	int ans = 0;

	for(int next : node[now].children)
		if(node[next].subtreeNumTask > 0)
			ans += 2 + finishJobAtSubTree(next);

	return ans;
}

int traversePath(int idx) {
	if(idx >= path.size()) return 0;

	int now = path[idx];
	int ans = 0;

	for(int next : node[now].children) {
		if(idx + 1 < path.size() && path[idx + 1] == next) continue;
		if(node[next].subtreeNumTask > 0) ans += 2 + finishJobAtSubTree(next);
	}

	return ans + (idx + 1 < path.size() ? 1 : 0) + traversePath(idx + 1);
}

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &N, &K);
		scanf("%d %d", &start, &finish);

		for(int i = 1; i <= N; i++) {
			hasTask[i] = false;
			node[i] = State(i, 0);
			adjlist[i].clear();
			parent[i] = -1;
		}

		while(K--) {
			int tHouse;
			scanf("%d", &tHouse);
			node[tHouse].subtreeNumTask = 1;
		}

		for(int i = 1; i < N; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adjlist[a].pb(b);
			adjlist[b].pb(a);
		}

		constructTree(-1, start);
		
		path.clear();
		int now = finish;
		while(now != -1) {
			path.pb(now);
			now = parent[now];
		}
		reverse(path.begin(), path.end());

		printf("%d\n", traversePath(0));
	}

	return 0;
}

