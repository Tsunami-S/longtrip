#include "longtrip.h"

static bool checkExistance(const int& startId, const int& endId, const float& distance, vector<pair<pair<int, int>, float>>& edges)
{
	for (auto& edge : edges)
	{
		if ((edge.first.first == startId && edge.first.second == endId) ||
			(edge.first.first == endId && edge.first.second == startId))
		{
			edge.second = distance;
			return true;
		}
	}
	return false;
}

Route getOneWayList(void)
{
    string line;
	int startId;
	int endId;
	float distance;
    int numOfStations;
    vector<pair<pair<int, int>, float>> edges;

    while (getline(cin, line))
	{
		startId = -1;
		endId = -1;
		distance = -1;
		if (!isValidInput(line, startId, endId, distance))
			continue;
		distance = round(distance * 100) / 100.0;
		if (!checkExistance(startId, endId, distance, edges))
			edges.push_back({{startId, endId}, distance});
    }
    numOfStations = 0;
    for (const auto& edge : edges)
	{
        numOfStations = max(numOfStations, max(edge.first.first, edge.first.second) + 1);
	}
    Route route(numOfStations);
    for (const auto& edge : edges)
	{
        route.addOneWay(edge.first.first, edge.first.second, edge.second);
        route.addOneWay(edge.first.second, edge.first.first, edge.second);
	}
	return route;
}
