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

int N, Q, a[200020];
int flashNum, lastFlashTurn;
int lastFlashed[200020];
LL total;

int main()
{
	scanf("%d %d", &N, &Q);

	total = 0LL;
	for(int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
		total += (LL) a[i];
	}

	lastFlashTurn = -1;
	memset(lastFlashed, 0, sizeof(lastFlashed));

	for(int q = 1; q <= Q; q++) {
		int type; scanf("%d", &type);
		int i, x;
		switch(type) {
			case 1:
				scanf("%d %d", &i, &x);
				if(lastFlashed[i] < lastFlashTurn) {
					total -= (LL) flashNum;
					lastFlashed[i] = lastFlashTurn;
				} else total -= (LL) a[i];

				total += (LL) x;
				a[i] = x;
				break;

			case 2:
				scanf("%d", &x);
				lastFlashTurn = q;
				total = (LL) x * (LL) N;
				flashNum = x;
				break;
		}

		printf("%I64d\n", total);
	}
	return 0;
}

