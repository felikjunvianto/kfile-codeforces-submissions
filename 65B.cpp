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

int N,x,y,z,beda;
char year[1111][10],now[10];

int main()
{
	scanf("%d",&N);
	for(x=1;x<=N;x++) scanf("%s",year[x]);
	
	z=N;
	for(x=2011;x>=1000;x--) 
	{
		sprintf(now,"%d",x);
		beda=0;
		for(y=0;y<5;y++) if(year[z][y]!=now[y]) beda++;
		if(beda<2) 
		{
			strcpy(year[z],now);
			z--;x++;
			if(!z) break;
		}
	}
	
	if(z) printf("No solution\n"); else
		for(x=1;x<=N;x++) printf("%s\n",year[x]);
	return 0;
}

