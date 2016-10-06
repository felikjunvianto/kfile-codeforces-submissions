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

int bawah,samping,ans,x,y,z,a,b,temp;
int sum[100][100];

int main()
{
	scanf("%d %d",&bawah,&samping);
	memset(sum,0,sizeof(sum));
	
	for(y=1;y<=bawah;y++)
		for(x=1;x<=samping;x++)
		{
			scanf("%d",&z);
			sum[x][y]=sum[x][y-1]+sum[x-1][y]+z-sum[x-1][y-1];
		}
		
	ans=INF;
	scanf("%d %d",&a,&b);
	for(z=0;z<2;z++)
	{
		swap(a,b);
		for(x=1;x+a-1<=samping;x++)
			for(y=1;y+b-1<=bawah;y++)
				ans=min(ans,sum[x+a-1][y+b-1]-sum[x-1][y+b-1]-sum[x+a-1][y-1]+sum[x-1][y-1]);
	}
	
	printf("%d\n",ans);
	return 0;
}

