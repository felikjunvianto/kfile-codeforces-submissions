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

char msk[200];
string satu, dua;

bool is_both(string s, string t)
{
	int cnt[30];
	memset(cnt, 0, sizeof(cnt));
	
	for(int i = 0; i < s.size(); i++) cnt[s[i] - 'a']++;
	for(int i = 0; i < t.size(); i++) cnt[t[i] - 'a']--;
	
	for(int i = 0; i < 30; i++) if(cnt[i] < 0) return false;
	return true;
}

bool is_array(string s, string t)
{
	int cnt[30];
	memset(cnt, 0, sizeof(cnt));
	
	for(int i = 0; i < s.size(); i++) cnt[s[i] - 'a']++;
	for(int i = 0; i < t.size(); i++) cnt[t[i] - 'a']--;
	
	for(int i = 0; i < 30; i++) if(cnt[i] != 0) return false;
	return true;
}

bool is_automaton(string s, string t)
{
	int p_t = 0;
	for(int i = 0; i < s.size() && p_t < t.size(); i++)
		if(s[i] == t[p_t]) p_t++;
		
	return p_t == (int) t.size();
}

int main()
{
	scanf("%s", msk); satu = msk;
	scanf("%s", msk); dua = msk;
	
	if(is_automaton(satu, dua)) printf("automaton\n"); else
		if(is_array(satu, dua)) printf("array\n"); else
			if(is_both(satu, dua)) printf("both\n"); else
				printf("need tree\n");
				
	return 0;
}

