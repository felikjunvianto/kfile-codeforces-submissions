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

const int SIZE = 1e5 + 5;

int T, N;
int perm[SIZE], turn[SIZE];
int cnt[SIZE], r[SIZE];
bool picked[SIZE];

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &perm[i]);
			turn[perm[i]] = i;
		}

		bool can = true;
		memset(picked, false, sizeof(picked));

		for(int i = 1; i <= N && can; i++) {
			memset(cnt, 0, sizeof(cnt));
			memset(r, -1, sizeof(turn));

			int last = -1;
			for(int j = N; j >= 1; j--) {
				if(!picked[j]) last = j;
				r[j] = last;
			}

			int maks = 0;
			for(int j = 1; j <= N; j++) if(r[j] != -1) {
				cnt[r[j]]++;
				maks = max(maks, cnt[r[j]]);
			}

			if(cnt[turn[i]] != maks) can = false;
			picked[turn[i]] = true;
		}

		printf("%s\n", can ? "Yes" : "No");
	}

	return 0;
}

