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

PII eq[5];
int x;
double res;

int main()
{
	for(x=0;x<3;x++) scanf("%d %d",&eq[x].fi,&eq[x].se);
	if(!eq[1].se)
	{
		printf("Hermione\n");
		return 0;
	} else
	
	if(!eq[1].fi)
	{
		printf("Ron\n");
		return 0;
	}
	
	res=1.00;
	for(x=0;x<3;x++)
		if(!eq[x].se)
		{
			printf("Hermione\n");
			return 0;
		} else
		
		if(!eq[x].fi)
		{
			printf("Ron\n");
			return 0;
		} else res=(res*(double)eq[x].se)/(double)eq[x].fi;
	
	if(res>1.00) printf("Ron\n"); else printf("Hermione\n");
	return 0;
}

