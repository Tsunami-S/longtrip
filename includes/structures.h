#ifndef STRUCTUwRES_H
# define STRUCTURES_H

using namespace	std;

struct			OneWay
{
	int			id;
	float		distance;
};

class Path
{
  public:
	float distance;
	vector<int> path;

	Path() : distance(0) {};
};

class Route
{
  public:
	int numOfWay;
	vector<vector<OneWay>> list;

	Route(int num) : numOfWay(num), list(num) {}

	void addOneWay(int start, int end, float distance)
	{
		list[start].push_back({end, distance});
	}
};

#endif
