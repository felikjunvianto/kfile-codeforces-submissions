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

int N, M;
vector<int> teman[150010];
vector<int> current;
bool used[150010];

void ff(int now) {
	used[now] = true;
	current.pb(now);

	for(int i = 0; i < teman[now].size(); i++) {
		int next = teman[now][i];
		if(!used[next]) ff(next);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) teman[i].clear();

	while(M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		teman[a].pb(b);
		teman[b].pb(a);
	}

	memset(used, false, sizeof(used));

	bool reasonable = true;
	for(int i = 1; i <= N && reasonable; i++) if(!used[i]) {
		current.clear();
		ff(i);

		LL totE = 0LL, totV = (LL) current.size();
		for(int j = 0; j < current.size(); j++) {
			int node = current[j];
			totE += (LL) teman[node].size();
		}

		if(totE != totV * (totV - 1LL)) reasonable = false;
	}

	printf("%s\n", reasonable ? "YES" : "NO");

	return 0;
}

