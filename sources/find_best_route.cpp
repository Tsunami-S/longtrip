#include "longtrip.h"

static void dfs(const c_route& route, int id, vector<bool>& visited, c_path& current, c_path& best)
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

void find_best_path(c_route& route)
{
	c_path current;
	c_path best;
    vector<bool> visited(route.num_of_way, false);

    for (int i = 0; i < route.num_of_way; i++)
	{
        dfs(route, i, visited, current, best);
	}
    for (const auto& station : best.path)
	{
        cout << station << endl;
	}
}
