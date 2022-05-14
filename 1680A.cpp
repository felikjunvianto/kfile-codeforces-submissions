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

int T, L1, R1, L2, R2;

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d %d", &L1, &R1, &L2, &R2);

		int ans;
		if(L1 <= L2 && L2 <= R1) {
			ans = L2;
		} else if(L2 <= L1 && L1 <= R2) {
			ans = L1;
		} else ans = L1 + L2;

		printf("%d\n", ans);
	}

	return 0;
}

