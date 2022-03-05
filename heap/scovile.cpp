#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
	int now;
	priority_queue<int, vector<int>, greater<int> > p_que;

	for (int i : scoville)
		p_que.push(i);
	while (!p_que.empty() && (now = p_que.top()) < K)
	{
		p_que.pop();
		if (p_que.empty())
			return (-1);
		now = now + 2 * (p_que.top());
		p_que.pop();
		p_que.push(now);
		answer++;
	}
	if (p_que.empty())
		return (-1);
    return answer;
}

int	main()
{
	vector<int>	scovile = {3, 2, 1, 9, 10, 12};

	cout << solution(scovile, 7);
}
