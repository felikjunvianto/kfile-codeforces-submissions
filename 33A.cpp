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

int N,M,K,ans,x,y,z;
int tooth[1010];

int main()
{
	scanf("%d %d %d",&N,&M,&K);
	for(x=1;x<=M;x++) tooth[x]=INF;
	while(N--)
	{
		scanf("%d %d",&x,&y);
		tooth[x]=min(tooth[x],y);
	}
	
	ans=0;
	for(x=1;(x<=M)&&K;x++) if(tooth[x]!=INF)
	{
		z=min(tooth[x],K);
		ans+=z;
		K-=z;
	}
	printf("%d\n",ans);
	return 0;
}

