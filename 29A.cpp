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

bool oke;
int N,x,y;
PII tar[111];

int main()
{
	scanf("%d",&N);
	for(x=1;x<=N;x++) scanf("%d %d",&tar[x].fi,&tar[x].se);
	
	oke=false;
	for(x=1;x<=N;x++) if(oke) break; else
		for(y=x+1;y<=N;y++) if((tar[x].fi+tar[x].se==tar[y].fi)&&(tar[y].fi+tar[y].se==tar[x].fi))
		{
			oke=true;
			break;
		}
		
	printf("%s\n",oke?"YES":"NO");
	return 0;
}

