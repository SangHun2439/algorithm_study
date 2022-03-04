#include <string>
#include <vector>
#include <numeric>
#include <stack>
#include <iostream>

using namespace std;

void	do_solution(vector<int> numbers, int target, int depth, int& answer)
{
	if (depth == numbers.size())
	{
		if (accumulate(numbers.begin(), numbers.end(), 0) == target)
			answer++;
		return ;
	}
	numbers[depth] *= 1;
	do_solution(numbers, target, depth + 1, answer);
	numbers[depth] *= -1;
	do_solution(numbers, target, depth + 1, answer);
}

int solution(vector<int> numbers, int target)
{
	int answer = 0;
	do_solution(numbers, target, 0, answer);
	return answer;
}

int	main()
{
	vector<int>	a;
	a.push_back(4);
	a.push_back(1);
	a.push_back(2);
	a.push_back(1);
	cout << solution(a, 4) << endl;
}
