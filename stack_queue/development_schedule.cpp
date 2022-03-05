#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
	queue<int>	wait_que;
	int			days = 1;
	int			cnt = 0;

	for (int i = 0; i < progresses.size(); i++)
		wait_que.push(i);
	while (!(wait_que.empty()))
	{
		cnt = 0;
		while (!(wait_que.empty()) && progresses[wait_que.front()] + speeds[wait_que.front()] * days >= 100)
		{
			wait_que.pop();
			cnt++;
		}
		if (cnt != 0)
			answer.push_back(cnt);
		days++;
	}
    return answer;
}

int	main()
{
	vector<int>	progresses = {93, 30, 55};
	vector<int>	speeds = {1, 30, 5};

	solution(progresses, speeds);
	return (0);
}
