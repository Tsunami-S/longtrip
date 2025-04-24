#include "longtrip.h"

static bool isvalid_input(string line, int& start, int& end, float& distance)
{
	char comma;
	
	stringstream ss(line);
	if (!(ss >> start >> comma >> end >> comma >> distance)) 
	{
		cerr << "Error: Invalid input format. Skipping line: " << line << endl;
        return false;
    }
    if (start < 0 || start > INT_MAX)
	{
        cerr << "Error: Invalid start station ID. Must be between 0 and " << INT_MAX << "." << endl;
        return false;
    }
    if (end < 0 || end > INT_MAX)
	{
        cerr << "Error: Invalid end station ID. Must be between 0 and " << INT_MAX << "." << endl;
        return false;
    }
    if (distance < 0)
	{
        cerr << "Error: Invalid distance. Must be more than 0." << endl;
        return false;
    }
    return true;
}

static bool check_existance(const int& start, const int& end, const float& distance, vector<pair<pair<int, int>, float>>& edges)
{
	for (auto& edge : edges)
	{
		if ((edge.first.first == start && edge.first.second == end) ||
			(edge.first.first == end && edge.first.second == start))
		{
			edge.second = distance;
			return true;
		}
	}
	return false;
}

c_route get_oneway_list(void)
{
    string line;
	int start;
	int end;
	float distance;
    int num_of_stations;
    vector<pair<pair<int, int>, float>> edges;

    while (getline(cin, line))
	{
		if (!isvalid_input(line, start, end, distance))
			continue;
		distance = round(distance * 100) / 100.0;
		if (!check_existance(start, end, distance, edges))
			edges.push_back({{start, end}, distance});
    }
    num_of_stations = 0;
    for (const auto& edge : edges)
	{
        num_of_stations = max(num_of_stations, max(edge.first.first, edge.first.second) + 1);
	}
    c_route route(num_of_stations);
    for (const auto& edge : edges)
	{
        route.add_oneway(edge.first.first, edge.first.second, edge.second);
	}
	return route;
}
