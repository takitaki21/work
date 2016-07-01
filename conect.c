#include <stdio.h>

typedef int data_t;

typedef struct nodetag{
data_t data;
struct nodetag *next;
} node_t;

int main (){
	int a;
node_t nd1,nd2,nd3;
node_t *p;

scanf("%d",a);
nd1.data = a;
nd1.next = &nd2;
nd2.data = a;
nd2.next = &nd3;
nd3.data = a;
nd3.next = NULL;


p = &nd1;
printf("%d\n",p->data);
p=p->next;
printf("%d\n",p->data);
p=p->next;
printf("%d\n",p->data);

}

