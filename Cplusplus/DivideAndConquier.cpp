#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return helper(nums, 0, nums.size()).first;
    }
    pair<int, int> helper(vector<int>& nums, int l, int r) {
        if (l == r - 1) {
            return make_pair(nums[l], 1);
        }
        int mid = l + (r - l) / 2;
        pair<int, int> maj_left = helper(nums, l, mid);
        pair<int, int> maj_right = helper(nums, mid, r);
        int extra_left = maj_left.second;
        int extra_right = maj_right.second;
        if (maj_right.first == maj_left.first) {
            int maj = maj_left.first;
            int extra = extra_left + extra_right;
            return make_pair(maj, extra);
        }
        else if (extra_right > extra_left) {
            int maj = maj_right.first;
            int extra = extra_right - extra_left;
            return make_pair(maj, extra);
        }
        else {
            int maj = maj_left.first;
            int extra = extra_left - extra_right;
            return make_pair(maj, extra);
        }
    }
};