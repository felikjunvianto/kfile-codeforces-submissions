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

bool prime[100];
vector<int> bil;
int x,y,z;

int main()
{
	memset(prime,true,sizeof(prime));
	prime[1]=false;
	for(x=2;x<=50;x++) if(prime[x])
	{
		z=2;
		bil.pb(x);
		while(x*z<=50)
		{
			prime[x*z]=false;
			z++;
		}
	}
	
	scanf("%d %d",&x,&y);
	z=lower_bound(bil.begin(),bil.end(),x)-bil.begin();
	if((z+1==bil.size())||(bil[z+1]!=y)) printf("NO\n"); else printf("YES\n");
	return 0;
}

