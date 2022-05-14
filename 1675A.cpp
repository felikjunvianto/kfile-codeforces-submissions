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

int T, a, b, c, x, y;

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

		x -= min(x, a);
		y -= min(y, b);

		printf("%s\n", x + y <= c ? "YES" : "NO");	
	}

	return 0;
}

