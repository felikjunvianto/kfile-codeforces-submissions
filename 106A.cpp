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

char nilai[]={'6','7','8','9','T','J','Q','K','A'};
char trump[5],satu[5],dua[5];
int x,y;
bool ans;

int main()
{
	scanf("%s",trump);
	scanf("%s %s",satu,dua);
	
	ans=false;
	if((satu[1]==trump[0])&&(dua[1]!=trump[0])) ans=true; 
		else if(satu[1]==dua[1])
		{
			for(x=0;x<9;x++) if(satu[0]==nilai[x]) break;
			for(y=0;y<9;y++) if(dua[0]==nilai[y]) break;
			if(x>y) ans=true;
		}
		
	printf("%s\n",ans?"YES":"NO");
	return 0;
}

