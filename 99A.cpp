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

char msk[1200];
int x,y,z,len;
bool carry;

int main()
{
	scanf("%s",msk);len=strlen(msk);
	for(z=0;z<len;z++) if(msk[z]=='.') break;
	
	if(msk[z-1]=='9') printf("GOTO Vasilisa.\n"); else
	{
		carry=false;
		if(msk[z+1]>='5') carry=true;
		for(x=z-1;(x>=0)&&(carry);x--)
			if(msk[x]=='9') msk[x]='0'; else
			{
				msk[x]++;
				carry=false;
			}
		
		for(x=0;x<z;x++) printf("%c",msk[x]);
		printf("\n");
	}
	return 0;
}

