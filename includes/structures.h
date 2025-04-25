#ifndef STRUCTURES_H
# define STRUCTURES_H

using namespace	std;

enum			VisitedStatus
{
	YET,
	PASSED,
	START,
	END,
};

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

class DFSStatus {
private:
    int id;
    int distance;
    vector<int> path;
    vector<VisitedStatus> visited;

public:
	/* for init */
    DFSStatus(int startId, int numOfNodes)
        : id(startId), distance(0), path{startId}, visited(numOfNodes, YET)
    {
        visited[startId] = START;
    }
	/* for update */
    DFSStatus(const DFSStatus& prev, int nextId, float edgeDistance)
        : id(nextId), distance(prev.distance + edgeDistance),
          path(prev.path), visited(prev.visited)
    {
        path.push_back(nextId);
		if(visited[nextId] == START)
			visited[nextId] = END;
		else
			visited[nextId] = PASSED;
    }

	/* functions */
    int getId() const
	{
		return id;
	}
    int getDistance() const
	{
		return distance;
	}
    const vector<int>& getPath() const
	{
		return path;
	}
    const vector<VisitedStatus>& getVisited() const
	{
		return visited;
	}
    VisitedStatus visitStatus(int stationId) const
	{
        return visited[stationId];
    }
    DFSStatus nextStatus(int nextId, float edgeDistance) const
	{
        return DFSStatus(*this, nextId, edgeDistance);
    }
};

#endif
