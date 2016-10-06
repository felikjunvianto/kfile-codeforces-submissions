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

int N,x,y,z,tot,ans,now;
int coin[111];

int main()
{
	scanf("%d",&N);
	
	tot=0;
	for(x=1;x<=N;x++) 
	{
		scanf("%d",&coin[x]);
		tot+=coin[x];
	}
	sort(coin+1,coin+1+N);
	
	ans=now=0;
	for(x=N;x>0;x--)
	{
		now+=coin[x];
		ans++;
		
		if(now>tot-now) break;
	}
	
	printf("%d\n",ans);
	return 0;
}

