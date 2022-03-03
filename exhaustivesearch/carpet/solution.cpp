#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int>	solution(int brown, int yellow)
{
	int	m;
	int	n;
	int	w;
	vector<int>	sol(2);

	w = brown + yellow; // 전체 타일 갯수
	n = 3;
	while (n <= w / 2)
	{
		if (w % n)
		{
			n++;
			continue;
		}
		m = w / n;
		if (brown == 2 * (m + n - 2)) // 브라운 색의 카펫이 테두리에 일치하는 경우
		{
			sol[0] = m;
			sol[1] = n;
			return (sol);
		}
		n++;
	}
	return (sol);
}

int main()
{
	vector<int>	res;

	res = solution(10, 2);
	cout << res[0] << " " << res[1] << endl;
}
