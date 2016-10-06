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

int N,x,y,z,maks;
char msk[50];
pair<string,int> prog[1010];
map<string,int> score;

int main()
{
	scanf("%d",&N);
	
	for(z=0;z<N;z++)
	{
		scanf("%s %d",msk,&x);
		if(score.find(msk)==score.end()) score[msk]=0; 
		score[msk]+=x;
		
		prog[z]=mp(msk,score[msk]);
	}
	
	maks=-INF;
	for(map<string,int>::iterator m=score.begin();m!=score.end();m++) maks=max(maks,m->se);
	for(x=0;x<N;x++) if((prog[x].se>=maks)&&(score[prog[x].fi]==maks)) break;

	printf("%s\n",prog[x].fi.c_str());
	return 0;
}

