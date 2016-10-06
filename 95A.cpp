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

int N,x,y,z,len;
bool besar[111];
vector<string> forbid;
string ans;
char msk[111],lucky[2];

bool cocok(int x,int y)
{
	if(x+(int)forbid[y].size()-1>=len) return(false);
	for(int i=0;i<forbid[y].size();i++) if(msk[x+i]!=forbid[y][i]) return(false);
	return(true);
}

int main()
{
	scanf("%d",&N);
	for(x=0;x<N;x++)
	{
		scanf("%s",msk);
		forbid.pb(msk);
		for(y=0;y<forbid[x].size();y++) 
			if((forbid[x][y]>='A')&&(forbid[x][y]<='Z')) forbid[x][y]^=32;
	}
	
	scanf("%s",msk);len=strlen(msk);
	scanf("%s",lucky); if((lucky[0]>='A')&&(lucky[0]<='Z')) lucky[0]^=32;
	memset(besar,false,sizeof(besar));
	for(x=0;x<len;x++) if((msk[x]>='A')&&(msk[x]<='Z')) 
	{
		msk[x]^=32;
		besar[x]=true;
	}
	ans=msk;
	
	x=-1;
	do
	{
		x++;
		for(y=0;y<N;y++) if(cocok(x,y))
		{
			for(z=x;z-x<forbid[y].size();z++) if(msk[z]==lucky[0])
			{
				if(lucky[0]=='a') ans[z]='b'; else ans[z]='a';
			} else ans[z]=lucky[0];
		}
	}while(x+1<len);
	for(x=0;x<len;x++) if(besar[x]) printf("%c",ans[x]^32); else printf("%c",ans[x]);
	printf("\n");
	return 0;
}

