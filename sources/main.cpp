#include "longtrip.h"

int main(void)
{
	c_route route = get_oneway_list();
    find_best_path(route);
    return EXIT_SUCCESS;
}
