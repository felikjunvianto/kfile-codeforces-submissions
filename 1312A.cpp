#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double> 
#define LL long long
#define INF 1000000000

using namespace std;

int T, M, N;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &N, &M);
		printf("%s\n", N % M == 0 ? "YES" : "NO");
	}
	return 0;
}

