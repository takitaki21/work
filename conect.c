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
	int a[]={1 ,2 , 3, 4, 5, 6, EOD};



	struct list *get_list(void){
		int d;
		struct list *p,*newp;

		p=NULL;
		while((d=get_data())!=EOD){
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
			printf("%d\t",p->key);
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
	char c=10;
	int num;
		struct list *lp,*new1;
		lp=get_list();
		print_list(lp);

		printf("what is done?\tE.end\nA.addition\tD.delete\tP.print\n");
		while(c!='E'){
		scanf("%c",&c);

	    fflush(stdin);
		switch(c){
			case'A':
			printf("add number & which is it addition");
			scanf("%d,%d",&num,i);
			new1=(struct list *)maloc(sizeof(struct list));
			new1->key=num;
			insert_after(new1,lp->next ); //plaseで場所の選択ができるようにしたい
			

			case'D':
			printf("which list is deleate ");
			scanf("%d",&i);
			delete_it(lp->next);
			
		    case'P':
		    print_list(lp);
}
	        fflush(stdin);
	        printf("what is done?\tE.end\tA.addition\tD.delete\n");
	}
	    return 0;
}