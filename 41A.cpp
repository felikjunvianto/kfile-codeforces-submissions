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

char a[200],b[200];
int x,len;
bool oke;

int main()
{
	scanf("%s",a);len=strlen(a);
	scanf("%s",b);
	oke=true;
	for(x=0;(x<len)&&oke;x++) if(a[x]!=b[len-x-1]) oke=false;
	printf("%s\n",oke?"YES":"NO");
	return 0;
}

