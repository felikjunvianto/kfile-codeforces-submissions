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

string crop[]={"Grapes","Carrots","Kiwis"};
int bawah,samping,K,Q,x,y,z,ans;
PII waste[1010];

int main()
{
	scanf("%d %d %d %d",&bawah,&samping,&K,&Q);
	for(z=0;z<K;z++) scanf("%d %d",&waste[z].fi,&waste[z].se);
	sort(waste,waste+K);
	while(Q--)
	{
		scanf("%d %d",&y,&x);
		ans=(y-1)*samping+x;
		bool gaada=false;
		for(z=0;z<K;z++)
		{
			if(waste[z].fi>y) break;
			if((waste[z].fi==y)&&(waste[z].se>x)) break;
			if((waste[z].fi==y)&&(waste[z].se==x))
			{
				gaada=true;
				break;
			}
			ans--;
		}

		printf("%s\n",gaada?"Waste":crop[ans%3].c_str());
	}
	return 0;
}

