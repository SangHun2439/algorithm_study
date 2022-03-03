#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int	up_down(char c)
{
	int	res;
	res = c - 'A';
	return (res > 13 ? 26 - res : res);
}

int	left(vector<int> cnt, int& cursor)
{
	int	idx;
	int	res;

	idx = cursor;
	res = 0;
	for (int i = 1; i < cnt.size(); i++)
	{
		res++;
		idx--;
		if (idx < 0)
			idx += cnt.size();
		if (cnt[idx])
			return (res);
	}
	return (0);
}

int	right(vector<int> cnt, int& cursor)
{
	int	idx;
	int	res;

	idx = cursor;
	res = 0;
	for (int i = 1; i < cnt.size(); i++)
	{
		res++;
		idx++;
		if (idx >= cnt.size())
			idx -= cnt.size();
		if (cnt[idx])
			return (res);
	}
	return (0);
}

int solution(string name) {
	int answer = 0;
	int cursor = 0;
	int left_dist;
	int right_dist;
	vector<int>	cnt(name.size());

	for (int i = 0; i < name.size(); i++)
		cnt[i] = up_down(name[i]);
	answer += cnt[cursor];
	cnt[cursor] = 0;
	left_dist = left(cnt, cursor);
	right_dist = right(cnt, cursor);
	while (left_dist)
	{
		if (left_dist > right_dist)
		{
			answer += right_dist;
			cursor += right_dist;
			if (cursor >= cnt.size())
				cursor -= cnt.size();
		}
		else
		{
			answer += left_dist;
			cursor -= left_dist;
			if (cursor < 0)
				cursor += cnt.size();
		}
		answer += cnt[cursor];
		cnt[cursor] = 0;
		left_dist = left(cnt, cursor);
		right_dist = right(cnt, cursor);
	}
	return answer;
}

int main()
{
	cout << solution("ABAAABB") << endl; //7
}
