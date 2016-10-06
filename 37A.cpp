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

int N,arr[1010];
int x,y,z,ans,tot;

int main()
{
	scanf("%d",&N);
	for(x=0;x<N;x++) scanf("%d",&arr[x]);
	sort(arr,arr+N);
	ans=tot=0;
	x=-1;
	do
	{
		x++;
		y=x;
		while((arr[x]==arr[y])&&(y<N)) y++;y--;
		tot++;
		ans=max(ans,y-x+1);
		x=y;
	}while(x+1<N);
	printf("%d %d\n",ans,tot);
	return 0;
}

