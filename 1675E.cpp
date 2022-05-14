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

const char NONE = '$';

int T, N, K;
char changeTo[30], s[200020];

int main()
{
	scanf("%d\n", &T);
	while(T--) {
		scanf("%d %d", &N, &K);
		scanf("%s", s);
		int len = strlen(s);

		int maxDis = 0;
		for(int i = 0; i < len; i++) maxDis = max(maxDis, s[i] - 'a');
		
		if(maxDis <= K) {
			for(int i = 0; i < len; i++) printf("a");
			printf("\n");
			continue;
		}

		memset(changeTo, NONE, sizeof(changeTo));
		changeTo[0] = 'a';

		for(int i = 0; i < len; i++) {
			int idx = s[i] - 'a';
			if(changeTo[idx] == NONE) {
				int move = idx;
				while(K > 0 && changeTo[move] == NONE) {
					K--;
					move--;
				}

				if(changeTo[move] == NONE) changeTo[move] = (char)('a' + move);
				for(int i = move + 1; i <= idx; i++) changeTo[i] = changeTo[move];
			}

			s[i] = changeTo[idx];
		}

		printf("%s\n", s);
	}

	return 0;
}

