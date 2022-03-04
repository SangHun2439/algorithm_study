#include <string>
#include <vector>
#include <iostream>

using namespace std;

void	do_solution(int n, vector<vector<int> > computers, int start, vector<bool>& visit)
{
	visit[start] = true;
	vector<int>	now = computers[start];
	for (int i = 0; i < n; i++)
	{
		if (now[i] == 1 && !visit[i])
			do_solution(n, computers, i, visit);
	}
}

int solution(int n, vector<vector<int> > computers)
{
	int answer = 0;
	vector<bool>	visit(n, false);

	for (int i = 0; i < n; i++)
	{
		if (!visit[i])
		{
			answer++;
			do_solution(n, computers, i, visit);
		}
	}
	return answer;
}

int	main()
{
	vector< vector<int> >	a(3);
	a[0] = {1, 1, 0};
	a[1] = {1, 1, 0};
	a[2] = {0, 1, 1};
	cout << solution(3, a) << endl;
}
