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

vector<int> asli,permut;
int x,y,z,a,b,tot,ans;

int main()
{
	for(x=0;x<4;x++)
	{
		scanf("%d",&a);
		asli.pb(a);
	}
	sort(asli.begin(),asli.end());
	scanf("%d %d",&a,&b);
	
	ans=0;
	for(x=a;x<=b;x++)
	{
		tot=0;
		permut=asli;
		do
		{
			y=x;
			for(z=0;z<4;z++) y%=permut[z];
			if(x==y) tot++;
		}while(next_permutation(permut.begin(),permut.end()));
		if(tot>=7) ans++;
	}
	printf("%d\n",ans);
	return 0;
}

