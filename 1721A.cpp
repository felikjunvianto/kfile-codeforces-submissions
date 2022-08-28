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

int T, cnt[30];
char pic[3];

int main()
{
	scanf("%d", &T);
	while(T--) {
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < 2; i++) {
			scanf("%s", pic);
			cnt[pic[0] - 'a']++;
			cnt[pic[1] - 'a']++;
		}

		int big = 0, ans, block;
		for(int i = 0; i < 26; i++) big = max(big, cnt[i]);

		switch(big) {
			case(4): ans = 0; break;
			case(3): ans = 1; break;
			case(2): 
				block = 0;
				for(int i = 0; i < 26; i++) if(cnt[i] == 2) block++;
				ans = (block == 2) ? 1 : 2;
				break;
			case(1): ans = 3; break;
		}

		printf("%d\n", ans);
	}
	return 0;
}

