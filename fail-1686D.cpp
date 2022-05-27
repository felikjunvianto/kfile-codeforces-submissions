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

int T, a, b, c, d, len, ptr, totA, totB;
char s[200020];
vector<int> abab, baba, aba, bab;

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		scanf("%s", s); len = strlen(s);

		abab.clear();
		baba.clear();
		aba.clear();
		baba.clear();

		totA = totB = 0;
		for(int i = 0; i < len; i++) if(s[i] == 'A') totA++; else totB++;

		int x = 0;
		while(x < len) {
			int y = x + 1;
			while(y < len && s[y-1] != s[y]) y++;

			if(y - x == 1) {
				if(s[x] == 'A') {
					a--; 
					totA--;
				} else {
					b--;
					totB--;
				}
			} else {
				int num = y - x;
				if(num % 2 == 0) {
					if(s[x] == 'A') abab.pb(num);
						else baba.pb(num); 
				} else {
					if(s[x] == 'A') aba.pb(num);
						else bab.pb(num);
				}
			}

			x = y;
		}

		// printf("initial %d %d %d %d %d %d\n", a, b, c, d, totA, totB);
		if(a < 0 || b < 0) {
			printf("NO\n");
			continue;
		}

		if(c > 0) {
			ptr = abab.size() - 1;
			while(c > 0 && !abab.empty()) {
				if(abab[ptr] <= c * 2) {
					int minus = abab[ptr--] / 2;
					c -= minus; totA -= minus; totB -= minus;
					abab.pop_back();
				} else {
					abab[ptr] -= c * 2;; totA -= c; totB -= c;
					c = 0;
				}
			}
		
			ptr = aba.size() - 1;
			while(c > 0 && a > 0 && !aba.empty()) {
				if(aba[ptr] <= c * 2) {
					int minus = (aba[ptr--] - 1) / 2;
					c -= minus; totA -= (minus + 1); totB -= minus;
					a--;
					aba.pop_back();
				} else {
					aba[ptr] -= c * 2;; totA -= c; totB -= c;
					c = 0;
				}
			}

			ptr = bab.size() - 1;
			while(c > 0 && b > 0 && !bab.empty()) {
				if(bab[ptr] <= c * 2) {
					int minus = (bab[ptr--] - 1) / 2;
					c -= minus; totA -= minus; totB -= (minus + 1);
					b--;
					bab.pop_back();
				} else {
					bab[ptr] -= c * 2;; totA -= c; totB -= c;
					c = 0;
				}
			}

			ptr = baba.size() - 1;
			while(c > 0 && a > 0 && b > 0 && !baba.empty()) {
				if(baba[ptr] - 2 <= c * 2) {
					int minus = (baba[ptr--] - 2) / 2;
					c -= minus; totA -= (minus + 1); totB -= (minus + 1);
					a--;
					b--;
					baba.pop_back();
				} else {
					baba[ptr] -= c * 2;; totA -= c; totB -= c;
					c = 0;
				}
			}
		}

		if(d > 0) {
			ptr = baba.size() - 1;
			while(d > 0 && !baba.empty()) {
				if(baba[ptr] >= d * 2) {
					int minus = baba[ptr--] / 2;
					d -= minus; totA -= minus; totB -= minus;
					baba.pop_back();
				} else {
					baba[ptr] -= d * 2; totA -= d; totB -= d;
					d = 0;
				}
			}

			ptr = aba.size() - 1;
			while(d > 0 && a > 0 && !aba.empty()) {
				if(aba[ptr] <= d * 2) {
					int minus = (aba[ptr--] - 1) / 2;
					d -= minus; totA -= (minus + 1); totB -= minus;
					a--;
					aba.pop_back();
				} else {
					aba[ptr] -= d * 2; totA -= d; totB -= d;
					d = 0;
				}
			}

			ptr = bab.size() - 1;
			while(d > 0 && b > 0 && !bab.empty()) {
				if(bab[ptr] <= d * 2) {
					int minus = (bab[ptr--] - 1) / 2;
					d -= minus; totA -= minus; totB -= (minus + 1);
					b--;
					bab.pop_back();
				} else {
					bab[ptr] -= d * 2; totA -= d; totB -= d;
					d = 0;
				}
			}

			ptr = abab.size() - 1;
			while(d > 0 && a > 0 && b > 0 && !abab.empty()) {
				if(abab[ptr] - 2 <= d * 2) {
					int minus = (abab[ptr--] - 2) / 2;
					d -= minus; totA -= (minus + 1); totB -= (minus + 1);
					a--;
					b--;
					abab.pop_back();
				} else {
					abab[ptr] -= d * 2; totA -= d; totB -= d;
					d = 0;
				}
			}
		}

		// printf("final %d %d %d %d %d %d\n", a, b, c, d, totA, totB);
		if(totA != a || totB != b) printf("NO\n");
			else printf("%s\n", (c || d) ? "NO" : "YES");
	}
	return 0;
}

