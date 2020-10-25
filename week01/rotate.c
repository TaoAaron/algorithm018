/*
leetcode 189 rotate
思路：翻转
整个数组翻转
以移动位置k为界
翻转k前半部分，翻转k后半部分
*/

void reverse(int *nums, int s, int e){
    while(s < e){
        int temp = nums[s];
        nums[s] = nums[e];
        nums[e] = temp;
        s++;
        e--;
    }
}

void rotate(int *nums, int numsSize,int k){
    if(numsSize < 2) return numsSize;

    k = k % numsSize;
    if(!k) return;

    reverse(nums,0,numsSize-1);
    rverse(nums,0,k-1);
    reverse(nums,k,numsSize-1);
    
}