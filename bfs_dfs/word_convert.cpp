#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool	is_connect(string a, string b)
{
	int	cnt;

	if (a == b)
		return (false);
	cnt = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			cnt++;
		if (cnt > 1)
			return (false);
	}
	return (true);
}

int	do_solution(vector< vector<int> > graph, int start_num, int target_num)
{
	queue<int>		bfs_que;
	vector<bool>	visit(graph.size(), false);
	vector<int>		can_visit;
	vector<int>		dist(graph.size(), 0);
	int				now;

	bfs_que.push(start_num);
	visit[start_num] = true;
	dist[start_num] = 0;
	while (!bfs_que.empty())
	{
		now = bfs_que.front();
		bfs_que.pop();
		can_visit = graph[now];
		for(int i : can_visit)
		{
			if (!visit[i])
			{
				visit[i] = true;
				dist[i] = dist[now] + 1;
				bfs_que.push(i);
				if (i == target_num)
					return (dist[i]);
			}
		}
	}
	return (0);
}

int solution(string begin, string target, vector<string> words)
{
	int answer = 0;
	vector< vector<int> >	graph;
	vector<int>				graph_node;
	int						target_num = -1;
	int						start_num;

	words.push_back(begin);
	start_num = words.size() - 1;
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == target)
			target_num = i;
		for (int j = 0; j < words.size(); j++)
		{
			if (is_connect(words[i], words[j]))
				graph_node.push_back(j);
		}
		graph.push_back(graph_node);
		graph_node.clear();
	}
	if (target_num == -1)
		return (0);
	answer = do_solution(graph, start_num, target_num);
	return answer;
}

int	main()
{
	vector<string>	words;

	words = {"hot", "dot", "dog", "lot", "log", "cog"};
	string begin = "hit";
	string target = "cog";
	cout << solution(begin, target, words) << endl;
}
