#include "manager.h"

void saveData(Product *p[], int count){
	FILE *fp;
	fp=fopen("product.txt","wt");
	for(int i=0; i<count; i++)
	{
		if(p[i]==NULL) continue;
		fprintf(fp,"%s\t%.1f\t%d\t%d\t%d\n", p[i]->name, p[i]->weight, p[i]->price, p[i]->rating, p[i]->rating_num);
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
			i++;
		}
		printf("=> 로딩성공!\n");
	}
	printf("넘어감!");
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
			readProduct(*p[i]);
			scnt++;
		}
	}
	if(scnt==0) printf("=> 검색된 데이터 없음!");
	printf("\n");
}
