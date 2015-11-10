#include<stdio.h>
#include<stdlib.h>
const int memoryerr =-1;
const int nodeNULL=0;
typedef int element_t;
typedef int node_ad_t;
struct node
{
	element_t element;
	node_ad_t adpre,adnext;
};
typedef struct node node_t;
#define Maxsize 64
node_t Nodepool[Maxsize];

void nodepoolinit(void)
{
	int i;
	for(i=0;i<Maxsize ;i++ )
	{
		Nodepool[i].adnext=i+1;
	}
	Nodepool[Maxsize].adnext=0;
}

node_ad_t nodealloc(void)
{
	node_ad_t tmp;
	tmp=Nodepool[0].adnext;
	Nodepool[0].adnext=Nodepool[tmp].adnext;
	return tmp;
}
void nodefree(node_ad_t p)
{
	Nodepool[p].adnext=Nodepool[0].adnext;
	Nodepool[0].adnext=p;
}

struct listT{
	node_ad_t head;
	node_ad_t last;
	int eleamount;
};
typedef struct listT list_t;

int isempty(list_t list)
{
	if(list.head==list.last)
	return 1;
	else
	return 0;
}

int islast(list_t list,node_ad_t p)
{
	if(list.last==p)
	return 1;
	else
	return 0;
}
int insernext(list_t list ,node_ad_t p,element_t x)
{
	node_ad_t tmp=nodealloc();
	if(tmp==nodeNULL) return memoryerr;
	Nodepool[tmp].element=x;
	Nodepool[tmp].adnext=Nodepool[p].adnext;
	Nodepool[p].adnext=tmp;
	Nodepool[Nodepool[tmp].adnext].adpre=tmp;
	Nodepool[tmp].adpre=p;
	if(list.last==p) list.last=tmp;
	list.eleamount++;
	return 1;
}

void printE(node_ad_t p)
{
	printf("%d",Nodepool[p].element);
}
void showlist(list_t list)
{
	node_ad_t tmp=Nodepool[list.head].adnext ;
	while(tmp!=list.last)
	{
		printE(tmp);
		printf("->");
		tmp=Nodepool[tmp].adnext;
	}
	printE(tmp);
	printf("\n");
	
}

list_t creatlist(void)
{
	list_t tmp;
	tmp.head=nodealloc();
	
	if(tmp.head==nodeNULL)
	{
		printf("no memory to use.");
	}
	else{
		Nodepool[tmp.head].adnext=tmp.head;
	Nodepool[tmp.head].adpre=tmp.head;
	tmp.last=tmp.head;
	tmp.eleamount=0;
	return tmp;
	}
	
}



int main(int argc, char *argv[])
{
	int a[10]={
		1,3,5,4,2,6,8,9,10,13
	};
	int i;
	list_t list=creatlist();
	for(i=0;i<10 ; i++)
	{
		insernext(list,list.last,a[i]);
	}
	showlist(list);
	
	return 0;
}

