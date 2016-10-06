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

int a,b,c,d,x,len;
char temp[30];

int main()
{
	scanf("%d",&a);
	scanf("%d",&b);
	c=a+b;
	
	sprintf(temp,"%d",c);
	c=0,len=strlen(temp);
	for(x=0;x<len;x++) if(temp[x]!='0') c=c*10+(temp[x]-'0');
	
	sprintf(temp,"%d",a);
	a=0,len=strlen(temp);
	for(x=0;x<len;x++) if(temp[x]!='0') a=a*10+(temp[x]-'0');
	
	sprintf(temp,"%d",b);
	b=0,len=strlen(temp);
	for(x=0;x<len;x++) if(temp[x]!='0') b=b*10+(temp[x]-'0');
	
	printf("%s\n",a+b==c?"YES":"NO");
	return 0;
}

