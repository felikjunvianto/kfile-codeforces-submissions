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

int T, N, M;
int a, maxA, b, maxB;

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		maxA = 0;
		while(N--) {
			scanf("%d", &a);
			maxA = max(a, maxA);
		}

		scanf("%d", &M);
		maxB = 0;
		while(M--) {
			scanf("%d", &b);
			maxB = max(b, maxB);
		}

		if(maxA > maxB) printf("Alice\nAlice\n"); else
		if(maxA < maxB) printf("Bob\nBob\n"); else
		printf("Alice\nBob\n");
	}
	return 0;
}
