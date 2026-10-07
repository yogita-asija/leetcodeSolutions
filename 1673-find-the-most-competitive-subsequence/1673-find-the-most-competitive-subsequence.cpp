class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {

        int n= nums.size();
        int remove= n-k;

        vector <int> st;

        for (int num:nums){
            while( !st.empty() && st.back()> num && remove>0){
                st.pop_back();
                remove--;
            }

            st.push_back(num);
        }
        return vector<int> (st.begin(), st.begin()+k);

        
    }
    
};