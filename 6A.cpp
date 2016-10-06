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

int edge[10],x,y,z;
bool triang, segment;

int main()
{
	scanf("%d %d %d %d",&edge[0],&edge[1],&edge[2],&edge[3]);
	sort(edge,edge+4);
	triang=segment=false;
	for(x=0;x<4;x++)
		for(y=x+1;y<4;y++)
			for(z=y+1;z<4;z++) 
			{
				if(edge[x]+edge[y]>edge[z]) triang=true;
				if(edge[x]+edge[y]==edge[z]) segment=true;
			}
			
	if(triang) printf("TRIANGLE\n"); else
	if(segment) printf("SEGMENT\n"); else
	printf("IMPOSSIBLE\n");
	return 0;
}

