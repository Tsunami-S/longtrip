#include "longtrip.h"

static void deepFirstSearch(const Route& route, int startId, Path& best)
{
    stack<pair<int, Path>> s;
    vector<bool> visited(route.list.size(), false);

    Path initialPath;
    s.push({startId, initialPath});
    while (!s.empty())
	{
        auto [id, current] = s.top();
        s.pop();
        if (visited[id])
		{
            continue;
        }
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
                Path newPath = current;
                newPath.distance += edge.distance;
                s.push({edge.id, newPath});
            }
        }
        current.path.pop_back();
    }
}

void findBestPath(Route& route)
{
	Path best;
    vector<bool> visited(route.numOfWay, false);

    for (int i = 0; i < route.numOfWay; i++)
	{
        deepFirstSearch(route, i, best);
	}
    for (const auto& station : best.path)
	{
        cout << station << endl;
	}
}
