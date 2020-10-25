/*
将所有0移动到数组末尾
要保持非0元素的相对顺序
不能拷贝额外数组
*/

void moveZeros(int *nums, int numSize){
    int j=0; //记录非0元素的位置

    for(int i=0; i<numSize; i++){
        if(nums[i] != 0){
            nums[j] = nums[i]; //非0元素 将其移动
            if(j != i){
                nums[i] = 0; //保留 0元素
            }
            j++;    //j+1 要在j!=i 处理之后
        }
    }
}