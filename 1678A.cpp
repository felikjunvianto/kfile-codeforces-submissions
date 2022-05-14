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

int T, N, a[101];
int numZero, cnt[101];

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);

		numZero = 0;
		memset(cnt, 0, sizeof(cnt));

		for(int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			cnt[a[i]]++;
			if(a[i] == 0) numZero++;
		}

		int extraOp = 0;
		if(!numZero) {
			bool twinFound = false;
			for(int i = 1; i <= 100 && !twinFound; i++) if(cnt[i] > 1) {
				numZero++;
				extraOp++;
				twinFound = true;
			}

			if(!twinFound) {
				numZero++;
				extraOp += 2;
			}
		}

		printf("%d\n", N - numZero + extraOp);
	}
	return 0;
}

