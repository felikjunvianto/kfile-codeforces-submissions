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

bool dapat,oke[12010];
int bts=6000;
int N,T,x,y,z,a,ans;

int main()
{
	memset(oke,true,sizeof(oke));
	scanf("%d %d",&N,&T);T*=2;
	while(N--)
	{
		scanf("%d %d",&x,&a);x=(x*2)+bts;
		for(y=x-a;y<=x+a;y++) oke[y]=false;
	}
	
	ans=0;
	for(y=3000;y<=9000;y++)
		if((!oke[y])&&(oke[y-1]))
		{
			dapat=true;
			for(x=1;x<T;x++) if(!oke[y-x]) dapat=false;
			if(dapat) ans++;
		} else
		
		if((!oke[y])&&(oke[y+1]))
		{
			dapat=true;
			for(x=1;x<T;x++) if(!oke[y+x]) dapat=false;
			if(dapat) ans++,y+=T;
		}
		
	printf("%d\n",ans);
	return 0;
}

