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

string nada[]={"C","C#","D","D#","E","F","F#","G","G#","A","B","H"};
vector<string> tes;
char msk[5];
int x,y,z,nilai[5];
bool tambah;

int main()
{
	for(x=0;x<3;x++) 
	{
		scanf("%s",msk);
		tes.pb(msk);
	}
	
	sort(tes.begin(),tes.end());
	do
	{
		//for(x=0;x<3;x++) printf("%s ",tes[x].c_str());printf("\n");
		for(x=0;x<12;x++) if(tes[0]==nada[x]) break;nilai[0]=x;
		z=0;
		while(1)
		{
			z++;
			y=(x+z)%12;
			if(tes[1]==nada[y])
			{
				tambah=true;
				nilai[1]=x+z;
				break;
			}
		
			y=x-z; while(y<0) y+=12;
			if(tes[1]==nada[y])
			{
				tambah=false;
				nilai[1]=x-z;
				break;
			}
		}
			
		y=nilai[1];
		if(tambah) while(1)
		{
			y++;
			if(tes[2]==nada[y%12])
			{
				nilai[2]=y;
				break;
			}
		}
		
		else while(1)
		{
			y--;z=y;while(z<0) z+=12;
			if(tes[2]==nada[z])
			{
				nilai[2]=y;
				break;
			}
		}
		
		if((nilai[1]-nilai[0]==4)&&(nilai[2]-nilai[0]==7))
		{
			printf("major\n");
			return 0;
		} else
		
		if((nilai[1]-nilai[0]==3)&&(nilai[2]-nilai[0]==7))
		{
			printf("minor\n");
			return 0;
		}
	}while(next_permutation(tes.begin(),tes.end()));
	printf("strange\n");
	return 0;
}

