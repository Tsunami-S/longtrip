#ifndef STRUCTURES_H
# define STRUCTURES_H

using namespace	std;

struct			s_oneway
{
	int			id;
	float		distance;
};

class c_path
{
  public:
	float distance;
	vector<int> path;

	c_path()
	{
		distance = 0;
	}
};

class c_route
{
  public:
	int num_of_way;
	vector<vector<s_oneway>> list;

	c_route(int num)
	{
		num_of_way = num;
		list.resize(num);
	}
	void add_oneway(int start, int end, float distance)
	{
		list[start].push_back({end, distance});
	}
};

#endif
