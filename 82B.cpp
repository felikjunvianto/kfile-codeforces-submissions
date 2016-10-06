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

using namespace std;

int cari[]={5,3,2};
int N,x,y,z;
vector<vector<int> > setset,ans;
vector<int> temp;
int cnt[300];
bool udah[300];

int main()
{
	scanf("%d",&N);
	for(x=1;2*x<=N*(N-1);x++)
	{
		scanf("%d",&z);
		temp.clear();
		while(z--)
		{
			scanf("%d",&y);
			temp.pb(y);
		}
		sort(temp.begin(),temp.end());
		setset.pb(temp);
	}
	
	sort(setset.begin(),setset.end());
	if(N==2)
	{
		sort(setset[0].begin(),setset[0].end());
		temp.clear();
		for(x=0;2*x<setset[0].size();x++) temp.pb(setset[0][x]);
		ans.pb(temp);
		
		temp.clear();
		int bts=(int)setset[0].size()/2+(int)setset[0].size()%2;
		for(x=bts;x<setset[0].size();x++) temp.pb(setset[0][x]);
		ans.pb(temp);
	}
	
	else
	{
		memset(udah,false,sizeof(udah));
		for(x=0;(x<setset.size())&&(ans.size()<N);x++)
			for(y=x+1;(y<setset.size())&&(ans.size()<N);y++)
			{
				memset(cnt,0,sizeof(cnt));
				for(z=0;z<setset[x].size();z++) if(!udah[setset[x][z]]) cnt[setset[x][z]]+=3;
				for(z=0;z<setset[y].size();z++) if(!udah[setset[y][z]]) cnt[setset[y][z]]+=2;
				
				for(int i=0;i<3;i++)
				{
					temp.clear();
					for(z=1;z<=200;z++) if((!udah[z])&&(cnt[z]==cari[i]))
					{
						udah[z]=true;
						temp.pb(z);
					}
				
					if(!temp.empty()) ans.pb(temp);
				}
			}
	}
	
	for(x=0;x<ans.size();x++)
	{
		printf("%d",(int)ans[x].size());
		for(y=0;y<ans[x].size();y++) printf(" %d",ans[x][y]);
		printf("\n");
	}
	return 0;
}

