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
vector<pii> ranges;
vector<vector<pii> > rStartsWith;
set<pii> rangeSet;

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		ranges.clear();
		rStartsWith = vector<vector<pii> >(N + 1, vector<pii>());
		rangeSet.clear();

		for(int i = 0; i < N; i++) {
			int l, r;
			scanf("%d %d", &l, &r);
			pii cur = mp(l, r);
			ranges.pb(cur);
			rStartsWith[l].pb(cur);
			rangeSet.insert(cur);
		}

		for(int i = 0; i < N; i++) {
			pii cur = ranges[i];
			if(cur.fi == cur.se) {
				printf("%d %d %d\n", cur.fi, cur.fi, cur.fi);
				continue;
			}

			if(rangeSet.find(mp(cur.fi + 1, cur.se)) != rangeSet.end()) {
				printf("%d %d %d\n", cur.fi, cur.se, cur.fi);
				continue;
			}

			if(rangeSet.find(mp(cur.fi, cur.se - 1)) != rangeSet.end()) {
				printf("%d %d %d\n", cur.fi, cur.se, cur.se);
				continue;
			}

			for(int i = 0; i < rStartsWith[cur.fi].size(); i++) {
				pii toCheck = rStartsWith[cur.fi][i];
				if(toCheck.se > cur.se) continue;

				if(rangeSet.find(mp(toCheck.se + 2, cur.se)) != rangeSet.end()) {
					printf("%d %d %d\n", cur.fi, cur.se, toCheck.se + 1);
					break;
				}
			}
		}
	}
	return 0;
}

