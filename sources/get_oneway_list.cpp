#include "longtrip.h"

static bool isValidFormat(string line, int& startId, int& endId, float& distance)
{
	bool error;
	string startStr;
	string endStr;
	string distanceStr;

	error = true;
	stringstream ss(line);
	if(!getline(ss, startStr, ',') || !getline(ss, endStr, ',') || !getline(ss, distanceStr))
	{
		cerr << "Error: Invalid input format. Skipping line: " << line << endl;
		return false;
    }
    if (!isInteger(startStr))
	{
        cerr << "Error: Invalid integer value: " << startStr << endl;
		error = false;
    }
    if (!isInteger(endStr))
	{
        cerr << "Error: Invalid integer value: " << endStr << endl;
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
    startId = stoi(startStr);
    endId = stoi(endStr);
    distance = stof(distanceStr);
	return true;
}

static bool isValidRange(string line, int& startId, int& endId, float& distance)
{
	bool error;

	error = true;
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

static bool isValidInput(string line, int& startId, int& endId, float& distance)
{
	if(!isValidFormat(line, startId, endId, distance))
		return false;
	if(!isValidRange(line, startId, endId, distance))
		return false;
	return true;
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
	}
	return route;
}
