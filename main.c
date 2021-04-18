#include "manager.h"

int main(){
	Product *p[100];
	int count=0, index=0;
	int menu;
	int exit =1;
#ifdef DEBUG
	printf(" => DEBUG MODE \n");
#endif
	count=loadData(p);
	index=count;
	while(exit){
		menu=selectMenu();
		if(menu==0){ 
			printf("종료됨!\n");
			exit=0;
		}
		if(menu==1||menu==3||menu==4){
			if(count==0) continue;
		}
		if(menu==2){
			p[index]=(Product *)malloc(sizeof(Product));
			count+=createProduct(p[index++]);
		}
		else if(menu ==1){
			if(count>0) listProduct(p,index);
		}
		else if(menu==3){
		       int no= selectDataNo(p,index);
		       if(no>0) updateProduct(p[no-1]);
		}
		else if(menu==4){
			int no=selectDataNo(p,index);
			if(no>0){
				printf("정말로 삭제하시겠습니까? (삭제:1)");
				int delok;
				scanf("%d",&delok);
				if(delok==1){
					deleteProduct(p,index);
					count--;
					printf("=> 삭제됨!\n");
				}
			}
		}
		else if(menu ==5)
		{
			saveData(p,index);
		}
		else if(menu==6)
		{
			printf("** 이름을 입력해 주세요 **\n");
			searchProduct(p,index);
		}
		else if(menu==7)
		{
			printf("**  별점을 입력해 주세요 **\n");
			searchProduct_rating(p,index);
		}
		else if(menu==8)
		{
			printf("** 가격의 최고한도를 입력해 주세요 **\n");
			searchProduct_price(p,index);
		}
		else continue;
	}
	return 0;
}
