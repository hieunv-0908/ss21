#include<stdio.h>
#include<string.h>
typedef struct{
	int maSach;
	char tenSach[100];
	char tenTacGia[100];
	float giaSach;
	char theLoai[100];
}Book;

void EnterQuanityInfomation(Book Books[],int *len);
void SaveFile(Book books[],int len);
void loadFile(Book books[],int *len);

int main(){
int len;
Book Books[100];
int select;
do{
	printf("\n");
	printf("\n________MENU_________\n");
	printf("Lua chon 1:Nhap soluong va thong tin sach\n");
	printf("Lua chon 2:Luu thong tin sach vao file\n");
	printf("Lua chon 3:Lay thong tin sach tu file\n");
	printf("Lua chon 4:Hien thi thong tin sach\n");
	printf("Lua chon 5:Thoat\n");	
	
	printf("Moi ban nhap vao lua chon: ");
	scanf("%d",&select);
	getchar();
	
	switch(select){
		case 1:
			EnterQuanityInformation(Books,&len);
			break;
		case 2:
			SaveFile(Books,len);
			break;
		case 3:
			loadFile(Books,&len);
			break;
		case 4:
			displayBook(Books,len);
			break;
		case 5:
			break;
		default :
			printf("Lua chon loi !!!!!!Moi ban nhap lai\n");
			break;				
	}
	
}while(select!=5);

return 0;
}
//  nhap so luong va tung thong tin cua sach
void EnterQuanityInformation(Book Books[],int *len){
	printf("Moi ban nhap vao so luong sach\n");
	scanf("%d",&*len);
	getchar();
	for(int i=0;i<*len;i++){
		printf("Moi nhap ma sach:");
		scanf("%d",&Books[i].maSach);
		getchar();
		printf("Moi nhap ten sach: ");
		fgets(Books[i].tenSach,100,stdin);
		Books[i].tenSach[strcspn(Books[i].tenSach,"\n")]='\0';
		printf("Moi nhap ten tac gia: ");
		fgets(Books[i].tenTacGia,100,stdin);
		Books[i].tenTacGia[strcspn(Books[i].tenTacGia,"\n")]='\0';
		printf("Moi nhap gia sach: ");
		scanf("%f",&Books[i].giaSach);
		getchar();
		printf("Moi nhap the loai sach: ");
		fgets(Books[i].theLoai,100,stdin);
		Books[i].theLoai[strcspn(Books[i].theLoai,"\n")]='\0';
	}
}

	//luu mang vao file
void SaveFile(Book books[],int len){
	FILE *fileBook=fopen("Book.bin","wb");
	if(fileBook==NULL){
		printf("Luu file khong thanh cong\n");
	}else{
		fwrite(books,sizeof(Book),len,fileBook);
		printf("Luu file thanh cong\n");
	}
	
	
	fclose(fileBook);
	
}


void loadFile(Book books[],int *len){
	FILE *fileBook=fopen("Book.bin","rb");
	if(fileBook==NULL){
		printf("Mo file khog thanh cong");
	}else{
		*len=fread(books,sizeof(Book),100,fileBook);
		printf("Thong tin sach vua lay ra %d sach",*len);
	}
}

void displayBook(Book books[],int len){
	for(int i=0;i<len;i++){
		printf("%d\n",books[i].maSach);
		printf("%s\n",books[i].tenSach);
		printf("%s\n",books[i].tenTacGia);
		printf("%f\n",books[i].giaSach);
		printf("%s\n",books[i].theLoai);
		printf("_____________________");
	}
}


