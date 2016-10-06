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

PII team[100];
int N,K;
int x,y,z,ans;

bool cf(PII i, PII j)
{
	if(i.fi!=j.fi) return (i.fi>j.fi);
	return (i.se<j.se);
}

int main()
{
	scanf("%d %d",&N,&K);
	for(x=1;x<=N;x++) scanf("%d %d",&team[x].fi,&team[x].se);
	sort(team+1,team+1+N,cf);
	
	ans=1;
	x=K-1;
	while((x>0)&&(team[x]==team[K]))
	{
		ans++;
		x--;
	}
	
	y=K+1;
	while((y<=N)&&(team[y]==team[K]))
	{
		ans++;
		y++;
	}
	
	printf("%d\n",ans);
	return 0;
}

