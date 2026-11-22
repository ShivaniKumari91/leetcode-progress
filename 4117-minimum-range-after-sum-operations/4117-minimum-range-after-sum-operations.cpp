
class Solution {
public:
    int minRange(int a, int b, int c) {

        // Step 1: Store all three numbers in a vector
        vector<int> v = {a, b, c};

        // Step 2: Sort in ascending order
        // x = smallest, y = middle, z = largest
        sort(v.begin(), v.end());

        int x = v[0];
        int y = v[1];
        int z = v[2];

        // Step 3: Case 1 - Perform no operation
        int ans = z - x;

        // Step 4: Case 2 - Replace largest number z with x + y
        // New numbers: x, y, x+y
        // Since x and y are positive, range = (x+y) - x = y
        ans = min(ans, y);

        // Step 5: Return minimum range
        return ans;
    }
};
