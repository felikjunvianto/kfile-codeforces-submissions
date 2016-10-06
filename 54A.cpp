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

int N,K,C,x,y,ans;
bool holi[400];

int main()
{
	scanf("%d %d",&N,&K);
	memset(holi,false,sizeof(holi));
	scanf("%d",&C);
	while(C--)
	{
		scanf("%d",&x);
		holi[x]=true;
	}
	
	x=ans=0;
	while(x<N)
	{
		bool ada=false;
		for(y=1;y<=K;y++) if(holi[x+y]) 
		{
			ada=true;
			break;
		}
		
		if(!ada) x+=K; else x+=y;
		if(x<=N) ans++;
	}
	
	printf("%d\n",ans);
	return 0;
}

