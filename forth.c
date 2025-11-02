#include<stdio.h>
void push(int stack[], int *top, int maxSize){
if(*top==maxSize-1){
 printf("stack overflow!\n");
return;
}
printf("enter the value:");
(*top)++;
scanf("%d",&stack[*top]);

return;
}
void pop(int stack[], int *top){
if(*top==-1){
    printf("stack underflow!\n");
    return;
}
  printf("poped element =%d\n",stack[*top]);
  (*top)--;
  if(*top==-1){
    printf("stack is empty is now!\n");
  }
  printf("top element is removed now!\n");
  return;
}

void peek(int stack[], int *top){
    if(*top==-1){
        printf("stack is empty!\n");
        return;
    }
printf("top element is %d\n",stack[*top]);
}
void display(int stack[], int *top){
    int i=0;
    printf("--------------whole stack--------------\n");
    for(i=(*top);i>=0;i--){
        printf("|     %d     |\n",stack[i]);
    }
    printf("______________\n");
    return;

}
int main(){
    
    int stack[4];
   int top=-1;
   int maxSize=4;
   int choice=-1;
  while(choice!=0){
   printf("enter your choice:\n1)push\n2)pop\n3)peek\n4)display\n5)exit\n");
   scanf("%d",&choice);
        switch(choice){
            case 1:
            push(stack,&top,maxSize);
             break;
             case 2:
             pop(stack,&top);
             break;
             case 3:
             peek(stack,&top);
             break;
             case 4:
             display(stack,&top);
             break;
             case 5:
             printf("exiting.................");
             return;
             break;
             default:
             printf("invalid!");
             break;


}
}
}