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

int T, N, len[100], nol, satu;
char inp[100];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		nol = satu = 0;
		for(int n = 0; n < N; n++) {
			scanf("%s", inp);
			len[n] = strlen(inp);
			for(int i = 0; i < len[n]; i++) if(inp[i] == '0') nol++; else satu++;
		}

		int ans = 0;
		for(int n = 0; n < N; n++) if(len[n] % 2 == 0) {
			int temp = len[n];
			while(temp - 2 >= 0 && nol - 2 >= 0) {
				temp -= 2;
				nol -= 2;
			}

			while(temp -2 >= 0 && satu - 2 >= 0) {
				temp -= 2;
				satu -= 2;
			}

			if(temp == 0) ans++;
		}

		for(int n = 0; n < N; n++) if(len[n] % 2 == 1) {
			int temp = len[n];
			while(temp - 2 >= 0 && nol - 2 >= 0) {
				temp -= 2;
				nol -= 2;
			}

			while(temp -2 >= 0 && satu - 2 >= 0) {
				temp -= 2;
				satu -= 2;
			}

			if(temp == 1 && nol > 0) {
				nol--;
				temp--;
			}

			if(temp == 1 && satu > 0) {
				satu--;
				temp--;
			}

			if(temp == 0) ans++;
		}

		printf("%d\n", ans);
	}
	return 0;
}

