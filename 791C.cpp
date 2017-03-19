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

int N, K;
char msk[55];
string namestock[] = {"A" , "B" , "C" , "D" , "E" , "F" , "G" , "H" , "I" , "J" , "K" , "L" , "M" , "N" , "O" , "P" , "Q" , "R" , "S" , "T" , "U" , "V" , "W" , "X" , "Y" , "Z" ,
							 "Aa", "Ab", "Ac", "Ad", "Ae", "Af", "Ag", "Ah", "Ai", "Aj", "Ak", "Al", "Am", "An", "Ao", "Ap", "Aq", "Ar", "As", "At", "Au", "Av", "Aw", "Ax", "Ay", "Az"};
vector<string> ans, notes;

string unik(int a, int b) {
	for(int i = 0; i < 52; i++) {
		bool oke = true;
		for(int j = a; j <= b && oke; j++)
			if(namestock[i] == ans[j]) oke = false;

		if(oke) return namestock[i];
	}

	return "ZZZZZ";
}

int main() {
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N - K + 1; i++) {
		scanf("%s", msk);
		notes.pb(msk);
	}

	for(int k = 0; k < K - 1; k++) ans.pb(namestock[k]);
	for(int i = 0; i < notes.size(); i++) {
		int head = ans.size() - K + 1;

		if(notes[i] == "NO") ans.pb(ans[head]); else {
			string baru = unik(head, ans.size() - 1);
			ans.pb(baru);
		}
	}

	for(int i = 0; i < ans.size(); i++) printf("%s%c", ans[i].c_str(), i + 1 == ans.size() ? '\n' : ' ');

	return 0;
}

