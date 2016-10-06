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

int N,x,y,z,ans;
vector<int> genap,ganjil;

int main()
{
	scanf("%d",&N);
	ans=0;
	while(N--)
	{
		scanf("%d",&x);
		if(x&1) ganjil.pb(x); else genap.pb(x);
	}
	
	sort(ganjil.begin(),ganjil.end());
	ans=0;
	if(ganjil.size())
	{
		for(x=0;x<genap.size();x++) ans+=genap[x];
		for(x=0;x<ganjil.size();x++) ans+=ganjil[x];
		if(ganjil.size()%2==0) ans-=ganjil[0];
	}
	
	printf("%d\n",ans);
	return 0;
}

