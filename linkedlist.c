#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node 
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create_LL(struct node *start);
struct node *display(struct node *start);
struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *insert_bef(struct node *start);
struct node *insert_aft(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_lst(struct node *start);
struct node *delete_node(struct node *start);
struct node *delete_aftr(struct node *start);
struct node *sort_list(struct node *start);
struct node *delete_list(struct node *start);

int main(int argc, char const *argv[])
{
    int option;
    gohere:
    printf("\n\t\t*******MAIN MENU************");
    printf("\n1. Create a list");
    printf("\n2. Display the list");
    printf("\n3. Insert at the beg of the list");
    printf("\n4. Insert at the end of the list");
    printf("\n5. Insert before the given node of the list");
    printf("\n6. Insert after the given node of the list");
    printf("\n7. Delete a node at the begining of the list");
    printf("\n8. Delete a node at the end of the list");
    printf("\n9. Delete a given node");
    printf("\n10. Delete a node after a given node");
    printf("\n11. Sort list");
    printf("\n12. Delete the list");
    printf("\n13. Terminate");

    scanf("%d", &option);
    
    switch (option)
    {
    case 1: start = create_LL(start);
            printf("\nLinked list created");
        break;
    case 2: start = display(start);
        break;
    case 3: start=insert_beg(start);
        break;
    case 4:start = insert_end(start);
        break;
    case 5:start = insert_bef(start);
        break;
    case 6:start = insert_aft(start);
        break;
    case 7:start = delete_beg(start);
        break;
    case 8:start = delete_lst(start);
        break;
    case 9:start = delete_node(start);
        break;
    case 10:start = delete_aftr(start);
        break;
    case 11:start = sort_list(start);
        break;
    case 12:start = delete_lst(start);
        break;
    case 13: exit(0);
        break;
    
    }
    
    goto gohere;
    
    return 0;
}
struct node *create_LL(struct node *start)
{   
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data");
    scanf("%d", &num);
    while (num!=-1)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
        {
            new_node->next=NULL;
            start = new_node;
        }else
        {
            ptr = start;
            while (ptr->next!=NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next=NULL;
        }
        printf("\nEnter the data: ");
        scanf("%d", &num);
        
    }

    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if (ptr == NULL)
        printf("\nList empty");
    while (ptr !=NULL)
    {
        printf("\t %d", ptr->data);
        ptr =ptr->next;
    }
    return start;
}
struct node *insert_beg(struct node *start)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->next=NULL;
    int num;

    printf("\nEnter data");
    scanf("%d", &num);

    new_node->data = num;
    new_node->next= start;
    start= new_node;

    return start;

}
struct node *insert_end(struct node *start)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node)), *ptr;
    
    int num;

    printf("\nEnter data ");
    scanf("%d", &num);

    new_node->data =num;
    new_node->next =NULL;
    ptr =start;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=new_node;

    return start;
   
}
struct node *insert_bef(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int val, num;
    printf("\nEnter data: ");
    scanf("%d", &num);
    printf("\nEnter the value for which the data is inserted before: ");
    scanf("%d", &val);

    new_node =(struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    ptr= start;

    while (ptr->data!=val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;

    return start;
}
struct node *insert_aft(struct node *start)
{
    struct node *new_node, *ptr, *postptr;
    int num, val;

    printf("\nEnter data: ");
    scanf("%d", &num);
    printf("\nEnter the value for which the data is inserted after: ");
    scanf("%d", &val);

    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    postptr = ptr;
    while (postptr->data!=val);
    {
        postptr =ptr;
        ptr=ptr->next;
    }
    postptr->next = new_node;
    new_node->next=ptr;

    return start;
}
struct node *delete_beg(struct node *start)
{
    struct node *ptr = NULL;
    
    if (start==NULL)
    {
        printf("\nNothing to delete");
        goto end;
    }
    ptr = start;
    start = start->next;

    free(ptr);
    end:
    return start;
    
}
struct node *delete_lst(struct node *start)
{
    struct node *ptr, *preptr;
    if (start==NULL)
    {
        printf("\nList already empty");
        goto end;
    }
    ptr = start;
    while (ptr->next!=NULL)
    {
        preptr =ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    end:
    return start;
}
struct node *delete_node(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\nEnter the value of the node which you want to delete");
    scanf("%d", &val);
    ptr = start;

    if (ptr->data ==val)
    {
        start = delete_beg(start);
    }else
    {
        while (ptr->data!=val)
        {
            preptr = ptr;
            ptr =ptr->next;
        }
        preptr->next = preptr->next;
        free(ptr);
        return start;
        
    }
    
    
}
struct node *delete_aftr(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\nEnter the value after whichh the node has to be deleted: ");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;
    while (preptr->data!=val)
    {
        preptr=ptr;
        ptr =ptr->next;
    }
    preptr->next= ptr->next;
    free(ptr);
    return start;
}
struct node *sort_list(struct node *start)
{
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = start;

    while (ptr1->next!=NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2!=NULL)
        {
            if(ptr1->data> ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2=ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start; // Had to be added
}
struct node *delete_list(struct node *start)
{
    struct node *ptr;
    if (start !=NULL)
    {
        ptr=start;
        while (ptr!=NULL)
        {
            printf("\n%d is to be deleted next", ptr->data);
            start = delete_beg(ptr);
            ptr = start;
        }
    }
    return start;
}