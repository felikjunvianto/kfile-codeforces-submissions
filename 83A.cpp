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

int N,x,y,z,arr[100100];
LL ans;

int main()
{
	scanf("%d",&N);
	for(x=0;x<N;x++) scanf("%d",&arr[x]);
	
	ans=0LL;
	x=-1;
	do
	{
		x++;y=x;
		while((y<N)&&(arr[y]==arr[x])) y++;
		
		z=y-x;
		ans+=(LL)z*(z+1)/2;
		x=y-1;
	}while(x+1<N);
	printf("%I64d\n",ans);
	return 0;
}

