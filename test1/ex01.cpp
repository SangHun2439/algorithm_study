#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void	left(int h, int w, int n, vector<vector<int> > board_int, int& answer)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 1; x < w; x++)
		{
			if (board_int[y][x] != 0)
				board_int[y][x] = board_int[y][x] + board_int[y][x - 1];
		}
	}

	int	res = 0;

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (board_int[y][x] == n)
			{
				if (x + 1 == w)
					res++;
				else if (x + 1 < w && board_int[y][x + 1] != n + 1)
					res++;
			}
		}
	}
	answer += res;
}

void	up(int h, int w, int n, vector<vector<int> > board_int, int& answer)
{
	for (int y = 1; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (board_int[y][x] != 0)
				board_int[y][x] = board_int[y][x] + board_int[y - 1][x];
		}
	}
	int	res = 0;

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (board_int[y][x] == n)
			{
				if (y + 1 == h)
					res++;
				else if (y + 1 < h && board_int[y + 1][x] != n + 1)
					res++;
			}
		}
	}
	answer += res;
}

void	diagonal_left(int h, int w, int n, vector<vector<int> > board_int, int& answer)
{
	for (int y = 1; y < h; y++)
	{
		for (int x = 1; x < w; x++)
		{
			if (board_int[y][x] != 0)
				board_int[y][x] = board_int[y][x] + board_int[y - 1][x - 1];
		}
	}
	int	res = 0;

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (board_int[y][x] == n)
			{
				if (y + 1 == h || x + 1 == w)
					res++;
				else if (board_int[y + 1][x + 1] != n + 1)
					res++;
			}
		}
	}
	answer += res;
}


void	diagonal_right(int h, int w, int n, vector<vector<int> > board_int, int& answer)
{
	for (int y = 1; y < h; y++)
	{
		for (int x = w - 2; x >= 0; x--)
		{
			if (board_int[y][x] != 0)
				board_int[y][x] = board_int[y][x] + board_int[y - 1][x + 1];
		}
	}
	int	res = 0;

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (board_int[y][x] == n)
			{
				if (y + 1 == h || x  == 0)
					res++;
				else if (board_int[y + 1][x - 1] != n + 1)
					res++;
			}
		}
	}
	answer += res;
}

int solution(int h, int w, int n, vector<string> board) {
    int answer = 0;
	vector<int> each_line;
	vector< vector<int> > board_int;

	for (string s : board)
	{
		for (char c : s)
			each_line.push_back(c - '0');
		board_int.push_back(each_line);
		each_line.clear();
	}
	left(h, w, n, board_int, answer);
	up(h, w, n, board_int, answer);
	diagonal_left(h, w, n, board_int, answer);
	diagonal_right(h, w, n, board_int, answer);
    return answer;
}

int main()
{
	vector<string> board = {"111100000","000010011","111100011","111110011","111100011","111100010","111100000"};

	solution(7, 9, 4, board);
}
