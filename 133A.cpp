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

char msk[111];
int x,len;
bool oke;

int main()
{
	scanf("%s",msk);len=strlen(msk);
	oke=false;
	for(x=0;x<len;x++)
		if((msk[x]=='H')||(msk[x]=='Q')||(msk[x]=='9')) oke=true;
		
	printf("%s\n",oke?"YES":"NO");
	return 0;
}

