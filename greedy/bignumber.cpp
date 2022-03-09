#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k)
{
	string answer = "";
	int		answer_len = number.size() - k;
	int		start_idx;
	int		max_val;

	start_idx = 0;
	for (int i = 0; i < answer_len; i++)
	{
		max_val = number[start_idx] - '0';
		for (int j = start_idx; j < number.size() - answer_len + i + 1; j++)
		{
			if (number[j] - '0' > max_val)
			{
				max_val = number[j] - '0';
				start_idx = j;
			}
		}
		start_idx++;
		answer = answer + to_string(max_val);
	}
	return answer;
}

int main()
{
	solution("1231234", 3);
}
