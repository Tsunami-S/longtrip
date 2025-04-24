#include "longtrip.h"

static bool isValidInput(string line, int& startId, int& endId, float& distance)
{
	bool error;
	string startIdStr;
	string endIdStr;
	string distanceStr;

	error = true;
	stringstream ss(line);
	if(!getline(ss, startIdStr, ',') || !getline(ss, endIdStr, ',') || !getline(ss, distanceStr))
	{
		cerr << "Error: Invalid input format. Skipping line: " << line << endl;
		return false;
    }
    if (!isInteger(startIdStr))
	{
        cerr << "Error: Invalid integer value: " << startIdStr << endl;
		error = false;
    }
    if (!isInteger(endIdStr))
	{
        cerr << "Error: Invalid integer value: " << endIdStr << endl;
		error = false;
    }
    if (!isFloat(distanceStr))
	{
        cerr << "Error: Invalid float value: " << distanceStr << endl;
		error = false;
    }
	if(!error)
	{
		cerr << "Skipping line: " << line << endl;
		return error;
	}
    startId = stoi(startIdStr);
    endId = stoi(endIdStr);
    distance = stof(distanceStr);
    if (startId < 0 || startId > INT_MAX)
	{
        cerr << "Error: Invalid startId station ID. Must be between 0 and " << INT_MAX << "." << endl;
		error = false;
    }
    if (endId < 0 || endId > INT_MAX)
	{
        cerr << "Error: Invalid endId station ID. Must be between 0 and " << INT_MAX << "." << endl;
		error = false;
    }
    if (distance < 0)
	{
        cerr << "Error: Invalid distance. Must be more than 0." << endl;
		error = false;
    }
	if(!error)
	{
		cerr << "Skipping line: " << line << endl;
	}
    return error;
}

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
	}
	return route;
}
