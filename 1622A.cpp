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

int T, l[3];

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d", &l[0], &l[1], &l[2]);
		sort(l, l + 3);

		if(l[2] == l[1] + l[0]) printf("YES\n"); else
		if(l[0] == l[1] && l[2] % 2 == 0) printf("YES\n"); else
		if(l[2] == l[1] && l[0] % 2 == 0) printf("YES\n"); else
		printf("NO\n");
	}
	return 0;
}

