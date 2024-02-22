#include "Single_Linked_List.h"

/**
  *@brief  : Insert Node at beginnig in linked list
  *@param  : Pointer to Pointer to Struct Type
  *@return : void
  */
void Insert_Node_At_Beginning(struct Node **List)
{
    struct Node *MyNode = NULL;
    MyNode = (struct Node *)malloc(sizeof(struct Node));

    if(!MyNode)
    {

    }
    else
    {
        printf("Enter Node Data: ");
        scanf("%i", &MyNode->NodeData);

        if(!(*List))
        {
            *List = MyNode;
            MyNode->NodeLink = NULL;
        }
        else
        {
            MyNode->NodeLink = *List;
            *List = MyNode;
        }
    }
}

/**
  *@brief  : Insert Node at end in linked list
  *@param  : Pointer to Pointer to Struct Type
  *@return : void
  */
void Insert_Node_At_End(struct Node **List)
{
    struct Node *MyNode = NULL;
    struct Node *LastNode = NULL;
    MyNode = (struct Node *)malloc(sizeof(struct Node));

    if(!MyNode)
    {

    }
    else
    {
        MyNode->NodeLink = NULL;
        printf("Enter Node Data: ");
        scanf("%i", &MyNode->NodeData);

        if(!(*List))
        {
            *List = MyNode;
        }
        else
        {
            LastNode = *List;

            while(LastNode->NodeLink)
            {
                LastNode = LastNode->NodeLink;
            }

            LastNode->NodeLink = MyNode;
        }
    }
}

/**
  *@brief  : Insert Node after determined node
  *@param  : Pointer to Struct Type
  *@return : void
  */
void Insert_Node_After(const struct Node *const List)
{
    struct Node *MyNode = NULL;
    struct Node *TempNode = List;
    uint32 NodePoss;
    uint32 Counter = 1;

    printf("Enter Node Possition (First Node Possition is 1): ");
    scanf("%i", &NodePoss);

    if(NodePoss > Get_Length(List))
    {
        printf("Invalid Possition :(\n");
    }
    else
    {
        TempNode = List;

        while(Counter++ < NodePoss)
        {
            TempNode = TempNode->NodeLink;
        }

        MyNode = (struct Node *)malloc(sizeof(struct Node));

        if(MyNode)
        {
            printf("Enter Node Data: ");
            scanf("%i", &MyNode->NodeData);

            MyNode->NodeLink = TempNode->NodeLink;
            TempNode->NodeLink = MyNode;
        }
        else
        {

        }
    }
}

/**
  *@brief  : Delete Node From Beginning from Linked List
  *@param  : Pointer to Pointer to Struct Type
  *@return : void
  */
void Delete_Node_At_Beginning(struct Node **List)
{
    struct Node *DeletedNode = *List;

    if(!(*List))
    {
        printf("List is Empty :(\n");
    }
    else
    {
        *List = DeletedNode->NodeLink;
        DeletedNode->NodeLink = NULL;
        free(DeletedNode);
    }
}

/**
  *@brief  : Delete Node from Linked List
  *@param  : Pointer to Struct Type
  *@return : void
  */
void Delete_Node(const struct Node *const List)
{
    struct Node *TempNode = List;
    struct Node *DeletedNode = NULL;
    uint32 NodePoss;
    uint32 Counter = 1;

    if(!List)
    {
        printf("List is Empty :(\n");
    }
    else
    {
        printf("Enter Node Possition (First Node Possition is 1): ");
        scanf("%i", &NodePoss);

        if((NodePoss > Get_Length(List)) || (1 == NodePoss) || (1 == Get_Length(List)))
        {
            printf("Invalid Possition or Try Delete_Node_At_Beginning Function :(\n");
        }
        else
        {
            while(Counter++ < (NodePoss - 1))
            {
                TempNode = TempNode->NodeLink;
            }

            DeletedNode = TempNode->NodeLink;
            TempNode->NodeLink = DeletedNode->NodeLink;

            DeletedNode->NodeLink = NULL;
            free(DeletedNode);
        }
    }
}

/**
  *@brief  : Display All Nodes Value
  *@param  : Pointer to Struct Type
  *@return : void
  */
void Display_All_Nodes(const struct Node *const List)
{
    struct Node *TempNode = List;

    if(!TempNode)
    {
        printf("List is Empty :( \n");
    }
    else
    {
        printf("Nodes Values: ");

        while(TempNode)
        {
            printf("%i\t", TempNode->NodeData);
            TempNode = TempNode->NodeLink;
        }

        if(!TempNode)
        {
            printf("NULL\n");
        }
    }
}

/**
  *@brief  : Function to Get The Length of Linked List
  *@param  : Pointer to the Struct Type
  *@return : The Length of Linked List
  */
uint32 Get_Length(const struct Node *const List)
{
    struct Node *TempNode = List;
    uint32 Len = 0;

    while(TempNode)
    {
        Len++;
        TempNode = TempNode->NodeLink;
    }

    return Len;
}
