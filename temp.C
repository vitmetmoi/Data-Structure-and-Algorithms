#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    if (data == -1)
    {
        return NULL;
    }
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void insertNode(struct Node **head, int data)
{
    if (*head == NULL)
    {
        *head = createNode(data);
    }
    else if ((*head)->left == NULL)
    {
        (*head)->left = createNode(data);
        //  insertNode(&(*head)->left, data);
    }
    else if ((*head)->right == NULL)
    {
        insertNode(&(*head)->right, data);
    }
}

void LRN(struct Node *head)
{
    if (head)
    {
        LRN(head->left);
        LRN(head->right);
        printf("%d ", head->data);
    }
}

int main()
{
    struct Node *head = NULL;
    int n;
    scanf("%d", &n);
    int arr[100000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Build tree from array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
        {
            insertNode(&head, arr[i]);
        }
    }

    LRN(head);
    return 0;
}