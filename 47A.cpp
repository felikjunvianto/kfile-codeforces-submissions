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

bool tri[600];
int N,x,y;

int main()
{
	x=0,y=1;
	memset(tri,false,sizeof(tri));
	while(x+y<=500)
	{
		x+=y;
		tri[x]=true;
		y++;
	}
	
	scanf("%d",&N);
	printf("%s\n",tri[N]?"YES":"NO");
	return 0;
}

