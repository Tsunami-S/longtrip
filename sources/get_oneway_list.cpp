#include "longtrip.h"

static bool checkExistance(const int& startId, const int& endId, const float& distance, vector<pair<pair<int, int>, float>>& edges)
{
	for (auto& edge : edges)
	{
		/* if it already exists, update the distance */
		if ((edge.first.first == startId && edge.first.second == endId))
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

	/* continue input until EOF is received */
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
	/* use the largest id as the number of stations and create a route list */
    numOfStations = 0;
    for (const auto& edge : edges)
	{
        numOfStations = max(numOfStations, max(edge.first.first, edge.first.second) + 1);
	}
    Route route(numOfStations);
    for (const auto& edge : edges)
	{
        route.addOneWay(edge.first.first, edge.first.second, edge.second);
	}
	return route;
}
