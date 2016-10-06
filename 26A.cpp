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

bool prime[3100];
vector<int> divi;
int N,ans,x,y,z;

int main()
{
	memset(prime,true,sizeof(prime));
	for(x=2;x<=3000;x++) if(prime[x])
	{
		divi.pb(x);
		z=2;
		while(x*z<=3000)
		{
			prime[x*z]=false;
			z++;
		}
	}
	
	scanf("%d",&N);
	ans=0;
	for(x=1;x<=N;x++)
	{
		z=0;
		for(y=0;(y<divi.size())&&(divi[y]<=x);y++) if(x%divi[y]==0) z++;
		if(z==2) ans++;
	}
	printf("%d\n",ans);
	return 0;
}

