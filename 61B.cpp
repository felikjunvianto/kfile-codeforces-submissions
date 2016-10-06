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

int permut[]={0,1,2};
vector<string> awal,ans;
string temp;
char msk[700];
int N,x,y,z,len;

int main()
{
	for(x=0;x<3;x++)
	{
		scanf("%s",msk);len=strlen(msk);
		temp.clear();
		for(y=0;y<len;y++)
		{
			if((msk[y]>='A')&&(msk[y]<='Z')) msk[y]^=32;
			if((msk[y]>='a')&&(msk[y]<='z')) temp.pb(msk[y]);
		}
		awal.pb(temp);
	}
	
	do
	{
		ans.pb(awal[permut[0]]+awal[permut[1]]+awal[permut[2]]);
	}while(next_permutation(permut,permut+3));
	
	scanf("%d",&N);
	while(N--)
	{
		scanf("%s",msk);len=strlen(msk);
		temp.clear();
		temp.clear();
		for(y=0;y<len;y++)
		{
			if((msk[y]>='A')&&(msk[y]<='Z')) msk[y]^=32;
			if((msk[y]>='a')&&(msk[y]<='z')) temp.pb(msk[y]);
		}
		
		bool sama=false;
		for(x=0;x<6;x++) if(temp==ans[x]) sama=true;
		printf("%s\n",sama?"ACC":"WA");
	}
	return 0;
}

