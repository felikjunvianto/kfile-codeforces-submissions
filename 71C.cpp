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

bool bisa,stat[100100];
vector<int> bil;
int N,x,y,z;

int main()
{
	scanf("%d",&N);
	for(x=0;x<N;x++) scanf("%d",&stat[x]);
	
	for(x=1;x*x<=N;x++) if(N%x==0)
	{
		if(x>2) bil.pb(x);
		if(x*x!=N) bil.pb(N/x);
	}
	
	bisa=false;
	for(x=0;x<bil.size();x++) if(bisa) break; else
		for(y=0;y<N/bil[x];y++)
		{
			bisa=true;
			z=y;
			for(int i=0;i<bil[x];i++)
			{
				if(!stat[z])
				{
					bisa=false;
					break;
				}
				z=(z+(int)N/bil[x])%N;
			}
			if(bisa) break;
		}
		
	printf("%s\n",bisa?"YES":"NO");
	return 0;
}

