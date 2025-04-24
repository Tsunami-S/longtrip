#include "longtrip.h"

static void dfs(const Route& route, int id, vector<bool>& visited, Path& current, Path& best)
{
    visited[id] = true;
    current.path.push_back(id);
    if (current.distance > best.distance)
	{
        best.distance = current.distance;
        best.path = current.path;
    }
    for (const auto& edge : route.list[id])
	{
        if (!visited[edge.id])
		{
			current.distance += edge.distance;
            dfs(route, edge.id, visited, current, best);
			current.distance -= edge.distance;
		}
    }
    visited[id] = false;
    current.path.pop_back();
}

void findBestPath(Route& route)
{
	Path current;
	Path best;
    vector<bool> visited(route.numOfWay, false);

    for (int i = 0; i < route.numOfWay; i++)
	{
        dfs(route, i, visited, current, best);
	}
    for (const auto& station : best.path)
	{
        cout << station << endl;
	}
}
