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

int besar,kecil,x,len;
char msk[200];

int main()
{
	scanf("%s",msk);len=strlen(msk);
	besar=kecil=0;
	for(x=0;x<len;x++) if((msk[x]>='a')&&(msk[x]<='z')) kecil++; else besar++;
	if(besar>kecil)
	{
		for(x=0;x<len;x++) if((msk[x]>='a')&&(msk[x]<='z')) msk[x]^=32;
	} else
	{
		for(x=0;x<len;x++) if((msk[x]>='A')&&(msk[x]<='Z')) msk[x]^=32;
	}
	
	printf("%s\n",msk);
	return 0;
}

