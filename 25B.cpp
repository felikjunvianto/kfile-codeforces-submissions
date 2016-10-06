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

int x,y,len;
char msk[110];

int main()
{
	scanf("%d",&len);
	scanf("%s",msk);
	
	switch(len%3)
	{
		case(0):printf("%c%c%c",msk[0],msk[1],msk[2]);
				for(x=3;x<len;x+=3) printf("-%c%c%c",msk[x],msk[x+1],msk[x+2]);
				printf("\n");
				break;
				
		case(1):printf("%c%c",msk[0],msk[1]);
				for(x=2;x+3<len;x+=3) printf("-%c%c%c",msk[x],msk[x+1],msk[x+2]);
				printf("-%c%c\n",msk[len-2],msk[len-1]);
				break;
				
		case(2):printf("%c%c",msk[0],msk[1]);
				for(x=2;x<len;x+=3) printf("-%c%c%c",msk[x],msk[x+1],msk[x+2]);
				printf("\n");
				break;
	}
	
	return 0;
}

