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

int N,M,a,b,leva,levb;

int main()
{
	scanf("%d %d %d %d",&N,&M,&a,&b);
	leva=a/M;if(a%M) leva++;
	levb=b/M;if(b%M) levb++;
	
	if(leva==levb) printf("1\n"); else
	if(M==1) printf("1\n"); else
	if((a%M==1)&&(b%M==0)) printf("1\n"); else
	if((a%M==1)&&(b==N)) printf("1\n"); else
	if(b==N) printf("2\n"); else
	if((a%M==1)||(b%M==0)) printf("2\n"); else
	if((M*leva-a+1)+(b-M*(levb-1))==M) printf("2\n"); else
	if(levb-leva==1) printf("2\n"); else printf("3\n");
	return 0;
}

