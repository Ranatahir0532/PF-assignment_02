#include<stdio.h>
#include<string.h>
void encode(){
printf("enter message:\n");
char message[56];
getchar();
fgets(message,sizeof(message),stdin);

int i;
char temp;  
int size=strlen(message);
if(message[size-1]=='\n'){
 message[size-1]='\0';
 size--;
}

for(i=0;i<size/2;i++){
  temp=message[i];
  message[i]=message[size-i-1];
  message[size-i-1]=temp;
}
int new[56];
for(i=0;i<size;i++){
new[i]=(int)message[i];
}
for(i=0;i<size;i++){
   new[i]=new[i]^(1<<1);
   new[i]=new[i]^(1<<5);
}
for(i=0;i<size;i++){
   message[i]=(char)new[i];
}
for(i=0;i<size;i++){
printf("%c",message[i]);
}
return;
}

void decode(){
char code[100];
printf("enter code:\n");
getchar();
fgets(code,sizeof(code),stdin);
int size=strlen(code);
if(code[size-1]=='\n'){
   code[size-1]='\0';
   size--;
}
int i;
char temp;
int new[100];
for(i=0;i<size;i++){
  new[i]=(int)code[i];
}
for(i=0;i<size;i++){
   new[i]=new[i]^(1<<1);
   new[i]=new[i]^(1<<5);
}
for(i=0;i<size;i++){
code[i]=(char)new[i];
}
for(i=0;i<size/2;i++){
temp=code[i];
code[i]=code[size-i-1];
code[size-i-1]=temp;
}
for(i=0;i<size;i++){
   printf("%c",code[i]);
}

}

int main(){
 
 int choice=-1;
 while(choice!=0){
 printf("enter any choice:\n1)encode message \n2)decode message\n3)exit!\n");
 scanf("%d",&choice);
 switch (choice)
 {
 case 1:
     encode();
    break;
 case 2:
     decode();
    break;
    case 3:
    printf("exiting..........");
    return;
    break;
 default:
    break;
 }
 }
 return 0;
}