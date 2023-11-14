#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct vector;

struct vector* init_vector(size_t);
int64_t get_element(const size_t number, const struct vector* vector);
void set_element(const int64_t value, const size_t number, const struct vector* vector);
size_t get_capacity(const struct vector* vector);
size_t get_count(const struct vector* vector);
void increase_vector(struct vector* vector);
void push_back(struct vector* vector, const int64_t value);
void push_back_vector(struct vector* in_vector, const struct vector* from_vector);
void resize_vector(struct vector* vector, size_t new_size);
void free_vector(struct vector* vector);
void write_vector(const struct vector* vector, FILE* f);