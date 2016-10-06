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

int ans,x,y,z,N,PA,PB,PC,TA,TB;
PII dur[200];

int main()
{
	scanf("%d %d %d %d %d %d",&N,&PA,&PB,&PC,&TA,&TB);
	for(x=0;x<N;x++) scanf("%d %d",&dur[x].fi,&dur[x].se);
	
	ans=0;
	for(x=0;x<N;x++)
	{
		ans+=PA*(dur[x].se-dur[x].fi);
		if(x+1<N)
		{
			y=dur[x+1].fi-dur[x].se;
			z=min(y,TA);ans+=z*PA;y-=z;
			z=min(y,TB);ans+=z*PB;y-=z;
			ans+=y*PC;
		}
	}
	printf("%d\n",ans);
	return 0;
}

