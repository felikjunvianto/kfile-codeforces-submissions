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

int ans,N,L,maks,x,y,z,k;
int arr[111];

int main()
{
	scanf("%d %d",&N,&L);
	ans=maks=0;
	for(x=0;x<N;x++)
	{
		scanf("%d",&arr[x]);
		maks=max(maks,arr[x]);
	}
	
	for(z=L;z<=maks;z++)
	{
		k=0;
		for(x=0;x<N;x++) k+=arr[x]/z;
		ans=max(ans,k*z);
	}
	
	printf("%d\n",ans);
	return 0;
}

