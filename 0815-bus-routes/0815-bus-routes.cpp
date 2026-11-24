
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes,
                              int source, int target) {

        if (source == target)
            return 0;

        // Map each stop to the routes that visit it
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                mp[stop].push_back(i);
            }
        }

        // If target is not present, impossible to reach
        if (mp.find(target) == mp.end())
            return -1;

        queue<int> q;
        q.push(source);

        unordered_set<int> visitedStops;
        unordered_set<int> visitedRoutes;

        visitedStops.insert(source);

        int buses = 0;

        while (!q.empty()) {

            int size = q.size();
            buses++;

            // Process current BFS level
            while (size--) {

                int stop = q.front();
                q.pop();

                // Get all buses passing through this stop
                for (int route : mp[stop]) {

                    if (visitedRoutes.count(route))
                        continue;

                    visitedRoutes.insert(route);

                    // Visit all stops of this bus route
                    for (int nextStop : routes[route]) {

                        if (nextStop == target)
                            return buses;

                        if (!visitedStops.count(nextStop)) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};
