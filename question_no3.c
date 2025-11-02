#include<stdio.h>

void update(int grid[][3]){
int row;
int col;
printf("enter cordinates of a secotr:\n");
scanf("%d",&row);
scanf("%d",&col);
if(row>2 || row<0 || col>2 || col<0){
    printf("invalid coordinates!");
    return;
}
int chose,act;
printf("enter to update:\n1)power status\n2)overload warning\n3)maintenance required\n");
scanf("%d",&chose);
printf("enter the action 1 for \"ON\" 0 for \"off\"\n");

scanf("%d",&act);
int bitset=1<<(chose-1);
if(act==1){
    grid[row][col] |= bitset;
     }
else{
    grid[row][col] &= ~bitset;
    
}
printf("sector (%d,%d) updated status=%d\n",row,col,grid[row][col]);

}

void query(int grid[][3],int *power,int *overload,int *maintance){
    int row,col;
    printf("enter the cordinates:");
    scanf("%d %d",&row,&col);
    if(row>2 || row<0 || col>2 || col<0){
    printf("invalid coordinates!");
    return;
}
    int status=grid[row][col];
   printf("power status:%s\n",(status &(*power))?"yes":"no");
   printf("overload warning:%s\n",(status&(*overload))?"yes":"no");
   printf("maintenance required:%s\n",(status&(*maintance))?"yes":"no");


}
void dignostic(int grid[][3],int *power,int *maintance,int *overload){
int i,j,maintances=0,overloads=0;

int status;
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        status=grid[i][j];
       if(status&(*maintance)){
            maintances++;
        }
         if(status&(*overload)){
             overloads++;
        }
    }
   

}
printf("total overloaded secotors:%d\n",maintances);
printf("total maintenance required sectors:%d\n",overloads);
}

int main(){
int power=(1<<0);
int overload=(1<<1);
int maintance=(1<<2);
int grid[3][3]={0};
int choice=-1;

while (choice!=0){
printf("select any opperation:\n1)update sector status\n2)query sector status\n3)run system dignostic\n");
scanf("%d",&choice);
{
    switch (choice)
    {
    case 1:
        update(grid);
        break;
    case 2:
        query(grid,&power,&overload,&maintance);
        break;
    case 3:
        dignostic(grid,&power,&overload,&maintance);
        break;

    default:
    printf("invalid!");
    break;
        
    }
    
}
}
return 0;
}