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

int N,x,y,ans;
int cnt[6];

int main()
{
	scanf("%d",&N);
	memset(cnt,0,sizeof(cnt));
	while(N--)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	
	ans=cnt[4];
	
	y=min(cnt[3],cnt[1]);
	ans+=y,cnt[3]-=y,cnt[1]-=y;
	if(cnt[3]>0) ans+=cnt[3];
	
	ans+=(cnt[2])/2,cnt[2]%=2;
	if(cnt[2]>0)
	{
		ans++;
		cnt[1]-=min(2,cnt[1]);
	}
	
	if(cnt[1]>0) 
	{
		ans+=(cnt[1]/4);
		if(cnt[1]%4) ans++;
	}
	
	printf("%d\n",ans);
	return 0;
}

