#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//logic ham
void printMenu(){
	printf("***QUAN LY THU VIEN***\n");
	printf("\n");
	printf("\t-Menu-\n");
	printf("1.Nhap so luong va thong tin sach\n");
	printf("2.Hien thi sach\n");
	printf("3.Them sach\n");
	printf("4.Sua thong tin sach\n") ;
	printf("5.Xoa sach\n");
	printf("6.Tim kiem sach theo ten \n");
	printf("7.Sap xep theo gia tien\n");
	printf("8.Thoat\n");
} 
void format(char *name){
	size_t len=strlen(name);
	int newword=1;
	for(int i=0;i<len;i++){
		if(isspace(*(name+i))){
			newword=1;
		}
		else if(newword==1){
			*(name+i)=toupper(*(name+i));
			newword=0;
		}
		else{
			*(name+i)=tolower(*(name+i));
		}
	}
}

void libraryInput(struct Book **book,int *n){
	if(*book!=NULL){
		free(*book);
	}
	
	printf("Enter the number of books :");
	scanf("%d",n);
	if(*n<1){
		printf("Invalid number of book !\n");
		exit(1);
	}
	getchar();
	*book=(struct Book*)malloc(*n*sizeof(struct Book));
	if(*book==NULL){
		printf("Memory allocation failed !\n");
		exit(1);
	}
	for (int i=0;i<*n;i++){
		printf("Enter book %d-th:\n",i+1);
		printf("Enter book ID: ");
		scanf("%d", &(*book)[i].bookId);
		getchar(); 
		printf("Enter title book :");
		fgets((*book)[i].title,30,stdin);
		(*book)[i].title[strcspn((*book)[i].title,"\n")]='\0';
		format((*book)[i].title);
		printf("Enter price book:");
		scanf("%d",&(*book)[i].price);
		getchar();
		printf("Enter author book:");
		fgets((*book)[i].author,30,stdin);
		(*book)[i].author[strcspn((*book)[i].author,"\n")]='\0';
		format((*book)[i].author);
		printf("\n");
	}
	
}

void updateBook(struct Book *book,int n){
	printf("Enter ID of book:",n);
	int bookID,i;
	int check=0;
	scanf("%d",&bookID);
	getchar();
	for(i=0;i<n;i++){
		if(book[i].bookId==bookID){
			printf("Update title: ");
			fgets(book[i].title,30,stdin);
			book[i].title[strcspn(book[i].title,"\n")]='\0'; 
			
		}
	}
	
}
