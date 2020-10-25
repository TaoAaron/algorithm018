/*
    leetCode 21 mergeTwolist 

    为了方便操作可以创建一个头节点
    l1和l2 把较小的依次 放到头节点后
    返回头节点

*/
struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode * mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode head;
    struct ListNode *pre = &head;

    while(l1 && l2){
        if(l1->val < l2->val){
            pre->next = l1;
            l1 = l1->next;     

        }else{
            pre->next = l2;
            l2 = l2->next;
        }
        
        pre = pre->next;
    }

    //如果l2 l1有未处理的元素
    pre->next = (NULL == l1 ? l2 : l1);

    return head.next;

}
