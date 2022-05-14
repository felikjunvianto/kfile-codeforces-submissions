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

int T, N, p[5050];
int prefMat[5050][5050];

int main()
{
	scanf("%d", &T);
	memset(prefMat, 0, sizeof(prefMat));

	while(T--) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", &p[i]);

		for(int c = 0; c < N; c++) {
			prefMat[c][0] = 0;
			for(int a = 0; a < c; a++) {
				prefMat[c][a+1] = prefMat[c][a];
				if(p[a] < p[c]) prefMat[c][a+1]++;
			}
		}

		// for(int r = 0; r < N; r++)
		// 	for(int c = 0; c < N; c++)
		// 		printf("%d%c", prefMat[r][c], c + 1 == N ? '\n' : ' ');

		LL ans = 0LL;
		for(int b = 1; b < N; b++) {
			int acPairCnt = prefMat[b+1][b];
			for(int d = b + 2; d < N; d++) {
				if(p[b] > p[d]) ans += (LL) acPairCnt;
				acPairCnt += prefMat[d][b];
			}
		}

		printf("%I64d\n", ans);
	}
	return 0;
}

