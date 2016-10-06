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

int dx[] = { 0, 0, 1, 1, 1, 0,-1,-1,-1};
int dy[] = { 0, 1, 1, 0,-1,-1,-1, 0, 1};

int val[1010][1010];
int N,M,x,y,i;
int ans;

int main()
{
	scanf("%d %d",&N,&M);
	ans = -1;
	i = 0;
	
	memset(val,0,sizeof(val));
	while(M--)
	{
		i++;
		scanf("%d %d",&x,&y);
		for(int j=0;j<9 && ans==-1;j++)
		{
			int sx = x + dx[j], sy = y + dy[j];
			if(sx>0 && sy>0 && sx<=N && sy<=N)
			{
				val[sx][sy]++;
				if(val[sx][sy]==9) ans = i;
			}
		}
		
		/*for(int a = 1;a<=N;a++)	
			for(int b=1;b<=N;b++)
				printf("%d%c",val[b][a],b==N?'\n':' ');
		printf("=======\n");*/
		
		if(ans!=-1) break;
	}
	
	printf("%d\n",ans);
	return 0;
}

