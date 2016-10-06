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

int T,x,y,z,len,tipe,num;
char msk[2000];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",msk);len=strlen(msk);
		tipe=1;
		if(msk[0]=='R')
		{
			tipe=2;
			for(z=0;z<len;z++) if(msk[z]=='C') break;
			if((z==1)||(z==len)) tipe=1;
			for(x=1;x<len;x++) if(x!=z) if((msk[x]<'0')||(msk[x]>'9')) tipe=1;
		}
		
		switch(tipe)
		{
			case(1) : num=0;
					  for(z=0;z<len;z++) if((msk[z]>='0')&&(msk[z]<='9')) break;
					  for(x=0;x<z;x++) num=num*26+(msk[x]-'A'+1);
					  printf("R");for(x=z;x<len;x++) printf("%c",msk[x]);
					  printf("C%d\n",num);
					  break;
			
			case(2) : num=0;
					  for(x=z+1;x<len;x++) num=num*10+(msk[x]-'0');
					  string temp="";
					  while(num)
					  {
						  if(num%26)
						  {
								y=num%26;
								num/=26;
						  } else
						  
						  {
								y=26;
								num/=26;num--;
						  }
						  temp=(char)(y+'A'-1)+temp;
					  } 
					  
					  printf("%s",temp.c_str());
					  for(x=1;x<z;x++) printf("%c",msk[x]);printf("\n");
					  break;
		}
	}
	return 0;
}

