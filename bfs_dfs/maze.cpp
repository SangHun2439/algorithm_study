#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int	x[] = {-1, 0, 1, 0};
int	y[] = {0, 1, 0, -1};

void	solution(int (*map)[7], pair<int, int> start, pair<int, int> finish)
{
	queue< pair<int, int> >	bfs_que;
	pair<int, int> 			now;
	int						answer;
	bool					solve;
	int						parent_idx = -1;
	vector< vector<int> >	history;
	vector<int>				history_node(3);

	solve = false;
	bfs_que.push(start);
	map[start.second][start.first]++;
	history_node[0] = start.first;
	history_node[1] = start.second;
	history_node[2] = parent_idx;
	history.push_back(history_node);
	while (!bfs_que.empty())
	{
		now = bfs_que.front();
		bfs_que.pop();
		parent_idx++;
		for (int i = 0; i < 4; i++)
		{
			int	nx = now.first + x[i];
			int	ny = now.second + y[i];
			if (map[ny][nx] == 0)
			{
				bfs_que.push(make_pair(nx, ny));
				map[ny][nx] = map[now.second][now.first] + 1;
				history_node[0] = nx;
				history_node[1] = ny;
				history_node[2] = parent_idx;
				history.push_back(history_node);
				if (nx == finish.first && ny == finish.second)
				{
					answer = map[ny][nx] - 1;
					solve = true;
					break;
				}
			}
		}
		if (solve)
			break;
	}
	if (!solve)
	{
		cout << "no solution!!" << endl;
		return ;
	}
	cout << "=====" << answer << "=====" << endl;
	parent_idx = history.back()[2];
	cout << "(" << history.back()[0] << ", " << history.back()[1] << ")" << endl;
	while (parent_idx != -1)
	{
		cout << "(" << history[parent_idx][0] << ", " << history[parent_idx][1] << ")" << endl;
		parent_idx = history[parent_idx][2];
	}
}

int	main()
{
	int	maze[7][7] = {
						{1, 1, 1, 1, 1, 1, 1},
						{1, 0, 0, 1, 0, 0, 1},
						{1, 0, 0, 0, 0, 0, 1},
						{1, 0, 0, 0, 1, 0, 1},
						{1, 1, 1, 0, 1, 1, 1},
						{1, 0, 0, 0, 0, 0, 1},
						{1, 1, 1, 1, 1, 1, 1}
					};

	solution(maze, make_pair(5, 1), make_pair(1, 5));
}
