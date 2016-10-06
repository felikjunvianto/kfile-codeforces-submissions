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

int ans[]={5,7,5};
char msk[200];
int x,y,z,len;
bool oke;

int main()
{
	oke=true;
	for(x=0;x<3;x++)
	{
		gets(msk);len=strlen(msk);
		z=0;
		for(y=0;y<len;y++) if((msk[y]=='a')||(msk[y]=='i')||(msk[y]=='u')||(msk[y]=='e')||(msk[y]=='o')) z++;
		if(z!=ans[x]) oke=false;
	}
	printf("%s\n",oke?"YES":"NO");
	return 0;
}

