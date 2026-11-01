class Solution {
public:

    // Merge two sorted halves and count inversions
    long long merge(vector<int>& nums, int low, int mid, int high) {

        vector<int> temp;

        int i = low;
        int j = mid + 1;

        long long cnt = 0;

        while(i <= mid && j <= high) {

            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);

                // All remaining elements in left half
                // are greater than nums[j]
                cnt += mid - i + 1;

                j++;
            }
        }

        while(i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= high) {
            temp.push_back(nums[j]);
            j++;
        }

        // Copy sorted elements back
        for(int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }

        return cnt;
    }

    // Merge Sort to count total inversions
    long long mergeSort(vector<int>& nums, int low, int high) {

        if(low >= high) return 0;

        int mid = low + (high - low) / 2;

        long long cnt = 0;

        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);

        cnt += merge(nums, low, mid, high);

        return cnt;
    }

    int minOperations(vector<int>& nums, vector<int>& locked, int k) {

        int n = nums.size();

        // Step 1: Count inversions using Merge Sort
        vector<int> tempNums = nums;

        long long swaps = mergeSort(tempNums, 0, n - 1);

        // Step 2: Mark inversion ranges
        vector<int> diff(n + 1, 0);

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                if(nums[i] > nums[j]) {

                    diff[i]++;
                    diff[j + 1]--;
                }
            }
        }

        // Step 3: Count covered locked indices
        int active = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++) {

            active += diff[i];

            if(active > 0 && locked[i] == 1) {
                cnt++;
            }
        }

        // Step 4: Check unlock limit
        if(cnt > k) {
            return -1;
        }

        // Step 5: Total operations
        return (int)(swaps + cnt);
    }
};