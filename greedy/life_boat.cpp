#include <string>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
	deque<int>	people_deq;

	people_deq.resize(people.size());
	copy(people.begin(), people.end(), people_deq.begin());
	sort(people_deq.begin(), people_deq.end(), greater<int>());
	while (!people_deq.empty())
	{
		answer++;
		if (people_deq.begin() == people_deq.end() - 1)
			people_deq.pop_front();
		else if (people_deq.front() + people_deq.back() <= limit)
		{
			people_deq.pop_front();
			people_deq.pop_back();
		}
		else
			people_deq.pop_front();
	}
    return answer;
}

int	main()
{
	vector<int> problem = {100, 500, 500, 900, 950};
	solution(problem, 1000);
}
