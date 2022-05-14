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

const int MAX = 200020;

int T, len;
char s[MAX];
int prefOneSum[MAX], prefZeroRem[MAX];
map<int, int> minZeroRem;

void print() {
	printf("%s\n", s + 1);
	for(int i = 0; i <= len + 1; i++) cout << prefOneSum[i]; cout << endl;
	for(int i = 0; i <= len + 1; i++) cout << prefZeroRem[i]; cout << endl;
	cout << endl;
}

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s + 1); len = strlen(s + 1);

		prefOneSum[0] = prefZeroRem[0] = 0;
		for(int i = 1; i <= len; i++) {
			prefOneSum[i] = prefOneSum[i-1] + (s[i] - '0');
			prefZeroRem[i] = prefZeroRem[i-1] + (s[i] == '0' ? 1 : 0);
		}
		prefOneSum[len+1] = prefOneSum[len];

		// print();
		minZeroRem.clear();
		for(int right = 1; right <= len + 1; right++) {
			int onesRemoved = prefOneSum[len+1] - prefOneSum[right-1];
			int zeroRemains = prefZeroRem[right - 1];

			if(minZeroRem.find(onesRemoved) == minZeroRem.end()) minZeroRem[onesRemoved] = zeroRemains;
				else minZeroRem[onesRemoved] = min(minZeroRem[onesRemoved], zeroRemains);
		}

		int ans = -1;
		for(int left = 0; left <= len; left++)
			for(int right = left + 1; right <= len + 1; right++) {
				int onesRemoved = prefOneSum[left] + prefOneSum[len+1] - prefOneSum[right-1];
				int zeroRemains = prefZeroRem[right - 1] - prefZeroRem[left];
				int cost = max(onesRemoved, zeroRemains);

				if(ans == -1 || ans > cost) ans = cost;
			}

		printf("%d\n", ans);
	}
	return 0;
}

