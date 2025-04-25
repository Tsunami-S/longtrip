#include "longtrip.h"

/* DeepFirstSearch using iteration */
static void deepFirstSearch(const Route& route, int startId, Path& best)
{
    stack<DFSStatus> stack;

    stack.emplace(startId, route.numOfWay);
    while (!stack.empty())
    {
		/* save current top of stack and pop it*/
        DFSStatus savedStack = stack.top();
        stack.pop();
		/* update best route */
        if (savedStack.getDistance() > best.distance)
        {
            best.distance = savedStack.getDistance();
            best.path = savedStack.getPath();
        }
		/* push valiable stations to stack */
		if(savedStack.visitStatus(savedStack.getId()) == END)
			continue;
        for (const auto& edge : route.list[savedStack.getId()])
        {
            if (savedStack.visitStatus(edge.id) != PASSED)
            {
                DFSStatus next = savedStack.nextStatus(edge.id, edge.distance);
                stack.push(next);
            }
        }
    }
}

void findBestPath(Route& route)
{
	Path best;

    for (int i = 0; i < route.numOfWay; i++)
	{
        deepFirstSearch(route, i, best);
	}
    for (const auto& station : best.path)
	{
        cout << station << endl;
	}
}
