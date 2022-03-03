#include <stack>
#include <vector>
#include <iostream>

using namespace std;

void	dfs_stack(vector< vector< pair<int, const char*> > > graph)
{
	stack< pair<int, const char*> >	st;
	vector<bool>	visit(graph.size(), false);

	st.push(make_pair(0, "S"));
	visit[0] = true;
	while (!st.empty())
	{
		pair<int, const char*> _top = st.top();
		st.pop();
		for (pair<int, const char*> a : graph[_top.first])
		{
			if (!visit[a.first])
			{
				cout << a.second << endl;
				visit[a.first] = true;
				st.push(_top);
				st.push(a);
				break;
			}
		}
	}
}

void	dfs_recursive(vector< vector< pair<int, const char*> > > graph, int start, vector<bool>& visit)
{
	visit[start] = true;
	cout << start << endl;
	for (pair<int, const char*> a : graph[start])
	{
		if (!visit[a.first])
		{
			visit[a.first] = true;
			dfs_recursive(graph, a.first, visit);
		}
	}
}

int	main()
{
	vector< vector< pair<int, const char*> > >	graph(5);

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

	dfs_stack(graph);

	vector<bool>	visit(graph.size(), false);
	dfs_recursive(graph, 0, visit);

	return (0);
}
