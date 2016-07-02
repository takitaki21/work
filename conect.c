#include <stdio.h>
#include <stdlib.h>

struct list{
	int key;
	struct list *next;
};
 
struct list *get_list(void);
void print_list(struct list *p);
void insert_after(struct list *x,struct list *p);
void insert_before(struct list *x,struct list *p);
void delete_next(struct list *p);
void delete_it(struct list *p);
int get_data(void);

#define EOD -1
int a[]={1,2,3,4,5,6,EOD};


struct list *get_list(void){
	int d;
	struct list *p,*newp;

	p=NULL;
	while((dget_data())!=EOD){
		newp=(struct list*)malloc(sizeof(struct list));
	newp->key =d;
	newp->next=p;
	p=newp;
	}
	return p;
}

int get_data(void){
static int i=0;
return a[i++];
}

void print_list(struct list *p){
	while(p!=NULL){
		printf("%d",p->key);
		p=p->next;
	}

	printf("\n");
}
void insert_after(struct list *x,struct list *p){
	x->next=p->next;
	p->next=x;
}

void insert_before(struct list *x,struct list *p){
	struct list tmp;
	tmp=*x;
	*x=*p;
	*p=tmp;
	p->next=x;
}

void delete_next(struct list *p){
	struct list *q;

	q=p->next;
	p->next=q->next;
	free(q);
}

void delete_it(struct list *p){
	struct list *q;
	if(p->next!=NULL){
		q=p->next;
		*p=*q;
		free(q);
	}
}

int main (void){
	struct list *lp,*new1,new2;
   
    lp = get_list();
    print_list(lp);

    new1=(struct list *)malloc(sizeof(struct list));
    new1 -> key=111;
    insert_after(new1,lp->next->next);
    print_list(lp);

    new2=(struct list *)malloc(sizeof(struct list));
    new2->key=222;
    insert_before(new2,lp->next->next);
    print_list(lp);

    delete_next(lp->next->next);
    print_list(lp);

    delete_it(lp->next->next);
    print_list(lp);

    return 0;
}