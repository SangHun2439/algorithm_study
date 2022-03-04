#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

bool	compare(vector<string> a, vector<string> b)
{
	return (a[1] < b[1]);
}

void	do_solution(vector<vector<string> > tickets, int now_idx, int depth, vector<string>& answer, vector<string>	each_answer, vector<bool> visit, bool& solve)
{
	if (solve)
		return ;
	visit[now_idx] = true;
	string to_go = tickets[now_idx][1];
	each_answer.push_back(to_go);
	if (depth == tickets.size() - 1)
	{
		answer = each_answer;
		solve = true;
		return ;
	}
	for (int i = 0; i < tickets.size(); i++)
	{
		if (!visit[i] && tickets[i][0] == to_go)
			do_solution(tickets, i, depth + 1, answer, each_answer, visit, solve);
	}
}

vector<string> solution(vector<vector<string> > tickets) {
    vector<string>	answer;
    vector<string>	each_answer;
	vector<bool>	visit(tickets.size(), false);
	queue<int>		start_que;
	bool			solve = false;

	sort(tickets.begin(), tickets.end(), compare);
	for (int i = 0; i < tickets.size(); i++)
	{
		if (tickets[i][0] == "ICN")
			start_que.push(i);
	}
	each_answer.push_back("ICN");
	while (!solve)
	{
		do_solution(tickets, start_que.front(), 0, answer, each_answer, visit, solve);
		start_que.pop();
	}
    return answer;
}

int	main()
{
	vector<vector<string> > tickets;
	tickets = {
				{"ICN", "COO"},
				{"ICN", "BOO"},
				{"COO", "ICN"},
				{"BOO", "DOO"}
	};
	vector<string> answer = solution(tickets);
	for (string s : answer)
		cout << s << endl;
}
