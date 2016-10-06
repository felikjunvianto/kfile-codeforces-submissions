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

string kuran[]={"S","M","L","XL","XXL"};
int sup[10];
int N,x,y,z;
char msk[8];

int main()
{
	for(x=0;x<5;x++) scanf("%d",&sup[x]);
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",msk);
		for(x=0;x<5;x++) if(!strcmp(msk,kuran[x].c_str())) break;
		for(y=0;y<5;y++)
		{
			if((x+y<5)&&(sup[x+y]))
			{
				sup[x+y]--;
				printf("%s\n",kuran[x+y].c_str());
				break;
			}
			
			if((x-y>=0)&&(sup[x-y]))
			{
				sup[x-y]--;
				printf("%s\n",kuran[x-y].c_str());
				break;
			}
		}
	}
	return 0;
}

