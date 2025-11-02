#include<stdio.h>
void Add_new_books(int isbns[],char titles[][50],float prices[],int quantities[],int *count){
    int i,ask,i2;
    for(i=*count;i<100;i++){ 
    printf("enter ISBNs of book\n");
     scanf("%d",&isbns[i]);
     if(count>=1){
           for(i2=0;i2<*count;i2++){
            if(isbns[i]==isbns[i2]){
                printf("duplicate isbns number\ntry again\n");
                return;
            }
           }
     }
     printf("enter title of book\n");
     scanf("%s",&titles[i]);
    printf("enter the price of book\n");
    scanf("%f",&prices[i]);
    printf("enter the quantities of books\n");
    scanf("%d",&quantities[i]);
    (*count)++;
    printf("do you want to store more books\n1 for yes\n0 for no\n");
    scanf("%d",&ask);
    if(ask==0){
        break;
    }
    
    
}

return;
}
void process_a_sale(int isbns[],int quantities[],int count){
          int isbns_ask,i,quantity_ask,ask;
         printf("enter the isbns of book you want to purchase\n");
         scanf("%d",&isbns_ask);
         for(i=0;i<count;i++){
               if(isbns_ask==isbns[i]){
                   printf("enter the quantity you want to purchase\n");
                   scanf("%d",&quantity_ask);
                   if(quantity_ask<quantities[i]){
                    quantities[i]-=quantity_ask;
                   }
                   else{
                    printf("insuficient books!\n");
                   }
               }
               printf("do you want to purchase more books\n1 for yes\n0 for no\n");
              scanf("%d",&ask);
              if(ask==0){
                break;
              }
         } 
     return;      
}
void Generate_low_stock_report(int isbns[],char titles[][50],float prices[],int quantities[],int count){
        int i;
        for(i=0;i<count;i++){
             if(quantities[i]<5){
                printf("---DATA of books less than 5 remaining---\n");
                printf("ISBNs:%d\ntitle:%s\nprice:%f\nquantity:%d\n",isbns[i],titles[i],prices[i],quantities[i]);
             }
        }
        return;
}
int main(){
int count=0;
int i;
int isbns[100];
 char titles[100][50];
 float prices[100];
 int quantities[100];
int choice;
while(1){
printf("Menu:\nenter the number to perform action:\n1)Add new book\n2)process a sale\n3)Generate Low-stock report.\n");
scanf("%d",&choice);
switch(choice){
  case 1:
    Add_new_books(isbns,titles,prices,quantities,&count);
    break;
  case 2:
    process_a_sale(isbns,quantities,count);
    break;
  case 3:
    Generate_low_stock_report(isbns,titles,prices,quantities,count);
    break;
  default:
     printf("invalid try again");
    }
    }
return 0;

}