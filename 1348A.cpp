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

int T, N;

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		int amt = N / 2;
		int a = 1 << N, b = 0, aAmt = 1, bAmt = 0;
		for(int i = 1; i < N; i++) {
			int coin = 1 << i;
			if(aAmt < amt) {
				a += coin;
				aAmt++;
			} else {
				b += coin;
				bAmt++;
			}
		}

		printf("%d\n", abs(a - b));
	}
	return 0;
}

