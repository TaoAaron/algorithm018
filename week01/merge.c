/*
    leetcode 88 merge
    nums1 和 nums2 都有序
    nums2 和并到 nums1 中
    nums1 空间足够 >= m+n

    采用倒序遍历数组，大的数往nums1后面放
    nums2如果有未处理完的，填入nums1
*/

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n){
    int i = m-1;    //nums1 末尾
    int j = n-1;   //nums2 末尾
    while (i>=0 && j>=0)
    {
        if(nums1[i] > nums2[j]){  //比较后 移走大的
            nums1[i+j+1] = nums1[i];
            i--;
        }else{
            nums1[i+j+1] = nums2[j];
            j--;
        }
    }
    
    //如果j有未处理的元素
    while(j>=0){
        nums1[j] = nums2[j];
        j--;
    }

}