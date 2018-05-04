// linked list stack implementation
#include <stdio.h>
#include <stdlib.h>

/*
 * 1st issue:
 * printing to console not matched with _stacktype: printf("%d"...),
 * works only for integer types
 *
 * 2nd issue:
 * works only for 1 stack - only 1 stack size counter
 */

#define uint8 unsigned char

#define _stacksize 160  // stack size in bytes
#define _nodesize sizeof(TNode)
#define _stacktype unsigned int
unsigned int stack_actual_size;

#define _IsEmpty(TNode) (TNode->next != NULL ? 0 : 1)
#define _IsFull(actual_size) (actual_size > _stacksize || actual_size + _nodesize > _stacksize ? 1 : 0)

typedef struct TNode
{
  _stacktype data;
  struct TNode *next;
}TNode;

void StackPush(TNode **head, _stacktype data)
{
  if (_IsFull(stack_actual_size))
  {
    printf("Push canceled ! This push will cause stack overflow!\n");
    return;
  }
  else
  {
    // allocate memory for new node
    TNode *temp = (TNode *) malloc(sizeof(TNode));
    stack_actual_size += _nodesize;

    temp->data = data;
    if (!*head)  // if empty
      temp->next = NULL;
    else
      temp->next = *head;

    *head = temp;
    printf("%d pushed onto stack\n", (*head)->data);
  }
}

void StackPop(TNode **head)
{
  if (!*head) // if empty
  {
    printf("stack is empty !\n");
    return;
  }
  else
  {
    TNode * temp = *head;
    *head = (*head)->next;
    printf("%d poped out of the stack\n",temp->data);
    free(temp);
    stack_actual_size -= _nodesize;
  }
}

void StackTop(TNode *head)
{
  if (!head) // if empty
    printf("stack is empty !\n");
  else
    printf("Top of the stack: %d\n", head->data);
}

void StackDisplay(TNode *head)
{
  if (!head) // if empty
  {
    printf("stack is empty !\n");
    return;
  }

  while (head) // display till head == NULL pointer
  {
    printf("%d\n", head->data);
    head = head->next;
  }
}

int main()
{
  TNode *stack_head = NULL;
  int i;

  StackPop(&stack_head);
  StackDisplay(stack_head);
  StackTop(stack_head);
  for (i = 0; i < 10; i++)
    StackPush(&stack_head, 10 * i);

//  StackDisplay(stack_head);

  StackTop(stack_head);
  StackPush(&stack_head, 77);
  StackTop(stack_head);
  StackPop(&stack_head);
  StackPop(&stack_head);
  StackPop(&stack_head);
  StackPush(&stack_head, 77);
  StackTop(stack_head);
  StackPop(&stack_head);
  StackTop(stack_head);

  return 0;
}
