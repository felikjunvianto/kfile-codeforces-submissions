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

PII gelas[1111];
int N,x,y,z;

int main()
{
	scanf("%d",&N);
	for(x=1;x<=N;x++)
	{
		scanf("%d",&y);
		gelas[x]=mp(y,x);
	}
	sort(gelas+1,gelas+N+1);
	
	if(gelas[1].fi==gelas[N].fi) printf("Exemplary pages.\n"); else
		switch(N)
		{
			case(2) : if((gelas[2].fi-gelas[1].fi)&1) printf("Unrecoverable configuration.\n");
						else printf("%d ml. from cup #%d to cup #%d.\n",(gelas[2].fi-gelas[1].fi)/2,
																		 gelas[1].se,gelas[2].se);
					  break;
					  
			default : if((gelas[2].fi!=gelas[N-1].fi)||(gelas[N].fi-gelas[N-1].fi!=gelas[2].fi-gelas[1].fi))
							printf("Unrecoverable configuration.\n"); else
								printf("%d ml. from cup #%d to cup #%d.\n",(gelas[2].fi-gelas[1].fi),
																			gelas[1].se,gelas[N].se);
		}
	return 0;
}

