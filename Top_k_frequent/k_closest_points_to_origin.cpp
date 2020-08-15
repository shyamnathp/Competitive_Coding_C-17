#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>

using namespace std;

int main()
{
	vector<vector<int>> points = { {3,3}, {5,-1}, {-2,4}};

	std::sort(points.begin(), points.end(), [](const vector<int>& point1, const vector<int>& point2) {
		int dist1 = pow(point1[0], 2) + pow(point1[1], 2);
		int dist2 = pow(point2[0], 2) + pow(point2[1], 2);
		return dist1 < dist2;
	});
	int k = 2, i=0;
	vector<vector<int>> kClosest(k);

	for_each(points.begin(), points.begin() + k, [&](vector<int> point)
	{
		kClosest[i] = point;
		++i;
	});

}