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

string idx[]={"rock","scissors","paper"};
int id[3],x,y;
char ans[4][4][4],msk[10];

int main()
{
	memset(ans,'?',sizeof(ans));
	ans[0][1][1]=ans[1][2][2]=ans[2][0][0]='F';
	ans[1][0][1]=ans[2][1][2]=ans[0][2][0]='M';
	ans[1][1][0]=ans[2][2][1]=ans[0][0][2]='S';
	for(x=0;x<3;x++)
	{
		scanf("%s",msk);
		for(y=0;y<3;y++) if(!strcmp(msk,idx[y].c_str())) break;
		id[x]=y;
	}
	printf("%c\n",ans[id[0]][id[1]][id[2]]);
	return 0;
}

