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
#include <set>

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

int V, E, NS, s, a, b;
bool special[200010];
vector<int> adjlist[200010];

queue<PII> Q;
int disFrom1[200010], disFromN[200010];

int main() {
	scanf("%d %d %d", &V, &E, &NS);

	memset(special, false, sizeof(special));
	for(int k = 0; k < NS; k++) {
		scanf("%d", &s);
		special[s] = true;
	}

	for(int i = 1; i <= V; i++) adjlist[i].clear();
	while(E--) {
		scanf("%d %d", &a, &b);
		adjlist[a].pb(b);
		adjlist[b].pb(a);
	}

	memset(disFrom1, -1, sizeof(disFrom1));
	Q.push(mp(1, 0));
	disFrom1[1] = 0;
	while(!Q.empty()) {
		PII now = Q.front(); Q.pop();
		for(int i = 0; i < adjlist[now.fi].size(); i++) {
			int next = adjlist[now.fi][i];
			if(disFrom1[next] == -1) {
				disFrom1[next] = now.se + 1;
				Q.push(mp(next, now.se + 1));
			}
		}
	}

	memset(disFromN, -1, sizeof(disFromN));
	Q.push(mp(V, 0));
	disFromN[V] = 0;
	while(!Q.empty()) {
		PII now = Q.front(); Q.pop();
		for(int i = 0; i < adjlist[now.fi].size(); i++) {
			int next = adjlist[now.fi][i];
			if(disFromN[next] == -1) {
				disFromN[next] = now.se + 1;
				Q.push(mp(next, now.se + 1));
			}
		}
	}	

	// for(int i = 1; i <= V; i++) printf("%d ", disFrom1[i]); printf("\n");
	// for(int i = 1; i <= V; i++) printf("%d ", disFromN[i]); printf("\n");

	int ans = 0;
	for(int i = 1; i <= V; i++) if(special[i])
		for(int j = i + 1; j <= V; j++) if (special[j]) {
			a = i, b = j;
			if(disFrom1[a] + disFromN[b] > disFrom1[b] + disFromN[a]) swap(a, b);
			ans = max(ans, disFrom1[a] + disFromN[b] + 1);
			// cout << a << " " << b << " " << disFrom1[a] + disFromN[b] + 1 << endl;
		}

	printf("%d\n", min(ans, disFrom1[V]));

	return 0;
}

