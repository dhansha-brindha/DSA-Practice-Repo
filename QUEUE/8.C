#include <stdio.h>
#define MAX 100
int cache[MAX];
int size = 0;
int capacity;
void put(int key)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (cache[i] == key)
        {
            for (int j = i; j < size - 1; j++)
                cache[j] = cache[j + 1];
            size--;
            break;
        }
    }
    if (size == capacity)
        size--;
    for (i = size; i > 0; i--)
        cache[i] = cache[i - 1];
    cache[0] = key;
    size++;
}
void display()
{
    for (int i = 0; i < size; i++)
        printf("%d ", cache[i]);
    printf("\n");
}
int main()
{
    int n, key;
    scanf("%d", &capacity);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        put(key);
        display();
    }
    return 0;
}