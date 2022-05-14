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

int T;
char s[200010];
bool prefAllOnes[200010], suffAllZeros[200010];

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s + 1);
		int len = strlen(s + 1);

		prefAllOnes[0] = true;
		for(int i = 1; i <= len; i++)
			if(s[i] == '0') prefAllOnes[i] = false;
				else prefAllOnes[i] = prefAllOnes[i - 1];

		suffAllZeros[len + 1] = true;
		for(int i = len; i >= 1; i--)
			if(s[i] == '1') suffAllZeros[i] = false;
				else suffAllZeros[i] = suffAllZeros[i + 1];

		int ans = 0;
		for(int i = 1; i <= len; i++)
			if(prefAllOnes[i - 1] && suffAllZeros[i + 1]) ans++;

		printf("%d\n", ans);
	}

	return 0;
}

