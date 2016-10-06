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

using namespace std;

int N,M,x,y,l,r,ans;
int cost[110],t[110],ronde[110];

int main()
{
	scanf("%d %d",&N,&M);
	memset(ronde,-1,sizeof(ronde));
	for(x=1;x<=M;x++)
	{
		scanf("%d %d %d %d",&l,&r,&t[x],&cost[x]);
		for(y=l;y<=r;y++) if((ronde[y]==-1)|(t[ronde[y]]>t[x])) ronde[y]=x;
	}
	ans=0;
	for(x=1;x<=N;x++) if(ronde[x]!=-1) ans+=cost[ronde[x]];
	printf("%d\n",ans);
	return 0;
}

