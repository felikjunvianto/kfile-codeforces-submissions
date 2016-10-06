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
#define ULL unsigned long long
#define INF 1000000000

using namespace std;

bool prime[1010];
int x,y,z,N;
vector<int> bil;
int temp[155];

void kali(int T)
{
	int num,i=-1,j,carry=0;
	int result[155];
	memset(result,0,sizeof(result));
	while(T)
	{
		i++;
		num=T%10;T/=10;
		for(j=0;j+i<155;j++) 
		{
			result[i+j]+=temp[j]*num+carry;
			//cout << i << " " << j << " " << result[i+j] << endl;
			carry=result[i+j]/10;
			result[i+j]%=10;
		}
	}
	for(j=0;j<155;j++) temp[j]=result[j];
}

void bagi(int T)
{
	int i,j,now=0;
	vector<int> ans;
	for(j=154;j>=0;j--) if(temp[j]) break;
	for(i=j;i>=0;i--)
	{
		now=now*10+temp[i];
		ans.pb(now/T);
		now%=T;
	}
	
	for(i=0;i<ans.size();i++) if(ans[i]) break;
	memset(temp,0,sizeof(temp));
	for(j=ans.size()-1;j>=i;j--) temp[ans.size()-j-1]=ans[j];
}

int main()
{
	memset(prime,true,sizeof(prime));
	for(x=2;x<=1000;x++) if(prime[x])
	{
		bil.pb(x);
		z=2;
		while(x*z<=1000)
		{
			prime[x*z]=false;
			z++;
		}
	}
	
	scanf("%d",&N);
	if(N==2)
	{
		printf("-1\n");
		return 0;
	}
	
	memset(temp,0,sizeof(temp));temp[0]=1;
	for(x=0;x+1<N;x++) kali(bil[x]);
	for(x=0;x<N;x++)
	{
		for(y=154;y>=0;y--) if(temp[y]) break;
		for(z=y;z>=0;z--) printf("%d",temp[z]);printf("\n");
		bagi(bil[x]);
		kali(bil[(x+N-1)%N]);
	}
	return 0;
}

