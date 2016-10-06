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

char msk[1010];
vector<string> kata;
int x,y,z,len,maks;
bool kiri;

int main()
{
	maks=0;
	while(gets(msk))
	{
		len=strlen(msk);
		maks=max(len,maks);
		kata.pb(msk);
	}
	
	kiri=true;
	for(x=0;x<maks+2;x++) printf("*");printf("\n");
	for(x=0;x<kata.size();x++)
	{
		printf("*");
		z=maks-(int)kata[x].size();
		
		if(z&1)
		{
			int left=z/2; if(!kiri) left++;
			for(y=0;y<left;y++) printf(" ");
			printf("%s",kata[x].c_str());
			for(y=0;y<z-left;y++) printf(" ");
			kiri^=1;
		} else
		{
			for(y=0;2*y<z;y++) printf(" ");
			printf("%s",kata[x].c_str());
			for(y=0;2*y<z;y++) printf(" ");
		}
		printf("*\n");
	}
	for(x=0;x<maks+2;x++) printf("*");printf("\n");
	return 0;
}

