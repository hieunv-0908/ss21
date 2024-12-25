#include<stdio.h>
#include<stdlib.h>

int main(){
FILE *file;
char input[100];
file=fopen ("bt01.txt","w");
if(file==NULL){
	printf("file khong the mo duoc");
	return 1;
}
printf("Nhap vao mot chuoi bat ki");
fgets(input,100,stdin);

fprintf(file,"%s",input);

fclose;
return 0;
}

