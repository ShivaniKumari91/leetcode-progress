class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();

        // Total sum of all elements
        int S = accumulate(begin(nums), end(nums), 0);

        // Divide array into two equal halves
        int n = N / 2;
        int n1 = n;
        int n2 = n;

        // Store subset sums according to the number of selected elements
        unordered_map<int, vector<int>> sumsLeft;
        unordered_map<int, vector<int>> sumsRight;

        // STEP 1: Generate subset sums of both halves in a single loop
        for (int mask = 0; mask < (1 << n1); mask++) {
            int s1 = 0, s2 = 0;
            int count1 = 0, count2 = 0;

            for (int i = 0; i < n1; i++) {
                if (mask & (1 << i)) {
                    // Select element from the left half
                    s1 += nums[i];
                    count1++;

                    // Select corresponding element from the right half
                    s2 += nums[n + i];
                    count2++;
                }
            }

            // Store sums grouped by the number of selected elements
            sumsLeft[count1].push_back(s1);
            sumsRight[count2].push_back(s2);
        }

        // STEP 2: Sort right-half subset sums for binary search
        for (int count = 0; count <= n2; count++) {
            sort(begin(sumsRight[count]), end(sumsRight[count]));
        }

        int minValue = INT_MAX;

        // STEP 3: Find the minimum difference
        // Select k elements from the left half
        // and n-k elements from the right half
        for (int k = 0; k <= n1; k++) {
            int m = n - k;

            for (int leftSubSum : sumsLeft[k]) {

                // Find the right subset sum that makes
                // the total selected sum as close to S/2 as possible
                int need = (S - 2 * leftSubSum) / 2;

                // Find the first right subset sum >= need
                int low = lower_bound(
                    begin(sumsRight[m]),
                    end(sumsRight[m]),
                    need
                ) - begin(sumsRight[m]);

                // Check the element at lower_bound
                if (low < sumsRight[m].size()) {
                    int rightSubSum = sumsRight[m][low];

                    minValue = min(
                        minValue,
                        abs(2 * (leftSubSum + rightSubSum) - S)
                    );
                }

                // Check the previous element as well
                if (low - 1 >= 0) {
                    int rightSubSum = sumsRight[m][low - 1];

                    minValue = min(
                        minValue,
                        abs(2 * (leftSubSum + rightSubSum) - S)
                    );
                }
            }
        }

        // Return the minimum possible difference
        return minValue;
    }
};