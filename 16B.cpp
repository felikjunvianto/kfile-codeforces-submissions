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

int N,M,x,ambil,ans;
PII match[30];

bool cf(PII a,PII b)
{
	if(a.se!=b.se) return(a.se>b.se);
	return(a.fi>b.fi);
}

int main()
{
	scanf("%d %d",&N,&M);
	for(x=0;x<M;x++) scanf("%d %d",&match[x].fi,&match[x].se);
	sort(match,match+M,cf);
	
	ans=0;
	for(x=0;x<M;x++)
	{
		ambil=min(N,match[x].fi);
		ans+=ambil*match[x].se;
		N-=ambil;
	}
	printf("%d\n",ans);
	return 0;
}

