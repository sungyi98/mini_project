#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[100];
	float weight;
	int price;
	int rating;
	int rating_num;
}Product;

int createProduct(Product *p);
void readProduct(Product p);
int updateProduct(Product *p);
int selectMenu();
void deleteProduct(Product *p[], int index);
void listProduct(Product *p[], int count);
int selectDataNo(Product *p[], int count);
void searchProduct(Product *p[], int count);
