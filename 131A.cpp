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
int len,x,y,z;
bool caps;

int main()
{
	scanf("%s",msk);len=strlen(msk);
	caps=true;
	for(x=1;x<len;x++) if((msk[x]<'A')||(msk[x]>'Z'))
	{
		caps=false;
		break;
	}
	
	if(caps) for(x=0;x<len;x++) msk[x]^=32;
	printf("%s\n",msk);
	return 0;
}

