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

int N, K, w;

int main() {
	scanf("%d %d", &N, &K);

	int total = 0;
	for(int i = 0; i < N; i++) {
		scanf("%d", &w);
		int carry = w % K == 0 ? 0 : 1;

		total += (w / K) + carry;
	}

	printf("%d\n", (total / 2) + (total % 2));
	return 0;
}

