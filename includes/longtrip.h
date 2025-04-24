#ifndef LONGTRIP_H
# define LONGTRIP_H

# include <algorithm>
# include <climits>
# include <cmath>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <vector>
# include "structures.h"

void findBestPath(Route& route);
Route getOneWayList(void);
bool isInteger(const string& str);
bool isFloat(const string& str);

#endif
