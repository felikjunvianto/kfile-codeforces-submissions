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

typedef struct
{
	int prior,num;
	string nama;
} man;

int N,x,y,z;
char msk[20],job[20];
man crew[200];

bool cf(man i,man j)
{
	if(i.prior!=j.prior) return(i.prior<j.prior);
	return(i.num<j.num);
}

int main()
{
	scanf("%d",&N);
	for(x=0;x<N;x++)
	{
		scanf("%s %s",msk,job);
		if(!strcmp(job,"rat")) z=0; else
		if(!strcmp(job,"man")) z=2; else
		if(!strcmp(job,"captain")) z=3; else z=1;
		crew[x]=(man){z,x,msk};
	}
	
	sort(crew,crew+N,cf);
	for(x=0;x<N;x++) printf("%s\n",crew[x].nama.c_str());
	return 0;
}

