/*
leetcode 33 搜索旋转排序数组
解题思路：通过有序，明确的上下边界，数组 三个条件 尝试用二分法去解决
时间复杂度：O(logn)
空间复杂度：O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //左右边界 设定
        int left = 0, right = nums.size() - 1, mid = 0;

        while (left <= right) {

            if (nums[mid] == target) return mid;
            //通过mid和left值的比较 可以确定有序的是左半部还是右半部
            if (nums[mid] >= nums[left]) { //左半部 升序
                if (target >= nums[left] && target < nums[mid]) { //target 在 left 和 mid 之间
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {    //右半部升序
                if (target > nums[mid] && target <= nums[right]) { //target 在 mid 和 right之间
                    left = mid + 1;
                } else {
                    right = mid - 1;
                } 
            }         
    
        }
        return -1;
    }
};