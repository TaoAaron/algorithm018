/*Leetcode 26
 排序数组
 原地删除 重复出现元素
*/

int removeDuplicates(int *nums, int numSize){
    //合法性判断
    if(numSize < 2) return numSize;

    int j=1; //记录不重复数字

    for(int i=1; i<numSize; i++){
        if(nums[i-1] != nums[i]){ //第二个数开始 和 前一个数比较
            nums[j++] = nums[i]; //用不重复数字 去覆盖重复数字的位置
        }
    }

    return j;
}