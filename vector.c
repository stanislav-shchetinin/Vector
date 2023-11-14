#define FIRST_CAPACITY 8

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct vector {
    size_t capacity;
    size_t count;
    int64_t* begin;
};

//Чтобы установить capacity по умолчанию нужно передать значение <= 0
struct vector* init_vector(size_t capacity){
    if (capacity <= 0){
        capacity = FIRST_CAPACITY;
    }
    struct vector* vector = malloc(sizeof(struct vector));
    if (vector) {
        int64_t* new_begin = malloc(sizeof(int64_t) * capacity;
        if (new_begin)
            vector->capacity = capacity, vector->count = 0, vector->begin = new_begin);
    }
        
    return vector;
}

int64_t get_element(const size_t number, const struct vector* vector){
    return vector->begin[number];
}

void set_element(const int64_t value, const size_t number, const struct vector* vector){
    vector->begin[number] = value;
}

size_t get_capacity(const struct vector* vector){
    return vector->capacity;
}

size_t get_count(const struct vector* vector){
    return vector->count;
}

bool increase_vector(struct vector* vector){
    int64_t* new_begin = realloc(vector->begin, sizeof(int64_t) * get_capacity(vector) * 2);
    if (new_begin) {
        vector->begin = new_begin;
        vector->capacity *= 2;
        return true;
    }
    return false;
}

bool push_back(struct vector* vector, const int64_t value){
    if (get_count(vector) == get_capacity(vector)){
        return increase_vector(vector);
    }   
    set_element(value, vector->count++, vector);
}

bool push_back_vector(struct vector* in_vector, const struct vector* from_vector){
    bool ok = true;
    for (size_t i = 0; i < get_count(from_vector); ++i){
        ok = push_back(in_vector, get_element(i, from_vector));
        if (!ok) return false;
    }
    return true;
}

bool resize_vector(struct vector* vector, size_t new_size){
    int64_t* new_begin = realloc(vector->begin, sizeof(int64_t) * new_size); 
    if (new_begin){
        vector->begin = new_begin;
        vector->count = new_size;
        return true;
    }
    return false;
}

void free_vector(struct vector* vector){
    if (vector && vector->begin){
        free(vector->begin);
        free(vector);
    }
}

void write_vector(const struct vector* vector, FILE* f){
    if (!vector) return;
    fprintf(f, "vector = {");
    for (size_t i = 0; i < get_count(vector) - 1; ++i){
        fprintf(f, "%ld, ", vector->begin[i]);
    }
    fprintf(f, "%ld}\n", vector->begin[get_count(vector) - 1]);
}

