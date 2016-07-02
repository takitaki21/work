#include <stdio.h>

struct node{
	struct node *left;
	struct node *right;
		char   label;
	};


void preorder(struct node *p){

	if (p==NULL)
		    return;
	printf("this %c came here\n",p->label);
	preorder(p->left);
	preorder(p->right);
}

void inorder(struct node *p){
		if (p==NULL)
			return;
	inorder(p -> left);
	printf("this %c came here\n",p ->label);		
	inorder(p -> right);
}

void postorder(struct node *p){
		if(p==NULL)
			return;
	postorder(p->left);
	postorder(p->right);
	printf("this %c came here\n",p->label);
}





