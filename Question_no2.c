#include<stdio.h>
#include<string.h>
void authenticaton(char cnic[],char name[]){
    
    printf("enter your CNIC-number:\n");
    scanf("%s",cnic);
    printf("enter your name:\n");
    scanf("%s",name);
    return;
    }
void inventory( char product_code[4][4],int quantity_in_stock[],int price_per_product[]){
   printf("PRODUCT CODE \t QUANTITY IN STOCK \t PRICE PER PRODUCT\n");
   printf("-----------------------------------------------------\n");
    int i;
   for(i=0;i<4;i++){
    printf("%-12s\t\t%-8d\t\t%-8d\n",product_code[i],quantity_in_stock[i],price_per_product[i]);
    }
    printf("\n-----------------------------------------------------");
    printf("\n-----------------------------------------------------\n");

return;
}
void update_inventory(char product_code[4][4],int quantity_in_stock[],int price_per_product[]){
    char product2[4];
    int quantity2;
    printf("enter the product code:\n");
    int i,j;
    scanf("%s",&product2);
   
        for(j=0;j<4;j++){
            if(strcmp(product2,product_code[j])==0){
                if(quantity_in_stock[j]>0){
                     printf("enter quantity to deduct:\n");
                     scanf("%d",&quantity2);
                     if(quantity_in_stock[j]>=quantity2){
                     quantity_in_stock[j]-=quantity2;
                    return;
                    }
                    else{
                        printf("insuficient!\n");
                    }
                }
                else{
                printf("out of stock!\n");
               }

            }
            // else{
            //     // printf("product not found\n");
            // }
        }

    
return;
}
void add_to_cart(char product_code[4][4],int quantity_in_stock[],int price_per_product[],int *bill){
    char product[4];
    int quantity;
    
    printf("enter the product code:\n");
    int i,j;
    scanf("%s",&product);
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(strcmp(product,product_code[j])==0){
                if(quantity_in_stock[i]<=0){
                        printf("out of stock!\n");
                        return;
                }
                else{
                printf("enter quantity to add to cart:\n");
                scanf("%d",&quantity);
                if(quantity_in_stock[i]>=quantity){
                quantity_in_stock[i]-=quantity;
                *bill=quantity*price_per_product[i];
                printf("item added sucessfully!\n");
                return;
                }
                else{
                    printf("insuficient!\n");
                }
                }
               }
            // else{
            //     printf("product not found\n");
            // }
        }

    }
    return;
}
void display_total_bill(int *bill){
    char voucher;
    printf("We are offering a promocode of Eid2025 DO you have voucher(y/n):\n");
    scanf(" %c",&voucher);
    if(voucher=='y'){
        (*bill)*=0.75;
    }
    // else{
    //     *bill=bill;
    // }
    printf("total bill=%d\n",*bill);
    return;
}
void invoice(char cnic[],char name[],int bill){
  printf("CNIC number:%s\nname:%s\ntotal bill:%d\n",cnic,name,bill);
  return;
}

int main(){
    char cnic[14];
    char name[30];
    char product_code[4][4]={"001","002","003","004"};
    int quantity_in_stock[4]={50,10,20,8};
    int price_per_product[4]={100,200,300,150};
    int bill=0;
    int choice=-1;
    
    while(choice!=7){
    printf("1)coustomer information\n2)display inventory\n3)upadate inventory\n4)add to cart item\n5)display total bill \n6)show invoice \n7)Exit the sytem\n");
scanf("%d",&choice);
    switch(choice){
        case 1:
        authenticaton(cnic,name);
         break;
         case 2:
          inventory(product_code,quantity_in_stock,price_per_product);
         break;
        case 3:
        update_inventory(product_code,quantity_in_stock,price_per_product);
        break; 
        case 4:
        add_to_cart(product_code,quantity_in_stock,price_per_product,&bill);
        break;
        case 5:
        display_total_bill(&bill);
        break;
        case 6:
        invoice(cnic,name,bill);
        break;
        case 7:
        return 0;
        break;
        default:
        printf("invalid!");

        


    }
    }
     
  return;  
}