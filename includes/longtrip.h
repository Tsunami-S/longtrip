#ifndef LONGTRIP_H
# define LONGTRIP_H

# include <algorithm>
# include <climits>
# include <cmath>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <vector>
# include <regex>
# include "structures.h"

Route getOneWayList(void);
void findBestPath(Route& route);

/* for validation */
bool isValidInput(string line, int& startId, int& endId, float& distance);
bool isInteger(const string& str);
bool isFloat(const string& str);

#endif
