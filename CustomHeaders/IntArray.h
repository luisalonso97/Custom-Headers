/**
 * @file IntArray.h
 * @author Luis Alberto Alonso Mendoza (luisalonso97@gmail.com)
 * @brief Small vector-like implementation of structs as an array of int
 * @version 0.1
 * @date 2016-04-25
 * 
 * MIT License
 *
 * @copyright Copyright (c) 2016 Luis Alonso
 * 
 */

#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include "SafeInput.h"

/**
 * @brief Base struct implementation of vector-like array of int
 * 
 * @vals int pointer to store dinamic array of integers
 * @size size_t size of array (Maximum capacity)
 * @current size_t current quantity of integers stored in vals
 */
typedef struct intArray_t {
    int *vals; 
    size_t size;
    size_t current;
} intArray_t;
/**
 * @brief Type definitioms to simplify use of intArray_t
 * 
 */
typedef intArray_t INT_ARRAY;
typedef INT_ARRAY* INT_ARRAY_T;

/**
 * @brief Set up an INT_ARRAY_T vector
 * 
 * @param array Array variable INT_ARRAY_T, must be allocated before
 * @param size Size of vector
 * @return int Success
 */
int setUpArray_int(INT_ARRAY_T array, const size_t size){
    if (size > 0 && array != NULL) {
        array->size = size;
        array->current = 0;
        array->vals = (int *)malloc(sizeof(int) * size);
        return 1;
    } else if (size <= 0) {
        printf("setUpArray_int: Can't setup array with zero or less values\n");
        return 0;
    } else if (array == NULL) {
        fprintf(stderr, "setUpArray_int: Array null, please allocate memory space before setup\n");
        return 0;
    } else {
        return 0;
    }
}

/**
 * @brief Fill up an INT_ARRAY_T with console data
 * 
 * @param array Array variable INT_ARRAY_T, must be allocated before
 * @return int Success
 */
int fillArray_int(INT_ARRAY_T array) {
    if (array != NULL) {
        for(size_t i = 0; i < array->size; i++) {
            int flag = 0;
            do {
                flag = read_Int(&array->vals[i]);
                if (flag) array->current++;
            } while (!flag);
        }
        return 1;
    } else {
        fprintf(stderr, "fillArray_int: Array null, please allocate memory space before filling\n");
        return 0;
    }
}

/**
 * @brief Print an Array variable INT_ARRAY_T format "[x, y, z, ...]".
 * Only prints setted values i.e. If array->current = 3 and array->size = 5 
 * will only print the first 3 elements of the array as the other 2 haven't 
 * been setted.
 * 
 * @param array Array variable INT_ARRAY_T, must be allocated before
 * @return int Success
 */
int printArray_int(const INT_ARRAY_T array){
    if (array->size > 0 && array->current > 0 && array->vals != NULL) {
        printf("[%d", array->vals[0]);
        for(size_t i = 1; i < array->current; i++) printf(", %d", array->vals[i]);
        printf("]\n");
        return 1;
    } else {
        printf("[Empty array]\n");
        return 0;
    }
}

/**
 * @brief Deallocates heap memory of an Array variable INT_ARRAY_T
 * 
 * @param array Array variable INT_ARRAY_T, must be allocated before
 * @return int Success
 */
int freeArray_int(INT_ARRAY_T array){
    if (array != NULL) {
        free(array->vals);
        free(array);
        array = NULL;
        return 1;
    } else {
        printf("Array already empty\n");
        return 0;
    }
}

/**
 * @brief Push value to the end of an Array variable INT_ARRAY_T
 * 
 * @param array Array variable INT_ARRAY_T, must be allocated before
 * @param val Value to be pushed
 * @return int Success
 */
int pushValueArray_int(INT_ARRAY_T array, const int val){
    if (array != NULL) {
        if (array->size > 0 && array->current < array->size) {
            array->vals[array->current] = val;
            array->current++;
            return 1;
        } else {
            return 0;
        } 
    } else {
        return 0;
    }
}

/**
 * @brief Pops and replaces value in a given index of an Array variable 
 * INT_ARRAY_T
 * 
 * @param array Array variable INT_ARRAY_T, must be allocated before
 * @param index Index of the value to be popped and replaced
 * @param val Value to be pushed
 * @return int Success
 */
int popValueArray_int(INT_ARRAY_T array, const int index, const int val){
    if (array != NULL && array->size > 0 && array->current > 0) {
        if (valRange(index, 0, array->current)) {
            array->vals[index] = val;
            return 1;
        } else {
            return 0;
        } 
    } else {
        return 0;
    }
}

#endif //INT_ARRAY_H