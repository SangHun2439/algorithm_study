#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = 0;
	vector<bool>	stud(n, true);

	for (vector<int>::iterator it = lost.begin(); it != lost.end(); it++)
		stud[*it - 1] = false;
	for (vector<int>::iterator it = reserve.begin(); it != reserve.end();)
	{
		if (!stud[*it - 1])
		{
			stud[*it - 1] = true;
			it = reserve.erase(it);
		}
		else
			it++;
	}
	sort(reserve.begin(), reserve.end());
	for (vector<int>::iterator it = reserve.begin(); it != reserve.end(); it++)
	{
		if (*it != 1 && !stud[*it - 2])
			stud[*it - 2] = true;
		else if (*it != 30 && !stud[*it])
			stud[*it] = true;
	}
	for (vector<bool>::iterator it = stud.begin(); it != stud.end(); it++)
	{
		if (*it)
			answer++;
	}
	return answer;
}

int main()
{
	vector<int>	lost(2);
	lost[0] = 2;
	lost[1] = 4;
	vector<int>	reserve(1);
	reserve[0] = 2;
	// reserve[1] = 3;
	// reserve[2] = 1;
	cout << solution(5, lost, reserve) << endl;
}
