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

char a[200],b[200],len,x;

int main()
{
	scanf("%s",a);
	scanf("%s",b);
	len=strlen(a);
	for(x=0;x<len;x++) printf("%c",a[x]==b[x]?'0':'1');
	printf("\n");
	return 0;
}

