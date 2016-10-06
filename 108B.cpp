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

int N,x,y,num[100100];
vector<int> asli;

int main()
{
	scanf("%d",&N);
	for(x=0;x<N;x++) scanf("%d",&num[x]);
	sort(num,num+N);
	x=-1;
	do
	{
		x++;y=x;
		while((y<N)&&(num[y]==num[x])) y++;
		asli.pb(num[x]);
		x=y-1;
	}while(x+1<N);
	
	bool oke=true;
	for(x=0;x+1<asli.size();x++) if(2*asli[x]>asli[x+1]) oke=false;
	printf("%s\n",oke?"NO":"YES");
	return 0;
}

