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

string ans="ABC";
char com[5][5];
int x,y,z,a,b,c;
bool dapat;

int main()
{
	for(x=0;x<3;x++) scanf("%s",com[x]);
	
	do
	{
		dapat=true;
		for(x=0;x<3;x++)
		{
			a=ans.find(com[x][0]);
			b=ans.find(com[x][2]);
			switch(com[x][1])
			{
				case('>') : if(a<b) dapat=false;break;
				case('<') : if(a>b) dapat=false;break;
			}
			if(!dapat) break;
		}
		
		if(dapat)
		{
			printf("%s\n",ans.c_str());
			break;
		}
	}while(next_permutation(ans.begin(),ans.end()));
	if(!dapat) printf("Impossible\n");
	return 0;
}

