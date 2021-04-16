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
						    


