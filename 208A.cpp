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

int x,y,z,len;
char msk[222];

int main()
{
	scanf("%s",msk);len=strlen(msk);
	for(x=0;x<len;x+=3) if(len-x>=2 && msk[x]=='W' && msk[x+1]=='U' && msk[x+2]=='B') continue;
		else break;
		
	for(y=len-1;y>=0;y-=3) if(y>=2 && msk[y]=='B' && msk[y-1]=='U' && msk[y-2]=='W') continue;
		else break;
		
	//cout << x << " " << y << endl;
	z=x-1;
	do
	{
		z++;
		bool spasi = false;
		while(y-z>=2 && msk[z]=='W' && msk[z+1]=='U' && msk[z+2]=='B')
		{
			spasi = true;
			z+=3;
		} if(spasi) z--;
		
		printf("%c",spasi?' ':msk[z]);
	} while(z<y);
	
	printf("\n");
	return 0;
}

