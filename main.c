#include <stdio.h>
#include "vector.h"

int main(int argc, char** argv) {
    Vector* vector;
    vector = vector_init();

    int x = 5, y = 10, z = 15, a = 2, b = 4, c = 6;

    // vector_push_back

    vector_push_back(vector, &x);

    vector_push_back(vector, &y);

    vector_push_back(vector, &a);

    vector_push_back(vector, &b);

    vector_push_back(vector, &c);

    // vector_insert

    puts("After insert:");
    vector_insert(vector, &z, 1);
    
    for (int i=0; i < vector->size; i++) {
        printf("%d\n", *(int*)vector_at(vector, i));
    }
    
    // vector_erase

    puts("After erase:");
    vector_erase(vector, 0);

    for (int i=0; i < vector->size; i++) {
        printf("%d\n", *(int*)vector_at(vector, i));
    }

    // vector_shrink

    puts("After shrink:");
    vector_shrink(vector, 3);

    for (int i=0; i < vector->size; i++) {
        printf("%d\n", *(int*)vector_at(vector, i));
    }
    
    // vector_pop_back
    puts("After popback:");
    void* element = vector_pop_back(vector);
    for (int i=0; i < vector->size; i++) {
        printf("%d\n", *(int*)vector_at(vector, i));
    }

    printf("Popback element: %d\n", *(int*)(element));

    // vector_clear

    puts("After clear:");
    vector_clear(vector);
    printf("Capacity: %d\n", vector->capacity);
    printf("Size: %d\n", vector->size);

    // vector_destroy

    puts("After destroy:");
    vector_destroy(vector);
    printf("Capacity: %d\n", vector->capacity);
    printf("Size: %d\n", vector->size);

    return 0; 
}