#include "vector.h"
#include <stdio.h>

int main(){
    struct vector* vector = init_vector((size_t)0);
    
    push_back(vector, 12);
    push_back(vector, 13);
    push_back(vector, 13);
    push_back(vector, 13);
    push_back(vector, 13);
    push_back(vector, 13);
    push_back(vector, 13);
    push_back(vector, 13);
    push_back(vector, 13);
    push_back(vector, 13);
    push_back(vector, 13);
    push_back(vector, 13);
    push_back(vector, 13);
    push_back(vector, 13);
    push_back(vector, 13);
    push_back(vector, 14);
    write_vector(vector, stdout);
    struct vector* vector_add = init_vector((size_t)0);
    push_back(vector, 15);
    push_back(vector, 16);
    push_back_vector(vector, vector_add);
    write_vector(vector, stdout);
    set_element(9, 0, vector);
    write_vector(vector, stdout);
    printf("capacity: %ld, count: %ld\n", get_capacity(vector), get_count(vector));
    resize_vector(vector, 5);
    write_vector(vector, stdout);
    resize_vector(vector, 10);
    write_vector(vector, stdout);
    free_vector(vector);
    
    return 0;
}