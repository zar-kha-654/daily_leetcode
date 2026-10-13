
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        // Get the total number of days
        int days = temperatures.size();

        // Stack stores indices of future days
        stack<int> st;

        // Initialize answers to 0 for all days
        vector<int> ans(days, 0);

        // Traverse from the last day to the first day
        for (int i = days - 1; i >= 0; i--) {

            // Remove days that are colder than or equal to today
            // They cannot be the next warmer day
            while (!st.empty() &&
                   temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If a warmer future day exists
            if (!st.empty()) {

                // Calculate the number of days to wait
                ans[i] = st.top() - i;
            }
            // Otherwise, the answer remains 0
            else {
                ans[i] = 0;
            }

            // Store today's index for earlier days to check
            st.push(i);
        }

        // Return the waiting days for every day
        return ans;
    }
};
