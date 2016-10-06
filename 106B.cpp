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

typedef struct
{
	int a,b,c,price;
} bar;

bar comp[111];
int N,x,y;
bool valid[111];

int main()
{
	scanf("%d",&N);
	for(x=1;x<=N;x++) scanf("%d %d %d %d",&comp[x].a,&comp[x].b,&comp[x].c,&comp[x].price);
	memset(valid,true,sizeof(valid));
	for(x=1;x<=N;x++)
		for(y=1;y<=N;y++) if((y!=x)&&(valid[y]))
			if((comp[y].a>comp[x].a)&&(comp[y].b>comp[x].b)&&(comp[y].c>comp[x].c))
			{
				valid[x]=false;
				break;
			}
			
	x=0;
	for(y=1;y<=N;y++) if(valid[y])
		if((!x)||(comp[x].price>comp[y].price)) x=y;
		
	printf("%d\n",x);
	return 0;
}

