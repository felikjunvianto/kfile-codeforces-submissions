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

struct cell {
	int a, b, idx;
	cell(int a, int b, int idx) : a(a), b(b), idx(idx) {};

	bool operator< (const cell &other) const {
		if(a != other.a) return a < other.a;
		if(b != other.b) return b < other.b;
		return idx < other.idx;
	}
};

int T, N;
int a[111], b[111];
vector<cell> sorted, origin;
vector<pii> ans;

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", &a[i]);
		for(int i = 0; i < N; i++) scanf("%d", &b[i]);

		sorted.clear(); origin.clear();
		for(int i = 0; i < N; i++) {
			cell now = cell(a[i], b[i], i);
			sorted.pb(now);
			origin.pb(now);
		}

		sort(sorted.begin(), sorted.end());
		bool prune = false;
		for(int i = 1; i < N && !prune; i++) if(sorted[i].a < sorted[i-1].a || sorted[i].b < sorted[i-1].b) {
			prune = true;
		}

		if(prune) {
			printf("-1\n");
			continue;
		}

		// for(int i = 0; i < N; i++) printf("sorted (%d, %d, %d)\n", sorted[i].a, sorted[i].b, sorted[i].idx);
		// printf("==============\n");

		ans.clear();
		for(int i = 0; i < N - 1; i++) {
			int thisPos = sorted[i].idx;

			int inOri;
			for(inOri = 0; inOri < N; inOri++) if(origin[inOri].idx == thisPos) break;
			// cout << i << " " << thisPos << " " << inOri << " " << N << endl;
			if(inOri == i) continue;

			ans.pb(mp(i, inOri));
			swap(origin[i], origin[inOri]);

			// for(int j = 0; j < N; j++) printf("origin (%d, %d, %d)\n", origin[j].a, origin[j].b, origin[j].idx);
			// printf("==============\n");
		}
		
		printf("%d\n", ans.size());
		for(pii step : ans) printf("%d %d\n", step.fi + 1, step.se + 1);
	}
	return 0;
}
