#ifndef _MANAGER_H
#define _MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saveData(Product *p[], int count);
int loadData(Product *p[]);
void searchProduct(Product *p[], int count);

#endif
