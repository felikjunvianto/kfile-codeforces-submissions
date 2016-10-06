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

LL KFib[60], sum[60], S;
vector<LL> ans;
int K, x;

map<LL, int> dp;

int main()
{
	scanf("%I64d %d",&S, &K);
	
	sum[0] = KFib[0] = 0LL;
	sum[1] = KFib[1] = 1LL;
	
	for(x=2; x <= 50; x++) 
	{
		int head = max(x - K - 1, 0);
		KFib[x] = sum[x-1] - sum[head];
		sum[x] = sum[x-1] + KFib[x];
	} 
	
	//for(x=0;x<=50;x++) printf("%I64d\n",KFib[x]);
	
	for(x = 50; x >= 0;x--) if(KFib[x]<=S)
	{
		S -= KFib[x];
		ans.pb(KFib[x]);
	} 
		
	printf("%d\n",ans.size());
	for(x=0;x<ans.size();x++) printf("%I64d%c",ans[x],x+1==(int)ans.size()?'\n':' ');
	
	return 0;
}

