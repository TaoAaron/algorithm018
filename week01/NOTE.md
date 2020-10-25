学习笔记

数组时间复杂度
	prepend	O(1)
	append	O(1)
	lookup	O(1)
	insert	O(n)
	delete	O(n)

数组的题目：
暴力解决->直接枚举
优化：
    针对有序数组，采取双指针的方法; 时间复杂度高的，可先进行一轮排序nlogn
    采用哈希表
特殊技巧：在数组旋转题目里，用3次reverse完成


链表时间复杂度
	prepend	O(1)
	append	O(1)
	lookup	O(n)
	insert	O(1)
	delete	O(1)

链表的题目：
    注意next指针的操作
    合并链表，为了操作方便可以增加1个dummy node
    检测循环链表，可以用快慢指针


跳表：针对元素有序情况进行加速
本质：空间换时间
	跳表(skip list)对标的是平衡树(AVL Tree)和二分查找，是一种插入/删除/搜索都是O(log n)的数据结构。
	最大的优势：原理简单、容易实现、方便扩展、效率更高。

stack：先入后出；添加、删除皆为O(1)
queue：先入先出；添加、删除皆为O(1)

Deque
理解为：两端可以进出的Queue Deque-double ended queue
插入和删除都是O(1)操作

括号匹配，雨水问题可以用栈去解