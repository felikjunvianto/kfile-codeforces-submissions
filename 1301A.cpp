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

int N;
char A[111],B[111],C[111];

int main() {
	scanf("%d", &N);
	while(N--) {
		scanf("%s", A);
		scanf("%s", B);
		scanf("%s", C);

		bool can = true;
		for(int i = 0, len = strlen(A); i < len && can; i++) {
			can = can && (A[i] == C[i] || B[i] == C[i]);
		}

		printf("%s\n", can ? "YES" : "NO");
	}
	return 0;
}

