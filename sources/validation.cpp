#include "longtrip.h"

static void printError(const string& reason, const string& value)
{
	cerr << "Error: " << reason << ": " << value << endl;
}

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
		return false;
    }
    if (!isInteger(startStr))
	{
		printError("Invalid integer value", startStr);
		error = false;
    }
    if (!isInteger(endStr))
	{
		printError("Invalid integer value", endStr);
		error = false;
    }
    if (!isFloat(distanceStr))
	{
		printError("Invalid float value", distanceStr);
		error = false;
    }
	if(!error)
	{
		return error;
	}
    startId = stoi(startStr);
    endId = stoi(endStr);
    distance = stof(distanceStr);
	return true;
}

static bool isValidRange(int& startId, int& endId, float& distance)
{
	bool error;

	error = true;
    if (startId < 0 || startId > INT_MAX)
	{
        cerr << "Error: Invalid end station ID. Must be more than 0." << endl;
		error = false;
    }
    if (endId < 0 || endId > INT_MAX)
	{
        cerr << "Error: Invalid end station ID. Must be more than 0." << endl;
		error = false;
    }
    if (distance < 0)
	{
        cerr << "Error: Invalid distance. Must be more than 0." << endl;
		error = false;
    }
    return error;
}

bool isValidInput(string line, int& startId, int& endId, float& distance)
{
	if(!isValidFormat(line, startId, endId, distance))
	{
		printError("Invalid input format. Skipping line", line);
		return false;
	}
	if(!isValidRange(startId, endId, distance))
	{
		printError("Invalid input Range. Skipping line", line);
		return false;
	}
	return true;
}
