#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "02hw8.h"

#define N 35001 


struct dnode
{
	char key[N];
	int cnt ;
	struct dnode *next;

};


/*
struct gram
{
	char *key;
	int exist ;

}term[1000];
*/


struct dnode *htab[N] ;



unsigned int hash(char *text)
{
	int len=0 , hashv=0 , i=0 ;

	len=strlen(text);
	hashv=0;
	
	for(i=0;i<len;i++)
	{
		hashv=(hashv*35000)+text[i];
	}

	return hashv ;
}



struct dnode  *insert(struct dnode *Htab , char *key )
{
	int  same=0 ;
	struct dnode *hptr ;

//	hv=hash32(key)%max;
	hptr = Htab ;

//	if(hptr==NULL)
//	{
//		printf("hptr=NULL\n");
//	}

	while(hptr!=NULL)
	{
//		printf("hptr!=NULL\n");

		if(strcmp(hptr->key,key)==0)
		{
//			same=1;
//			hptr->cnt=hptr->cnt+1;
//			printf("cnt+1\n");
			return hptr ;
		}
			
		hptr=hptr->next;
		
	}


	if(same==0)
	{
/*		p=(struct dnode *)malloc(sizeof(struct dnode));
		strcpy(p->key,key);
		p->cnt=1;
		p->next = hptr;
		hptr=p;
//		printf("no the same\n");
*/		
		hptr=(struct dnode *)malloc(sizeof(struct dnode));
		strcpy(hptr->key,key);
		hptr->next = Htab;
		Htab=hptr;

	}

//	Htab=hptr ;

//	printf("end\n");
	return hptr ;

}


char* getnterm(char *ptr , int n)
{
	char *qtr ;

	qtr=(char *)malloc(strlen(ptr)+1);
	strcpy(qtr,ptr);

	qtr[n*2]='\n';
	qtr[n*2+1]='\0';

	return qtr ;

}



int find(struct dnode *Htab , char *key)
{
	//int i ;
	struct dnode *hptr ;

//	hv=hash32(key)%max;
	hptr=Htab;

//	printf("find\t%s\n",key);

//	printf("----------\n");

	while(hptr!=NULL)
	{
		if(strcmp(hptr->key,key)==0)
		{

		//	if(hptr->cnt>0)
		//	{
			//printf("find\t%s\n",key);
			//printf("----------\n");
			//	printf("%s\n",hptr->key);
		//		printf("----------\n");
				return 1 ;
		//	}
		}

		hptr=hptr->next;

	}


//	printf("Not\tfound!\n");
//	printf("----------\n");


	return 0 ;

}



int main(int argc , char *argv[])
{
	int i=0 , j=0 , hv=0 , no=0 , minus=0;
	char line[N]={'\0'} , word[1000]={'\0'} , *ptr , *term ;
	FILE *fp , *data ;
//	char test[30]={"this is a pen!"};

	fp=fopen(argv[argc-2],"r");
	data=fopen(argv[argc-1],"r");

	while(fgets(line,N,fp)!=NULL)
	{
		hv=hash(line)%N;
		htab[hv]=insert(htab[hv],line);
		//printf("%s",htab[hv]->key);
	}

	while(fgets(word,1000,data)!=NULL)
	{


	ptr=word;

//	ptr=ptr+4;

	while(*ptr!='\n')
	{
		if(*ptr>=(char)0x81&&*ptr<=(char)0xFE)
		{
//			printf("1");

			for(i=15-j;i>0;i--)
			{
				term=getnterm(ptr,i);
				hv=hash(term)%N;
//				printf("%s",term);
		//		printf("%d\n",strlen(term));
			
				if(find(htab[hv],term)==1)
				{
					if(no==1)
					{
						printf("\n");
						no=0;
					}

//					printf("2\n");
					printf("%s",term);
					ptr=ptr+strlen(term)-1;

					if(strlen(ptr)<31)
					{
						j=15-((strlen(ptr)-1)/2);
					}
					
//					ptr[4]='\0';	

//					printf("%s",ptr);

					break ;
					
				}
				else if(i==1)
				{
					if(no==1)
					{
						printf("\n");
						no=0;
					}

					if(strlen(ptr)==3)
					{
						printf("%s",ptr);

					}
					else
					{
						term[2]='\0';
						printf("%s\n",term);
					}

					ptr=ptr+2;
					//no=1;
					

					if(minus==1)
					{
						j++;
					}
				}
	
			}

			if(strlen(ptr)<=31)
			{
				minus=1;
			}
		}
		else
		{	
			printf("%c",*ptr);
			ptr=ptr+1;
			no=1;
			
		}
	}
	
	minus=0;
	no=0;
	j=0;

	}


	//printf("%s\n",term);

//	ptr+=2;

//	ptr[4]='\0';

//	printf("%s",ptr);
	
//	test[5]='\0';

//	printf("%s\n",test);





	return 0 ;

}













