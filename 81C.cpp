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

int N,a,b,x,y,z;
PII score[100100];
int ans[100100];

bool cfa(PII i,PII j)
{
	if(i.se!=j.se) return(i.se>j.se);
	return(i.fi>j.fi);
}

bool cfb(PII i,PII j)
{
	if(i.se!=j.se) return(i.se>j.se);
	return(i.fi<j.fi);
}

int main()
{
	scanf("%d",&N);
	scanf("%d %d",&a,&b);
	if(a==b)
	{
		for(x=1;x<=a;x++) printf("1 ");
		for(x=1;x<=b;x++) printf("2%c",x==b?'\n':' ');
	} else
	
	{
		for(x=1;x<=N;x++)
		{
			scanf("%d",&z);
			score[x]=mp(x,z);
		}
		
		if(a>b) 
		{
			sort(score+1,score+N+1,cfa);
			for(x=1;x<=b;x++) ans[score[x].fi]=2;
			for(x=b+1;x<=N;x++) ans[score[x].fi]=1;
		} else
			
		{
			sort(score+1,score+N+1,cfb);
			for(x=1;x<=a;x++) ans[score[x].fi]=1;
			for(x=a+1;x<=N;x++) ans[score[x].fi]=2;
		}
		
		for(x=1;x<=N;x++) printf("%d%c",ans[x],x==N?'\n':' ');
	}
	return 0;
}

