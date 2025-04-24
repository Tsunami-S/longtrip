#include "longtrip.h"

int main(void)
{
	Route route = getOneWayList();
    findBestPath(route);
    return EXIT_SUCCESS;
}
