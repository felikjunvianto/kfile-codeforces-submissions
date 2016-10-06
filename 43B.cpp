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

int score[]={1,-1};
int cnt[60],x,y,z,len;
char msk[300];

int main()
{
	memset(cnt,0,sizeof(cnt));
	for(y=0;y<2;y++)
	{
		gets(msk);len=strlen(msk);
		for(x=0;x<len;x++) if(msk[x]!=' ')
		{
			if((msk[x]>='A')&&(msk[x]<='Z')) z=msk[x]-'A'; else z=26+msk[x]-'a';
			cnt[z]+=score[y];
		}
	}
	
	bool oke=true;
	for(x=0;x<60;x++) if(cnt[x]<0) oke=false;
	printf("%s\n",oke?"YES":"NO");
	return 0;
}

