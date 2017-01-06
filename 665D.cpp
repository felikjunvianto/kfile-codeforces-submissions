#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int LIM = 2000010;

int prima[LIM];
int N, satuCnt;
set<int> angka;

int main()
{
	memset(prima, true, sizeof(prima));
	for(int i = 2; i * i <= LIM; i++) if(prima[i])
		for(int j = 2; i * j <= LIM; j++) prima[i * j] = false;

	scanf("%d", &N);	
	satuCnt = 0;
	for(int i = 0; i < N; i++)
	{
		int msk;
		scanf("%d", &msk);
		if(msk == 1) satuCnt++; else angka.insert(msk);
	}

	vector<int> answer;	
	if(satuCnt >= 2)
	{
		for(int i = 0; i < satuCnt; i++) answer.push_back(1);
		
		for(set<int>::iterator it = angka.begin(); it != angka.end(); it++)
			if(prima[1 + *it])
			{
				answer.push_back(*it);
				break;
			}
	} else
	{
		vector<int> toProcess;

		for(set<int>::iterator it = angka.begin(); it != angka.end(); it++) toProcess.push_back(*it);
		if(satuCnt == 1) toProcess.push_back(1);
		
		for(int i = 0; i < toProcess.size() && answer.empty(); i++)
			for(int j = i + 1; j < toProcess.size() && answer.empty(); j++)
				if(prima[toProcess[i] + toProcess[j]])
				{
					answer.push_back(toProcess[i]);
					answer.push_back(toProcess[j]);
				}
				
		if(answer.empty()) answer.push_back(toProcess[0]);
	}
	
	printf("%d\n", (int) answer.size());
	for(int i = 0; i < answer.size(); i++) printf("%d%c", answer[i], i + 1 == answer.size() ? '\n' : ' ');
	
	return 0;
}
