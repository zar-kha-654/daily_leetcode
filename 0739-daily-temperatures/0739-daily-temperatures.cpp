
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        // Store the number of days to wait for a warmer temperature.
        // Initialize all answers to 0 because some days have no warmer day.
        vector<int> answer(n, 0);

        // Store the indices of days whose warmer future day is not found yet.
        stack<int> st;

        // Visit each day from left to right.
        for (int i = 0; i < n; i++) {

            // If the stack is not empty AND today's temperature is warmer
            // than the temperature of the day at the top of the stack...
            while (!st.empty() &&
                   temperatures[i] > temperatures[st.top()]) {

                // Get the index of the previous unresolved day.
                int prev = st.top();

                // Remove that day because we have found its warmer day.
                st.pop();

                // Calculate how many days we waited for a warmer temperature.
                answer[prev] = i - prev;
            }

            // Add today's index to the stack.
            // Its next warmer day has not been found yet.
            st.push(i);
        }

        // Return the waiting time for every day.
        return answer;
    }
};
