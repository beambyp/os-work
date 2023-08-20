#include <stdio.h>
#include <stdlib.h>

int gv_1 = 1;
int gv_2 = 2;
int gv_3 = 3;

void func_mem(int c, char ovf)
{
    int stack_v = c;
    printf("Stack variable address (level %d): %p\n", c, &stack_v);

    int *heap_v = (int *)malloc(sizeof(int));
    *heap_v = c;
    printf("Heap variable address (level %d): %p\n", c, &heap_v);

    if (ovf == 'y')
    {
        func_mem(c + 1, ovf);
    }
    else
    {
        if (c < 3)
        {
            func_mem(c + 1, ovf);
        }
    }

    free(heap_v);
}

int main()
{
    printf("Global variable 1 address: %p\n", (void *)&gv_1);
    printf("Global variable 2 address: %p\n", (void *)&gv_2);
    printf("Global variable 3 address: %p\n", (void *)&gv_3);

    char ovf;
    printf("Show overflow? (y/n): ");
    scanf("%c", &ovf);
    func_mem(1, ovf);
    return 0;
}
