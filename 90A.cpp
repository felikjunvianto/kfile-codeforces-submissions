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

int orang[5];
int x,ans;

int main()
{
	scanf("%d %d %d",&orang[0],&orang[1],&orang[2]);
	ans=x=-1;
	while(orang[0]+orang[1]+orang[2])
	{
		ans++;
		x=(x+1)%3;
		orang[x]-=min(2,orang[x]);
	}
	printf("%d\n",ans+30);
	return 0;
}

