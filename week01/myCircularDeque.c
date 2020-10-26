/*
用数组来实现
技巧: 通过%来解决循环的问题
*/
#include <stdbool.h>

typedef struct {
    int headIndex;
    int tailIndex;
    int size;
    int *array;
} MyCircularDeque;

bool myCircularDequeIsFull(MyCircularDeque* obj)；
bool  myCircularDequeIsEmpty(MyCircularDeque* obj)；


MyCircularDeque* myCircularDequeCreate(int k){
    MyCircularDeque* p = malloc(sizeof(MyCircularDeque));
    int* array = malloc((k+1)*sizeof（int));
    p->headIndex = 0;
    p->tailIndex = 0;
    p->size = k + 1;

    return p;
}

 bool myCircularDequeInsertFront(MyCircularDeque* obj, int value){
     if(myCircularDequeIsFull(obj)) return false;

     obj->headIndex = (obj->headIndex+obj->size-1) % obj->size;
     obj->array[obj->headIndex]= value;  

     return true;
 }

 bool myCircularDequeDeleteFront(MyCircularDeque* obj){
     if(myCircularDequeIsEmpty(obj)) return false;

     obj->headIndex = (obj->headIndex+1) % obj->size;

     return true;
 }
 
 bool myCircularDequeInsertLast(MyCircularDeque* obj){
     if(myCircularDequeIsFull(obj)) return faluse;

    obj->tailIndex = (obj->tailIndex+1) % obj->size;
    return true;
 }

 bool myCircularDequeDeleteLast(MyCircularDeque* obj, int value){
     if( myCircularDequeIsEmpty(obj)) return false;
    
    obj->tailIndex = (obj->tailIndex-1+obj->size) % obj->size; //边界处理

    return true;
 }

bool myCircularDequeIsFull(MyCircularDeque* obj) {

	return (obj->headIndex == (obj->tailIndex+1) % obj->size) ? true : false;

}


bool  myCircularDequeIsEmpty(MyCircularDeque* obj){
    return (obj->headIndex == obj->tail) ? true : false;
}

 void mycircularDequeFree(MyCircularDeque* obj){
     free(obj->array);
     free(obj);
 }
