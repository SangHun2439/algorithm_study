#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
	unordered_map<string, int> table;

	for (int i = 0; i < plays.size(); i++)
	{
		if (table.count(genres[i]) == 0)
			table.insert(make_pair(genres[i], plays[i]));
		else
			table[genres[i]] += plays[i];
	}
    return answer;
}
