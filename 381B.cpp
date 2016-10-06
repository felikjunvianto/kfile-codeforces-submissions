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

int M, cnt[5050];
vector<int> ans;

int main()
{
	scanf("%d", &M);
	memset(cnt, 0, sizeof(cnt));
	
	int temp;
	for(int i = 1; i <= M; i++)
	{
		scanf("%d", &temp);
		cnt[temp]++;
	}
	
	int large;
	for(large = 5000; large > 0; large--) if(cnt[large]) break;
	
	for(int i = 1; i < large; i++) if(cnt[i]) 
	{
		ans.pb(i);
		cnt[i]--;
	}
	
	ans.pb(large);
	
	for(int i = large - 1; i > 0; i--) if(cnt[i]) ans.pb(i);
	
	printf("%d\n", (int) ans.size());
	for(int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], i + 1 == (int) ans.size() ? '\n' :' ');
	return 0;
}

