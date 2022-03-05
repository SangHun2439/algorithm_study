#include <string>
#include <vector>
#include <queue>

using namespace std;

bool	is_sig(int idx, vector<int>priorities)
{
	for (int i : priorities)
	{
		if (priorities[idx] < i)
			return (false);
	}
	return (true);
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
	queue<int>	wait_que;
	int	print_num;

	for (int i = 0; i < priorities.size(); i++)
		wait_que.push(i);
	while (!(wait_que.empty()))
	{
		print_num = wait_que.front();
		wait_que.pop();
		if (!is_sig(print_num, priorities))
			wait_que.push(print_num);
		else
		{
			answer++;
			priorities[print_num] = 0;
			if (print_num == location)
				return (answer);
		}
	}
    return answer;
}

int	main()
{
	vector<int>	a = {2, 1, 3, 2};

	solution(a, 2);
}
