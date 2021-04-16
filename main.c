#include "product.h"
#include "manager.h"

int main(){
	Product *p[100];
	int count=0, index=0;
	int menu;
#ifdef DEBUG
	printf(" => DEBUG MODE \n");
#endif
	count=loadData(p);
	index=count;
	while(1){
		menu=selectMenu();
		if(menu==0){ 
			printf("종료됨!\n");
			break;
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
			searchProduct(p,index);
		}
	}
	return 0;
}
