class Solution {
public:

    int countBits(int x) {
        int count = 0;

        while (x > 0) {
            count += x & 1;
            x >>= 1;
        }

        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {

        sort(arr.begin(), arr.end(), [&](int a, int b) {

            int bitsA = countBits(a);
            int bitsB = countBits(b);

            if (bitsA != bitsB)
                return bitsA < bitsB;

            return a < b;
        });

        return arr;
    }
};