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

int N,x,y,z;
int first[111],second[111];
char msk[200];
bool besar,kecil;

int main()
{
	scanf("%d",&N);
	scanf("%s",msk);
	
	for(x=0;x<N;x++) first[x]=msk[x]-'0';
	for(x=0;x<N;x++) second[x]=msk[x+N]-'0';
	
	sort(first,first+N);
	sort(second,second+N);
	
	besar=kecil=true;
	for(x=0;x<N;x++) if(first[x]>=second[x])
	{
		kecil=false;
		break;
	}
	
	for(x=0;x<N;x++) if(first[x]<=second[x])
	{
		besar=false;
		break;
	}
	
	if(besar^kecil) printf("YES\n"); else printf("NO\n");
	printf("\n");
	return 0;
}

