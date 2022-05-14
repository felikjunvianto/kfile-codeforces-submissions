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

int T, N, a[33];

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%d", &a[i]);

		int cnt = 0;
		bool can = true;
		for(int i = N - 2; i >= 0 & can; i--) {
			while(a[i] >= a[i+1] && a[i] != 0) {
				a[i] >>= 1;
				cnt++;
			}

			if(a[i] == 0 && a[i] == a[i+1]) can = false;
		}

		printf("%d\n", can ? cnt : -1);
	}

	return 0;
}

