/*leetcode 66
  数组表示：整形数字
  末尾加1
  要考虑到进位造成的数组 size + 1
*/

int *plusOne(int *digits, int digitSize, int *returnSize){
    //从个位(数组末尾)往前看
    for(int i=digitSize-1; i>=0; i--){
        //判断是否需要进位
        if(digits[i] == 9){
            digits[i] = 0; //进位后置0
        }else{ //不涉及进位
            digits[i]++;
            *returnSize = digitSize;
            return digits;
        }

    }

    int *result = (int *)malloc((digitSize+1)*sizeof(int));
    memset(result,0,(digitSize+1)*sizeof(int));
    result[0] = 1; //最高位 即近位置1

    *returnSize = digitSize + 1;

    return result;
}