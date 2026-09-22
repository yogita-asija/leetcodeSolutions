class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> mp;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // Already exists
        if (mp.count(val)) {
            return false;
        }

        // Store index of new element
        mp[val] = nums.size();

        // Add to vector
        nums.push_back(val);

        return true;
    }
    
    bool remove(int val) {
        // Doesn't exist
        if (!mp.count(val)) {
            return false;
        }

        // Index of element to remove
        int index = mp[val];

        // Last element
        int last = nums.back();

        // Put last element at deleted element's position
        nums[index] = last;

        // Update last element's index
        mp[last] = index;

        // Remove last element
        nums.pop_back();

        // Remove val from hashmap
        mp.erase(val);

        return true;
    }
    
    int getRandom() {
        int index = rand() % nums.size();
        return nums[index];
    }
};