/*HEAP SORT
 * C Program to sort an array based on heap sort algorithm(MAX heap)
 */
#include <stdio.h>

void main()
{
    int heap[10], n, i, j, c, root, temp;

    printf("\n Enter n of elements :");
    scanf("%d", &n);
    printf("\n Enter the ns : ");
    for (i = 0; i < n; i++)
       scanf("%d", &heap[i]);
    for (i = 1; i < n; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;
            if (heap[root] < heap[c])   /* to create MAX heap array */
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }

    printf("Heap array : ");
    for (i = 0; i < n; i++)
        printf("%d\t ", heap[i]);
    for (j = n - 1; j >= 0; j--)
    {
        temp = heap[0];
        heap[0] = heap[j];    /* swap max element with rightmost leaf element */
        heap[j] = temp;
        root = 0;
        do
        {
            c = 2 * root + 1;    /* left nde of root element */
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;
            if (heap[root]<heap[c] && c<j)    /* again rearrange to max heap array */
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < j);
    }
    printf("\n The sorted array is : ");
    for (i = 0; i < n; i++)
       printf("\t %d", heap[i]);
    printf("\n Complexity : \n Best case = Avg case = Worst case = O(n logn) \n");
}
