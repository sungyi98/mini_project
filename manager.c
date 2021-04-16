#include "manager.h"

void listProduct(Product *p[], int count){            //전체 등록된 제품 리스트 출력하는 함수
	printf("\nNo    제품명      중량     판매가격    별점(별점개수)\n");
       	printf("-----------------------------------------------------\n");
	for(int i=0;i<count;i++){
		if(p[i]==NULL) continue;
		printf("%d    ",i+1);
		readProduct(*p[i]);
	}
}

int selectDataNo(Product *p[], int count){             // 사용자가 선택한 번호를 받는 함수
	int no;
	listProduct(p, count);
	printf("번호는 (취소:0)? ");
	scanf("%d",&no);
	return no;

}
						    
void saveData(Product *p[], int count){
	FILE *fp;
	fp=fopen("product.txt","wt");
	for(int i=0; i<count; i++)
	{
		if(p[i]==NULL) continue;
		fprint(fp,"%s\t%.1f\t%d\t%d\t%d\n", p[i]->name, p[i]->weight, p[i]->price, p[i]->rating, p[i]->rating_num);
	}
	fclose(fp);
	printf("=> 저장됨!");
}

int loadData(Product *p[]){
	int i=0;
	char line[100];
	FILE *fp;
	fp=fopen("product.txt","rt");
	if(fp==NULL) printf("=> 파일 없음\n");
	else{
		while(fgets(line, sizeof(line), fp)!=NULL){
			p[i]=(Product *)malloc(sizeof(Product));
			char *ptr=strtok(line, "\t");
			strcpy(p[i]->name,ptr);
			ptr=strtok(NULL,"\t");
			p[i]->weight=atof(ptr);
			ptr=strtok(NULL,"\t");
			p[i]->price=atoi(ptr);
			ptr=strtok(NULL,"\t");
			p[i]->rating=atoi(ptr);
			ptr=strtok(NULL,"\t\n");
			p[i]->rating_num=atoi(ptr);

			printf("%d",p[i]->rating);
			printf("%d",p[i]->rating_num);
			i++;
		}
		printf("=> 로딩성공!\n");
	}
	fclose(fp);
	return i;
}
void searchProduct(Product *p[], int count){
	int scnt=0;
	char search[20];

	printf("검색할 이름? ");
	getchar();
	scanf("%[^\n]s",search);
	printf("*****************************************************\n");
	printf("No    제품명    중량    판매가격    별점    별점개수\n");
	for(int i=0; i<count; i++){
		if(p[i]==NULL) continue;
		if(strstr(p[i]->name,search)){
			printf("%2d  ",i+1);
			scnt++;
		}
	}
	if(scnt==0) printf("=> 검색된 데이터 없음!");
	printf("\n");
}
