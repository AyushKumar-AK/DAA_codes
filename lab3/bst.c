//bst with all operations

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

void insert(int item)
{
    struct node *temp,*p,*q;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=item;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
        root=temp;
    else
    {
        p=root;
        while(p!=NULL)
        {
            q=p;
            if(item<p->data)
                p=p->left;
            else
                p=p->right;
        }
        if(item<q->data)
            q->left=temp;
        else
            q->right=temp;
    }
}

void inorder(struct node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}

void preorder(struct node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(struct node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
}

int main()
{
    int ch,item;
    while(1)
    {
        printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the item to be inserted: ");
                    scanf("%d",&item);
                    insert(item);
                    break;
            case 2: printf("Inorder traversal: ");
                    inorder(root);
                    break;
            case 3: printf("Preorder traversal: ");
                    preorder(root);
                    break;
            case 4: printf("Postorder traversal: ");
                    postorder(root);
                    break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}



