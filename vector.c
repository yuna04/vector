#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

#define DEFAULT_SIZE 0;
#define DEFAULT_CAPACITY 8;

Vector* vector_init() {
    Vector* vector = malloc(sizeof(Vector));
    vector->size = DEFAULT_SIZE;
    vector->capacity = DEFAULT_CAPACITY;
    vector->data = malloc(sizeof(void*) * vector->capacity);
    return vector;
}

static void vector_grow(Vector* vector) {
        vector->capacity *= 2;
        vector->data = realloc(vector->data, sizeof(void*) * (vector->capacity));
}

void vector_shrink(Vector* vector, size_t new_capacity) {
    if (new_capacity < vector->size) {
        vector->size = new_capacity;
    }
    vector->data = realloc(vector->data, sizeof(void*) * new_capacity);
    vector->capacity = new_capacity;
}

void vector_push_back(Vector* vector, void* ptr) {
    if (vector->size >= vector->capacity) {
        vector_grow(vector);
        if(!vector->data) {
            puts("It's fucked.");
            return;
        }
    }
    vector->data[vector->size++] = ptr;
}

void* vector_pop_back(Vector* vector) {
    if (vector->size == 0) {
        puts("Vector is empty.\n");
        return NULL;
    }

    void *element = vector->data[--vector->size];
    vector->data[vector->size] = NULL;
    return element;
}

void* vector_at(Vector* vector, int index) {
    if (index < 0 || index >= vector->size) {
        printf("Index out of bounds.\n");
        return NULL;
    }
    return vector->data[index];
}

size_t vector_get_size(Vector* vector) {
    return vector->size;
}

size_t vector_get_capacity(Vector* vector) {
    return vector->capacity;
}

void vector_clear(Vector* vector) {
    for (int i = 0; i < vector->size; i++) {
        *(vector->data+i) = NULL;
    }
    vector->size=0;
}

void vector_erase(Vector* vector, int index) {
    if (index < 0 || index >= vector->size) {
        printf("Index out of bounds.\n");
        return;
    }
    memmove(vector->data+index, vector->data+index+1, sizeof(void*) * (vector->size - index - 1));
    vector->size--;
    if (vector->capacity >= vector->size*4) {
        vector_shrink(vector, vector->size*2);
    }
}

void vector_destroy(Vector* vector) {
    free(vector->data);
    vector->capacity = 0;
    vector->size = 0;
}

void vector_insert(Vector* vector, void* ptr, int index) {
    if (vector->size >= vector->capacity) {
        vector_grow(vector);
        if (!vector->data) {
            // failed realloc
            return;
        }
    }
    memmove(vector->data+index+1, vector->data+index, sizeof(void*) * (vector->size - index));
    vector->data[index] = ptr;
    vector->size++;
}
