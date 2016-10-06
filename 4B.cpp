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

int N,sum,temin,temax,x,y,each[50];
PII day[50];

int main()
{
	scanf("%d %d",&N,&sum);
	temin=temax=0;
	for(x=1;x<=N;x++) 
	{
		scanf("%d %d",&day[x].fi,&day[x].se);
		temin+=day[x].fi,temax+=day[x].se;
	}
	
	if((sum<temin)||(sum>temax)) printf("NO\n"); else
	{
		for(x=1;x<=N;x++) 
		{
			each[x]=day[x].fi;
			sum-=day[x].fi;
		}
		
		x=0;
		while(sum)
		{
			x++;
			y=min(sum,day[x].se-day[x].fi);
			each[x]+=y;
			sum-=y;
		}
		
		printf("YES\n");
		for(x=1;x<=N;x++) printf("%d%c",each[x],x==N?'\n':' ');
	}
	return 0;
}

