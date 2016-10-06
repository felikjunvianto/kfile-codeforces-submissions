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

int N,x,y,z;
int fx,fy,fz;

int main()
{
	scanf("%d",&N);
	fx=fy=fz=0;
	while(N--)
	{
		scanf("%d %d %d",&x,&y,&z);
		fx+=x,fy+=y,fz+=z;
	}
	if( !fx && !fy && !fz) printf("YES\n"); else printf("NO\n");
	return 0;
}

