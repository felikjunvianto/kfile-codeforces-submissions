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

int N, arr[111];

int tanda(int X)
{
	if(X > 0) return 1;
	if(X < 0) return -1;
	return 0;
}

int main()
{
	scanf("%d", &N);
	for(int n = 0; n < N; n++) scanf("%d", &arr[n]);

	bool allZ = true;
	for(int n = 0; n < N && allZ; n++) if(arr[n] != 0) allZ = false;

	if(allZ) printf("NO\n"); else
	{
		vector<PII> ans;

		int n = 0;
		do
		{
			int patokan = tanda(arr[n]);
			int k = n;

			while(k < N && (patokan == 0 || tanda(arr[k]) == 0 || tanda(arr[k]) == patokan)) 
			{
				k++;
				if(patokan == 0) patokan = tanda(arr[k]);
			}		
			ans.pb(mp(n + 1, k));

			n = k;
		} while (n < N);

		printf("YES\n%d\n", (int) ans.size());
		for(int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].fi, ans[i].se);
	}

	return 0;
}

