class Solution {
public:
    int minimizeXor(int nums1, int nums2) {
        function<int(int)> count = [&](int num) -> int {
            int cnt = 0;
            while (num > 0) {
                cnt += (num & 1);
                num >>= 1;
            }
            return cnt;
        };

        auto add = [&](int nums, int cnt) -> int {
            int pos = 0;
            while (cnt > 0) {
                while (((nums >> pos) & 1)) { 
                    pos++;
                }
                nums |= (1 << pos);
                cnt--; 
            }
            return nums;
        };

        auto remove = [&](int nums, int rem) -> int {
            while (rem) {
                nums = (nums & (nums - 1));
                rem--;
            }
            return nums;
        };

        int no1 = count(nums1);
        int no2 = count(nums2);

        if (no1 == no2) {
            return nums1;
        }
        if (no1 < no2) {
            return add(nums1, no2 - no1);
        }
        return remove(nums1, no1 - no2);
    }
};
