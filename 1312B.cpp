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

int T, N, a[111];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", &a[i]);
		
		sort(a, a + N);
		for(int i = N - 1; i >= 0; i--) printf("%d%c", a[i], i == 0 ? '\n' : ' ');
	}
	return 0;
}

