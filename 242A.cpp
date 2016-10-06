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

int A, B, X, Y;
int i, j;
vector<PII> comb;

int main()
{
	scanf("%d %d %d %d",&X, &Y, &A, &B);
	for(i = A; i <= X; i++)
		for(j = B; j <= Y; j++) if(i > j)
			comb.pb(mp(i,j));
			
	printf("%d\n",(int)comb.size());
	for(i=0;i<comb.size();i++) printf("%d %d\n",comb[i].fi, comb[i].se);
	return 0;
}

