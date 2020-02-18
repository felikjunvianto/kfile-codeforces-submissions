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
#include <set>

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

int N, K;

int main() {
	scanf("%d %d", &N, &K);

	int leftspan = K - 1, rightspan = N - K;
	int firsttime = 2;
	int secondtime = 4;
	int sisa = (N - 2) * 3;
	int backorigin = min(leftspan, rightspan);

	printf("%d\n", firsttime + secondtime + sisa + backorigin);

	return 0;
}

