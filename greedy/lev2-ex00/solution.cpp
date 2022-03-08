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

int	get_dist(int s, int e, int size)
{
	int dist = abs(e - s);
	if (dist > size / 2)
		dist = size - dist;
	return (dist);
}

vector<vector<pair<int, int> > >	make_graph(const string& name)
{
	vector<pair<int, int> >				node;
	vector<vector<pair<int, int> > >	res;
	int	idx;

	idx = 0;
	node.push_back(make_pair(0, get_dist(0, 0, name.size())));
	for (int i = 1; i < name.size(); i++)
	{
		if (name[i] != 'A')
		{
			idx++;
			node.push_back(make_pair(idx, get_dist(0, i, name.size())));
		}
	}
	res.push_back(node);
	node.clear();
	for (int i = 1; i < name.size(); i++)
	{
		if (name[i] != 'A')
		{
			idx = 0;
			node.push_back(make_pair(0, get_dist(i, 0, name.size())));
			for (int j = 1; j < name.size(); j++)
			{
				if (name[j] != 'A')
				{
					idx++;
					node.push_back(make_pair(idx, get_dist(i, j, name.size())));
				}
			}
			res.push_back(node);
			node.clear();
		}
	}
	return (res);
}

void	dfs(vector<vector<pair<int, int> > > graph, vector<bool> visit, int now_idx, int& answer, int each_answer)
{
	bool	end = true;

	visit[now_idx] = true;
	for (bool b : visit)
		end = b && end;
	if (end)
	{
		if (answer == -1)
			answer = each_answer;
		else if (each_answer < answer)
			answer = each_answer;
		return ;
	}
	for (int i = 0; i < graph[now_idx].size(); i++)
	{
		if (!(visit[graph[now_idx][i].first]))
			dfs(graph, visit, graph[now_idx][i].first, answer, each_answer + graph[now_idx][i].second);
	}
}

// int solution(string name) {
// 	int	answer = -1;
// 	vector<vector<pair<int, int> > >	graph;

// 	graph = make_graph(name);
// 	vector<bool>	visit(graph.size(), false);
// 	dfs(graph, visit, 0, answer, 0);
// 	for (char c : name)
// 		answer += up_down(c);
// 	return answer;
// }

using namespace std;

int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

int solution(string name) {
    int answer = 0;
    for (auto ch : name)
        answer += LUT[ch - 'A'];
    int len = name.length();
    int left_right = len - 1;
    for (int i = 0; i < len; ++i) {
        int next_i = i + 1;
        while (next_i < len && name[next_i] == 'A')
            next_i++;
        left_right = min(left_right, i + len - next_i + min(i, len - next_i));
    }
    answer += left_right;
    return answer;
}

int main()
{
	cout << solution("ABAAABB") << endl; //7
}
