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

int x,mars[5],ven[5];
bool oke;

int main()
{
	scanf("%d %d",&ven[1],&ven[0]);
	scanf("%d %d",&mars[0],&mars[1]);
	oke=false;
	for(x=0;x<2;x++) if((ven[x]-mars[x]<=1)&&(mars[x]<=(ven[x]+1)*2)) oke=true;
	printf("%s\n",oke?"YES":"NO");
	return 0;
}

