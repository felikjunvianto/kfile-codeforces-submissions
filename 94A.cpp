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

char msk[100];
string asal,temp[15];
int x,y,z;

int main()
{
	scanf("%s",msk);
	asal=msk;
	for(x=0;x<10;x++)
	{
		scanf("%s",msk);
		temp[x]=msk;
	}
	
	while(asal.size()!=0)
		for(x=0;x<10;x++) if(asal.find(temp[x])==0)
		{
			printf("%d",x);
			asal.erase(0,10);
			break;
		}
		
	printf("\n");
	return 0;
}

