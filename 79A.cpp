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

int X,Y,now,i;
PII conf[2][3]={{mp(2,2),mp(1,12),mp(0,22)},
				{mp(0,22),mp(1,12),mp(2,2)}};

int main()
{
	scanf("%d %d",&X,&Y);
	now=1;
	while(1)
	{
		now^=1;
		bool dapat=false;
		for(i=0;i<3;i++) if((conf[now][i].fi<=X)&&(conf[now][i].se<=Y))
		{
			dapat=true;
			X-=conf[now][i].fi;
			Y-=conf[now][i].se;
			break;
		}
		if(!dapat) break;
	}
	
	printf("%s\n",now?"Ciel":"Hanako");
	return 0;
}

