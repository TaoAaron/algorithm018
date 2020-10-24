 /*暴力解*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *result = (int *)malloc(sizeof(int)*2); //returned array must be malloced
    *returnSize = 0;

    //两重循环 
    for(int i=0; i<numsSize-1; i++){
        for(int j=i+1; j<numsSize; j++){
            if(nums[i] + nums[j] == target){
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return result;
}