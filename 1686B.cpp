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

int T, N, p[200020];

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", &p[i]);

		int ans = 0;
		for(int i = 0; i + 1 < N; i++) if(p[i] > p[i + 1]) {
			ans++;
			i++;
		}

		printf("%d\n", ans);
	}
	return 0;
}

