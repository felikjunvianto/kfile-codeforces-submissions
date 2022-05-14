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

struct state {
	int i, node;
	state(int i, int node) : i(i), node(node) {};
};

vector<int> children[200010];
queue<state> Q;
vector<vector<int>> ans;

int T, N;

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1 ; i <= N; i++) children[i].clear();

		int root = -1, inp;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &inp);
			if(inp == i) root = i; else children[inp].pb(i);
		}

		ans.clear();
		while(!Q.empty()) Q.pop();
		Q.push(state(0, root));
		ans.pb(vector<int>{root});

		while(!Q.empty()) {
			state now = Q.front(); Q.pop();
			// cout << now.i << " " << now.node << endl;

			for(int i = 0; i < children[now.node].size(); i++) {
				int next = children[now.node][i], ni;

				if(!i) ni = now.i; else {
					ni = ans.size();
					ans.pb(vector<int>());
				}

				ans[ni].pb(next);
				Q.push((state(ni, next)));
			}
		}

		printf("%d\n", ans.size());
		for(int i = 0; i < ans.size(); i++) {
			printf("%d\n", ans[i].size());
			for(int j = 0; j < ans[i].size(); j++) printf("%d%c", ans[i][j], j + 1 == ans[i].size() ? '\n' : ' ');
		}

		if(T) printf("\n");
	}

	return 0;
}

