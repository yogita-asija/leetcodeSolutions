class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {

        vector<string> letterLogs;
        vector<string> digitLogs;

        // Separate letter and digit logs
        for (string& log : logs) {

            int pos = log.find(' ');

            // Character after identifier
            if (isdigit(log[pos + 1])) {
                digitLogs.push_back(log);
            }
            else {
                letterLogs.push_back(log);
            }
        }

        // Sort letter logs
        sort(letterLogs.begin(), letterLogs.end(),
            [](const string& a, const string& b) {

                int posA = a.find(' ');
                int posB = b.find(' ');

                string idA = a.substr(0, posA);
                string idB = b.substr(0, posB);

                string contentA = a.substr(posA + 1);
                string contentB = b.substr(posB + 1);

                // First compare content
                if (contentA != contentB)
                    return contentA < contentB;

                // If content same, compare identifier
                return idA < idB;
            });

        // Letter logs first, digit logs later
        letterLogs.insert(
            letterLogs.end(),
            digitLogs.begin(),
            digitLogs.end()
        );

        return letterLogs;
    }
};