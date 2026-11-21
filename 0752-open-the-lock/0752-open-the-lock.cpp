
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead(
            deadends.begin(), deadends.end()
        );

        // Starting combination is blocked
        if (dead.count("0000")) return -1;

        queue<string> q;
        unordered_set<string> visited;

        q.push("0000");
        visited.insert("0000");

        int steps = 0;

        while (!q.empty()) {

            int size = q.size();

            // Process one complete BFS level
            while (size--) {

                string curr = q.front();
                q.pop();

                // Target reached
                if (curr == target) {
                    return steps;
                }

                // Generate 8 neighbours
                for (int i = 0; i < 4; i++) {

                    // Rotate forward
                    string next = curr;
                    next[i] = (next[i] - '0' + 1) % 10 + '0';

                    if (!dead.count(next) &&
                        !visited.count(next)) {

                        visited.insert(next);
                        q.push(next);
                    }

                    // Rotate backward
                    string prev = curr;
                    prev[i] = (prev[i] - '0' + 9) % 10 + '0';

                    if (!dead.count(prev) &&
                        !visited.count(prev)) {

                        visited.insert(prev);
                        q.push(prev);
                    }
                }
            }

            // Move to next BFS level
            steps++;
        }

        return -1;
    }
};
