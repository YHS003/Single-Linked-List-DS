#ifndef _SINGLE_LINKED_LIST_H
#define _SINGLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "Std_Types.h"

struct Node{
    uint32 NodeData;
    struct Node *NodeLink;
};

/**
  *@brief  : Insert Node at beginnig in linked list
  *@param  : Pointer to Pointer to Struct Type
  *@return : void
  */
void Insert_Node_At_Beginning(struct Node **List);

/**
  *@brief  : Insert Node at end in linked list
  *@param  : Pointer to Pointer to Struct Type
  *@return : void
  */
void Insert_Node_At_End(struct Node **List);

/**
  *@brief  : Insert Node after determined node
  *@param  : Pointer to Struct Type
  *@return : void
  */
void Insert_Node_After(const struct Node *const List);

/**
  *@brief  : Delete Node From Beginning from Linked List
  *@param  : Pointer to Pointer to Struct Type
  *@return : void
  */
void Delete_Node_At_Beginning(struct Node **List);

/**
  *@brief  : Delete Node from Linked List
  *@param  : Pointer to Struct Type
  *@return : void
  */
void Delete_Node(const struct Node *const List);

/**
  *@brief  : Display All Nodes Value
  *@param  : Pointer to Struct Type
  *@return : void
  */
void Display_All_Nodes(const struct Node *const List);

/**
  *@brief  : Function to Get The Length of Linked List
  *@param  : Pointer to the Struct Type
  *@return : The Length of Linked List
  */
uint32 Get_Length(const struct Node *List);

#endif // _SINGLE_LINKED_LIST_H
