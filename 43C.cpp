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

int N,sisa[4],x,y,z;

int main()
{
	scanf("%d",&N);
	memset(sisa,0,sizeof(sisa));
	while(N--)
	{
		scanf("%d",&x);
		y=0;
		while(x)
		{
			y+=(x%10);
			x/=10;
		}
		sisa[y%3]++;
	}
	printf("%d\n",sisa[0]/2+min(sisa[1],sisa[2]));
	return 0;
}

