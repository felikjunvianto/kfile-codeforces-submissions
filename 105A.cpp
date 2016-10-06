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

char msk[40];
map<string,int> skill;
int N,M,x,y,z;
double K;

int main()
{
	scanf("%d %d %lf",&N,&M,&K);
	while(N--)
	{
		scanf("%s %d",msk,&z);
		y=(int)floor((double)z*K+eps);
		if(y>=100) skill[msk]=y;
	}
	
	while(M--)
	{
		scanf("%s",msk);
		if(skill.find(msk)==skill.end()) skill[msk]=0;
	}
	
	printf("%d\n",skill.size());
	for(map<string,int>::iterator m=skill.begin();m!=skill.end();m++)
		printf("%s %d\n",m->fi.c_str(),m->se);
	return 0;
}

