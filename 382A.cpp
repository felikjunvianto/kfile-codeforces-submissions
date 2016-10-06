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

char timbangan[100], sisa[100];
int lentim, lenkiri, lenkanan, lensisa;

int main()
{
	scanf("%s", timbangan); lentim = strlen(timbangan);
	for(int i = 0; i < lentim; i++)
		if(timbangan[i] == '|') 
		{
			lenkiri = i;
			lenkanan = lentim - i - 1;
			break;
		}
		
	scanf("%s", sisa); lensisa = strlen(sisa);
	int diff = abs(lenkiri - lenkanan);
	if(diff > lensisa) printf("Impossible\n"); else
		if((lensisa - diff) & 1) printf("Impossible\n"); else
		{
			int bagi = (lensisa - diff) >> 1;
			
			string akhirkiri, akhirkanan;
			for(int i = 0; i < lenkiri; i++) akhirkiri += timbangan[i];
			for(int i = lenkiri + 1; i < lentim; i++) akhirkanan += timbangan[i];
			
			if(akhirkiri.size() < akhirkanan.size())
			{
				for(int i = 0; i < diff; i++) akhirkiri += sisa[i];
			}
			else
				for(int i = 0; i < diff; i++) akhirkanan += sisa[i];
			
			for(int i = diff; i < diff + bagi; i++) akhirkiri += sisa[i];
			for(int i = diff + bagi; i < lensisa; i++) akhirkanan += sisa[i];
			
			printf("%s|%s\n", akhirkiri.c_str(), akhirkanan.c_str());
		}
	
	return 0;
}

