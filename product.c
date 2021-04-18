#include "product.h"

int createProduct(Product *p)
{
	getchar();
	printf("제품명은?: ");
	scanf("%[^\n]s",p->name);
	printf("중량은?: ");
	scanf("%f",&p->weight);
	printf("판매가격은? ");
	scanf("%d",&p->price);
	printf("별점은? ");
	scanf("%d",&p ->rating);
	printf("별점개수는? ");
	scanf("%d",&p->rating_num);
	printf("=> 생성 성공!\n");
	return 1;
}
void readProduct(Product p){
	printf("%s   %.1fg   %d원   %d점(%d개)\n",p.name,p.weight,p.price,p.rating,p.rating_num);
	return;
}
int updateProduct(Product *p)
{
	getchar();
	printf("새 제품명은?: ");
	scanf("%[^\n]s",p->name);
	printf("새 중량은? ");
	scanf("%f",&p ->weight);
	printf("새 판매가격은? ");
	scanf("%d",&p->price);
	printf("새 별점은?: ");
	scanf("%d",&p ->rating);
	printf("새 별점개수는? ");
	scanf("%d",&p->rating_num);
	printf("=> 수정 성공!\n");
	return 1;
}
void deleteProduct(Product *p[], int index){
	p[index-1]=NULL;
}
int selectMenu(){
	int menu;
	printf("\n\n***** Menu *****\n");
	printf("1. 메뉴조회\n");
	printf("2. 메뉴추가\n");
	printf("3. 메뉴수정\n");
	printf("4. 메뉴삭제\n");
	printf("5. 파일저장\n");
	printf("6. 이름으로 검색\n");
	printf("7. 별점으로 검색\n");
	printf("8. 가격으로 검색\n");
	printf("0. 종료\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d",&menu);
	return menu;
}
void listProduct(Product *p[], int count){
	printf("No    제품명    중량    판매가격    별점(별점개수)\n");
	printf("--------------------------------------------------\n");
	for(int i=0; i<count; i++){
		if(p[i]==NULL) continue;
		printf("%d    ",i+1);
		readProduct(*p[i]);
	}
}
int selectDataNo(Product *p[], int count){
	int no;
	listProduct(p,count);
	printf("번호는 (취소:0)? ");
	scanf("%d",&no);
	return no;
}
void searchProduct(Product *p[], int count){
	int scnt =0;
	char search[20];
	printf("검색할 이름? ");
	getchar();
	scanf("%[^\n]s",search);
	printf("*****************************************************\n");
	printf("No    제품명    중량    판매가격    별점    별점개수\n");
	for(int i=0;i<count;i++){
		if(p[i] == NULL) continue;
		if(strstr(p[i]->name,search)){
			printf("%2d  ",i+1);
			readProduct(*p[i]);
			scnt++;
		}
	}
	if(scnt ==0) printf("=> 검색된 데이터 없음!");
	printf("\n");
}
