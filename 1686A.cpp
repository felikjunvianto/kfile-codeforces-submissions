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

int N, T, a[55], tot;

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		tot = 0;
		for(int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			tot += a[i];
		}

		bool can = false;
		for(int i = 0; i < N && !can; i++) {
			if(tot - a[i] == a[i] * (N - 1)) can = true;
		}

		printf("%s\n", can ? "YES" : "NO");
	}
	return 0;
}

