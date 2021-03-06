## 为什么需要位运算
&emsp;机器里数字的表示方式和存储格式就是二进制  
&emsp;位运算的计算方式更符合计算机的特性，运算效率比普通运算高。  

## 位运算符  
&emsp;左移&emsp;<<  
&emsp;右移&emsp;>>  
&emsp;按位或&emsp;|  
&emsp;按位与&emsp;&  
&emsp;按位取反&emsp;~  
&emsp;按位异或&emsp;^  

## 指定位置的运算
&emsp;1、将x最右边的n位清零 ： x & (~0 << n)  
&emsp;2、获取x的第n位值: (x>>n) * 1  
&emsp;3、获取x的第n位的幂值：x&(1<<n)  
&emsp;4、仅将第n位置1：x | (1<<n)  
&emsp;5、仅将第n为清零：x | (~(1<<n))  
&emsp;6、将x最高位至第n位(含清零): x&((1<<n)-1)  

## 实战位运算要点  
• 判断奇偶：  
&emsp;x%2 == 1 -> (x&1) == 1  
&emsp;x%2 == 0 -> (x&1) == 0  
• 乘二、除二  
&emsp;	x >> 1 -> x/2  
&emsp;	x << 1 -> x*2  

• x = x & (x-1) 清零最低位的1  
• x & -x -> 得到最低位的1  
&emsp;x & ~x -> 0  