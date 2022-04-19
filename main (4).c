// stack operations push(),pop()
#include<stdio.h>
#include<stdlib.h>

struct stack
{
  int size;
  int *arr;
  int top;
};

int isEmpty(struct stack *ptr)
{
  if(ptr->top==-1)
    return 1;
  else
    return 0;
}

int isFull(struct stack *ptr)
{
  if(ptr->top== ptr->size - 1)
    return 1;
  else
    return 0;
}

void push(struct stack *ptr,int val){
  if(isFull(ptr)){
    printf("stack overflow! can not push %d to stack\n",val);
  }
  else{
    ptr->top++;
    ptr->arr[ptr->top]= val;
  }
}

int pop(struct stack *ptr){
  if(isEmpty(ptr)){
    printf("stack underflow ! cna't pop \n");
    return -1;
  }
  else{
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
  }
}

int main(){
  struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
  sp->size =10;
  sp->top = -1;
  sp->arr = (int*)malloc(sp->size * (sizeof(int)));
  printf("stack has been created successfully\n");

  printf("before pushing : Full %d\n",isFull(sp));
  printf("before pushing :Empty %d\n",isEmpty(sp));

  // pushing element 
  push(sp,1);
  push(sp,23);
  push(sp, 99);
  push(sp, 75);
  push(sp, 3);
  push(sp, 64);
  push(sp, 57);
  push(sp, 46);
  push(sp, 89);
  push(sp, 6); // pushed 10 value 
  push(sp,22);// stack over flow condition
  printf("After pushing, Full: %d\n", isFull(sp));
  printf("After pushing, Empty: %d\n", isEmpty(sp));

  // pop operation 
  printf("popped %d from stack\n",pop(sp));// Lastin first out 
  printf("popped %d from stack\n",pop(sp));
  printf("popped %d from stack\n",pop(sp));
  
  
  

  return 0;
}