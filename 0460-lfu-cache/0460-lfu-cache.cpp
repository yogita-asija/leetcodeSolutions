class LFUCache {
private:

    struct Node {
        int key;
        int value;
        int freq;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    };

    int capacity;
    int minFreq;

    // key -> node
    unordered_map<int, list<Node>::iterator> keyTable;

    // freq -> list of nodes
    unordered_map<int, list<Node>> freqTable;

    void increaseFreq(int key) {

        auto it = keyTable[key];
        Node node = *it;

        int oldFreq = node.freq;

        // Remove from old frequency list
        freqTable[oldFreq].erase(it);

        // If old frequency becomes empty
        if (freqTable[oldFreq].empty()) {

            freqTable.erase(oldFreq);

            if (minFreq == oldFreq) {
                minFreq++;
            }
        }

        // Increase frequency
        node.freq++;

        // Add to new frequency list
        freqTable[node.freq].push_back(node);

        // Update iterator
        keyTable[key] = prev(freqTable[node.freq].end());
    }

public:

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {

        if (keyTable.find(key) == keyTable.end()) {
            return -1;
        }

        auto it = keyTable[key];

        int value = it->value;

        increaseFreq(key);

        return value;
    }

    void put(int key, int value) {

        if (capacity == 0) {
            return;
        }

        // Key already exists
        if (keyTable.find(key) != keyTable.end()) {

            auto it = keyTable[key];

            it->value = value;

            increaseFreq(key);

            return;
        }

        // Cache full
        if (keyTable.size() == capacity) {

            auto &lst = freqTable[minFreq];

            // LRU node is at front
            Node victim = lst.front();

            keyTable.erase(victim.key);

            lst.pop_front();

            if (lst.empty()) {
                freqTable.erase(minFreq);
            }
        }

        // Insert new node
        Node newNode(key, value);

        freqTable[1].push_back(newNode);

        keyTable[key] = prev(freqTable[1].end());

        minFreq = 1;
    }
};