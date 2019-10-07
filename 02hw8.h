#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 35001

#ifndef __02HW8_H_
#define __02HW8_H_

struct dnode;


struct dnode *htab[N] ;


unsigned int hash(char *text);


struct dnode  *insert(struct dnode *Htab , char *key );


char* getnterm(char *ptr , int n);


int find(struct dnode *Htab , char *key);





#endif
