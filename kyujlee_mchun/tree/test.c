#include "maxHeap.h"

int     main()
{
    int max_size = 14;
    t_maxheap   *h = createHeap(max_size);


    addData(h, 1);
    addData(h, 2);
    addData(h, 3);
    addData(h, 4);
    addData(h, 5);

    
    printHeap(h);

    printf ("\n\n");
    removeMaxData(h);
    removeMaxData(h);
    removeMaxData(h);
    removeMaxData(h);

    printHeap(h);

    return (0);

}
