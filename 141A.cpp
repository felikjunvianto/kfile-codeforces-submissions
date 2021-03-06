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
int len,x,y,hitung[30];

int main()
{
	memset(hitung,0,sizeof(hitung));
	for(x=0;x<2;x++)
	{
		scanf("%s",msk);len=strlen(msk);
		for(y=0;y<len;y++) hitung[msk[y]-'A']++;
	}
	
	scanf("%s",msk);len=strlen(msk);
	for(x=0;x<len;x++) hitung[msk[x]-'A']--;
	
	bool benar=true;
	for(x=0;x<30;x++) if(hitung[x]!=0) benar=false;
	printf("%s\n",benar?"YES":"NO");
	return 0;
}

