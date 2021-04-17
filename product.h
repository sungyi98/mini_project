#ifndef _PRODUCT_H
#define _PRODUCT_H

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
int selectDataNo(Product *p[], int count);
void saveData(Product *p[], int count); 

#endif
