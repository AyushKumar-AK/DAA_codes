//huffmann coding

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct node
{
    int freq;
    char ch;
    struct node *left, *right;
} node;

typedef struct heap
{
    int size;
    node *arr[MAX];
} heap;

node *newnode(char ch, int freq)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->ch = ch;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

heap *newheap()
{
    heap *temp = (heap *)malloc(sizeof(heap));
    temp->size = 0;
    return temp;
}

void swap(node **a, node **b)
{
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(heap *h, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < h->size && h->arr[left]->freq < h->arr[smallest]->freq)
        smallest = left;
    if (right < h->size && h->arr[right]->freq < h->arr[smallest]->freq)
        smallest = right;
    if (smallest != i)
    {
        swap(&h->arr[smallest], &h->arr[i]);
        heapify(h, smallest);
    }
}

int issizeone(heap *h)
{
    return (h->size == 1);
}

node *extractmin(heap *h)
{
    node *temp = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    --h->size;
    heapify(h, 0);
    return temp;
}

void insert(heap *h, node *temp)
{
    ++h->size;
    int i = h->size - 1;
    while (i && temp->freq < h->arr[(i - 1) / 2]->freq)
    {
        h->arr[i] = h->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->arr[i] = temp;
}

void buildheap(heap *h)
{
    int n = h->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        heapify(h, i);
}

void printarr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf(" ");
}

int isleaf(node *root)
{
    return !(root->left) && !(root->right);
}

heap *createheap(char data[], int freq[], int size)
{
    heap *h = newheap();
    int i;
    for (i = 0; i < size; ++i)
        h->arr[i] = newnode(data[i], freq[i]);
    h->size = size;
    buildheap(h);
    return h;
}

node *huffmantree(char data[], int freq[], int size)
{
    node *left, *right, *top;
    heap *h = createheap(data, freq, size);
    while (!issizeone(h))
    {
        left = extractmin(h);
        right = extractmin(h);
        top = newnode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert(h, top);
    }
    return extractmin(h);
}

void printcodes(node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printcodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printcodes(root->right, arr, top + 1);
    }
    if (isleaf(root))
    {
        printf("%c: ", root->ch);
        printarr(arr, top);
    }
}

void huffmancodes(char data[], int freq[], int size)
{
    node *root = huffmantree(data, freq, size);
    int arr[MAX], top = 0;
    printcodes(root, arr, top);
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    huffmancodes(arr, freq, size);
    return 0;
}
