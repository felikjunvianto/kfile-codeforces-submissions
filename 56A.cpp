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

string alc[]={"ABSINTH","BEER","BRANDY","CHAMPAGNE","GIN","RUM",
              "SAKE","TEQUILA","VODKA","WHISKEY","WINE"};

char msk[200];
int N,age,ans;


int main()
{
	scanf("%d",&N);
	ans=0;
	while(N--)
	{
		scanf("%s",msk);
		if((msk[0]>='0')&&(msk[0]<='9'))
		{
			sscanf(msk,"%d",&age);
			if(age<18) ans++;
		}
		
		else for(int i=0;i<11;i++) if(!strcmp(msk,alc[i].c_str()))
		{
			ans++;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}

