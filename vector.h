#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct {
    void **data;
    size_t size;
    size_t capacity;
} Vector;

// Function declarations
Vector* vector_init();
void vector_push_back(Vector* vector, void* ptr);
void* vector_pop_back(Vector* vector);
void* vector_at(Vector* vector, int index);
size_t vector_get_size(Vector* vector);
size_t vector_get_capacity(Vector* vector);
void vector_shrink(Vector* vector, size_t new_capacity);
void vector_clear(Vector* vector);
void vector_erase(Vector* vector, int index);
void vector_destroy(Vector* vector);
void vector_insert(Vector* vector, void* ptr, int index);

#endif // VECTOR_H