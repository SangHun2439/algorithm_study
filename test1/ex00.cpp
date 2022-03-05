#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int	get_day(string daystamp, vector<int>& month_convert)
{
	string month = daystamp.substr(5, 7);
	string day = daystamp.substr(8, 10);

	return (month_convert[stoi(month) - 1] + stoi(day) - 1);
}

int	get_price(string purchase)
{
	return (stoi(purchase.substr(11)));
}

vector<int> solution(vector<string> purchase) {
    vector<int> answer(5);
	vector<int>	month_day;
	vector<int>	month_convert;
	vector<int>	day_convert(365, 0);
	int			convert;
	int			amount;

	month_day = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
	for (int i = 0; i < month_day.size(); i++)
	{
		convert = 0;
		for (int j = 0; j <= i; j++)
			convert += month_day[j];
		month_convert.push_back(convert);
	}

	for (string s : purchase)
		day_convert[get_day(s, month_convert)] = get_price(s);

	for (int j = 0; j < day_convert.size(); j++)
	{
		amount = 0;
		int k = j - 29 < 0 ? 0 : j - 29;
		for (; k <= j; k++)
			amount += day_convert[k];
		if (amount < 10000)
			answer[0]++;
		else if (amount < 20000)
			answer[1]++;
		else if (amount < 50000)
			answer[2]++;
		else if (amount < 100000)
			answer[3]++;
		else
			answer[4]++;
	}
    return answer;
}

int main()
{
	vector<string> str_arr;

	str_arr = {"2019/01/01 5000", "2019/01/20 15000", "2019/02/09 90000"};
	solution(str_arr);
}
