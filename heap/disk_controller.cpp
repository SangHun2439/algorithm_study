#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct cmp1
{
	bool operator()(vector<int> v1, vector<int> v2)
	{
		return (v1[0] > v2[0]);
	}
};

struct cmp2
{
	bool operator()(vector<int> v1, vector<int> v2)
	{
		return (v1[1] > v2[1]);
	}
};

int solution(vector<vector<int>> jobs) {
    int 		answer = 0;
	int			now_time = 0;
	vector<int> now_job;
	priority_queue<vector<int> , vector<vector<int> >, cmp1> wait_que;
	priority_queue<vector<int> , vector<vector<int> >, cmp2> exec_que;

	for (vector<int> v : jobs)
		wait_que.push(v);
	while (!(wait_que.empty()) || !(exec_que.empty()))
	{
		while (!wait_que.empty() && wait_que.top()[0] <= now_time)
		{
			exec_que.push(wait_que.top());
			wait_que.pop();
		}
		if (!exec_que.empty())
		{
			now_time += exec_que.top()[1];
			answer += now_time - exec_que.top()[0];
			exec_que.pop();
		}
		else
			now_time++;
	}
	answer /= jobs.size();
    return answer;
}

int	main()
{
	vector<vector<int> > jobs;

	jobs = {
			{0, 3},
			{1, 9},
			{2, 6}
	};
	cout << solution(jobs);
}
