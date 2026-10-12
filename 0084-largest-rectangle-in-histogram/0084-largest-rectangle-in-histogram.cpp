
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        // Stack mein bars ke indices store karenge
        stack<int> st;

        // Maximum rectangle area store karega
        int maxi = 0;

        // Total number of bars
        int n = heights.size();

        // i == n par remaining bars ko bhi process karenge
        for(int i = 0; i <= n; i++){

            // Current bar chhota ya equal hai to
            // stack ke top bar ka rectangle calculate karenge
            // i == n par saare remaining bars process honge
            while(!st.empty() &&
                  (i == n || heights[st.top()] >= heights[i])){

                // Top index ki height rectangle ki height hogi
                int element = heights[st.top()];

                // Current bar ko stack se remove kar do
                st.pop();

                int width;

                // Agar stack empty hai, rectangle index 0 se i-1 tak hai
                if(st.empty()) {
                    width = i;
                }
                // Otherwise, previous smaller bar ke baad se
                // current bar ke pehle tak width milegi
                else {
                    width = i - st.top() - 1;
                }

                // Rectangle ka area calculate karo
                maxi = max(maxi, element * width);
            }

            // Valid index ko hi stack mein push karna hai
            if(i < n) {
                st.push(i);
            }
        }

        // Maximum possible rectangle area return karo
        return maxi;
    }
};
