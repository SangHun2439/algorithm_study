#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

void	bfs_recur(vector<vector<int> > grid, int& answer, int& solve, int now_idx)
{
	vector<bool>	visit(8, false);
	queue<int>		bfs_que;

	if (solve)
		return ;
	visit[now_idx] = true;
	bfs_que.push(now_idx);
	while (!(bfs_que.empty()))
	{

	}


}

int solution(vector<vector<int> > grid) {
    int answer = -1;
    return answer;
}
