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

int N,stow,cont,x,y,z,arah,len;
char msk[300];

int main()
{
	scanf("%d %d %d",&N,&stow,&cont);getchar();
	gets(msk);if(!strcmp(msk,"to head")) arah=-1; else arah=1;
	scanf("%s",msk);len=strlen(msk);
	
	for(x=0;x<len;x++) if(x+1==len)
	{
		printf("Stowaway\n");
		break;
	} else 
	
	{
		switch(msk[x])
		{
			case('0') : if((stow<cont)&&(stow>1)) stow--; else
						if((stow>cont)&&(stow<N)) stow++;
						
						if((cont+arah<1)||(cont+arah>N)) arah*=-1;
						cont+=arah;
						break;
						
			case('1') : if((cont+arah<1)||(cont+arah>N)) arah*=-1;
						cont+=arah;
						
						if(arah==1) stow=1; else stow=N;
						break;
		}
		
		if(stow==cont)
		{
			printf("Controller %d\n",x+1);
			break;
		}
	}
	return 0;
}

