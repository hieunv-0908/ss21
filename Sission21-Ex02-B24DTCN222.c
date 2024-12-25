#include<stdio.h>
#include<stdlib.h>

int main(){
FILE *file;
char input[100];
file=fopen("bt01.txt","r");
if(file==NULL){
	printf("file khong the mo duoc");
	return 1;
}
char ch=fgetc(file);
if(ch!=EOF){
	printf("%c\n",ch);
}else{
	return 1;
}


fclose(file);
return 0;
}


