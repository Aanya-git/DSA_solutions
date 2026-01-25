class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = n - 1;

        if (n == 1) return nums[0];

        while (st < end) {
            int mid = st + (end - st) / 2;

            // make sure mid is not at boundary
            if (mid > 0 && mid < n - 1) {
                if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                    return nums[mid];
                }
            }

            // odd index case
            if (mid % 2 == 1) {
                if (nums[mid] == nums[mid - 1]) {
                    // pair is correct → single is on right
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            // even index case
            else {
                if (nums[mid] == nums[mid + 1]) {
                    // pair is correct → single is on right
                    st = mid + 2;
                } else {
                    end = mid;
                }
            }
        }

        return nums[st];
    }
};
