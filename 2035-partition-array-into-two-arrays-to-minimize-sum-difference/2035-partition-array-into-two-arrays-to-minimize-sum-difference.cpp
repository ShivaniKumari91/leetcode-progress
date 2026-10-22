class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();

        // Total sum of all elements
        int S = accumulate(begin(nums), end(nums), 0);

        // Divide the array into two halves
        int n = N / 2;
        int n1 = n;
        int n2 = n;

        // sumsLeft[count]  -> sums of subsets having 'count' elements from left half
        // sumsRight[count] -> sums of subsets having 'count' elements from right half
        unordered_map<int, vector<int>> sumsLeft;
        unordered_map<int, vector<int>> sumsRight;

        // -------------------- STEP 1: GENERATE LEFT SUBSET SUMS --------------------
        // Use bitmasking to generate all subsets of the left half
        for (int mask = 0; mask < (1 << n1); mask++) {
            int s = 0;
            int count = 0;

            for (int i = 0; i < n1; i++) {
                // If the ith bit is set, include nums[i] in this subset
                if (mask & (1 << i)) {
                    s += nums[i];
                    count++;
                }
            }

            // Store the subset sum according to its number of elements
            sumsLeft[count].push_back(s);
        }

        // -------------------- STEP 2: GENERATE RIGHT SUBSET SUMS --------------------
        // Generate all subsets of the right half
        for (int mask = 0; mask < (1 << n1); mask++) {
            int s = 0;
            int count = 0;

            for (int i = 0; i < n1; i++) {
                // Right half starts from index n
                if (mask & (1 << i)) {
                    s += nums[n + i];
                    count++;
                }
            }

            // Store sums grouped by the number of selected elements
            sumsRight[count].push_back(s);
        }

        // -------------------- STEP 3: SORT RIGHT SUBSET SUMS --------------------
        // Sorting allows us to use binary search with lower_bound
        for (int count = 0; count <= n2; count++) {
            sort(begin(sumsRight[count]), end(sumsRight[count]));
        }

        int minValue = INT_MAX;

        // -------------------- STEP 4: FIND THE MINIMUM DIFFERENCE --------------------
        // We need to select exactly n elements for the first partition.
        // If k elements are selected from the left half,
        // then n-k elements must be selected from the right half.
        for (int k = 0; k < n1; k++) {
            int m = n - k;

            // Try every subset sum having exactly k elements from the left half
            for (int leftSubSum : sumsLeft[k]) {

                // Let leftSubSum + rightSubSum be the sum of the first partition.
                //
                // First partition sum     = leftSubSum + rightSubSum
                // Second partition sum    = S - (leftSubSum + rightSubSum)
                //
                // Difference = abs(2 * (leftSubSum + rightSubSum) - S)
                //
                // To make this difference minimum, we want:
                // leftSubSum + rightSubSum to be as close to S/2 as possible.

                int need = (S - 2 * leftSubSum) / 2;

                // Find the first right subset sum >= need
                int low = lower_bound(
                    begin(sumsRight[m]),
                    end(sumsRight[m]),
                    need
                ) - begin(sumsRight[m]);

                // Check the element at lower_bound, if it exists.
                // It is the first possible sum greater than or equal to need.
                if (low < sumsRight[m].size()) {
                    int rightSubSum = sumsRight[m][low];

                    // Calculate the difference between the two partition sums
                    minValue = min(
                        minValue,
                        abs(2 * (leftSubSum + rightSubSum) - S)
                    );
                }

                // Also check the previous element.
                // It may be closer to the ideal sum than the element at lower_bound.
                if (low - 1 >= 0) {
                    int rightSubSum = sumsRight[m][low - 1];

                    minValue = min(
                        minValue,
                        abs(2 * (leftSubSum + rightSubSum) - S)
                    );
                }
            }
        }

        // Return the minimum difference found
        return minValue;
    }
};