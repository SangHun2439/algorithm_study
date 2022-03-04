#include <queue>
#include <vector>
#include <iostream>

using namespace std;

void	bfs(vector< vector< pair<int, string> > > graph)
{
	queue< pair<int, string> > _que;
	vector<bool>	visit(graph.size(), false);
	vector< vector<int> > history;
	vector<int>	hitory_node(2);

	_que.push(make_pair(0, "S"));
	visit[0] = true;
	int	idx = 0;
	int	parent_idx = -1;
	hitory_node[0] = 0;
	hitory_node[1] = parent_idx;
	history.push_back(hitory_node);
	while (!_que.empty())
	{
		pair<int, string> next = _que.front();
		_que.pop();
		parent_idx++;
		if (next.second == "D")
			break;
		for (pair<int, string> a : graph[next.first])
		{
			if (!visit[a.first])
			{
				cout << a.second << endl;
				visit[a.first] = true;
				_que.push(a);
				hitory_node[0] = a.first;
				hitory_node[1] = parent_idx;
				history.push_back(hitory_node);
			}
		}
	}
	int	i = history.back()[1];
	int	j = history.back()[0];
	cout << j << endl;
	while (i != -1)
	{
		j = history[i][0];
		i = history[i][1];
		cout << j << endl;
	}
}

int	main()
{
	vector< vector< pair<int, string> > >	graph(5);

	graph[0].push_back(make_pair(1, "A"));
	graph[0].push_back(make_pair(2, "B"));
	graph[0].push_back(make_pair(3, "C"));

	graph[1].push_back(make_pair(0, "S"));
	graph[1].push_back(make_pair(4, "D"));

	graph[2].push_back(make_pair(0, "S"));
	graph[2].push_back(make_pair(4, "D"));

	graph[3].push_back(make_pair(0, "S"));
	graph[3].push_back(make_pair(4, "D"));

	graph[4].push_back(make_pair(1, "A"));
	graph[4].push_back(make_pair(2, "B"));
	graph[4].push_back(make_pair(3, "C"));

	bfs(graph);

	return (0);
}
