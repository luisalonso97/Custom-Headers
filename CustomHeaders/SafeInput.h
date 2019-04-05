/**
 * @file SafeInput.h
 * @author Luis Alberto Alonso Mendoza (luisalonso97@gmail.com)
 * @brief Small implementations of functions to safely read console input
 * @version 0.1
 * @date 2016-04-25
 * 
 * MIT License
 *
 * @copyright Copyright (c) 2016 Luis Alonso
 * 
 */
#ifndef SAFE_INPUT_H
#define SAFE_INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <float.h>
#include <string.h>

#define BUFF_SIZE 1024  /* Size of buffer defalut to 1kB */
#define BASE_10 10      /* Numeric base of reader, default to base 10 (decimal) */
#define BASE_ERR 0      /* Base error of operation */

/**
 * @brief Function to read an integer number from console
 * 
 * @param number Pointer to variable
 * @return int Success
 */
int read_Int(int *number) {
    long a;
    char buf[BUFF_SIZE];
    if (!fgets(buf, BUFF_SIZE, stdin))  return 0;
    char *endptr;
    errno = BASE_ERR;
    a = strtol(buf, &endptr, BASE_10);
    if (errno == ERANGE)                return 0;
    if (endptr == buf)                  return 0;
    if (*endptr && *endptr != '\n')     return 0;
    if (a > INT_MAX || a < INT_MIN)     return 0;
    *number = (int) a;
    return 1;
}

/**
 * @brief Function to read a floating point (float) number from console
 * 
 * @param number Pointer to variable
 * @return int Success
 */
int read_Float(float *number) {
    float a;
    char buf[BUFF_SIZE];
    if (!fgets(buf, BUFF_SIZE, stdin))  return 0;
    char *endptr;
    errno = BASE_ERR;
    a = strtof(buf, &endptr);
    if (errno == ERANGE)                return 0;
    if (endptr == buf)                  return 0;
    if (*endptr && *endptr != '\n')     return 0;
    if (a > FLT_MAX || a < FLT_MIN)     return 0;
    *number = (float) a;
    return 1;
}

/**
 * @brief Function to read a floating point (double) number from console
 * 
 * @param number Pointer to variable
 * @return int Success
 */
int read_Double(double *number) {
    double a;
    char buf[BUFF_SIZE];
    if (!fgets(buf, BUFF_SIZE, stdin))  return 0;
    char *endptr;
    errno = BASE_ERR;
    a = strtod(buf, &endptr);
    if (errno == ERANGE)                return 0;
    if (endptr == buf)                  return 0;
    if (*endptr && *endptr != '\n')     return 0;
    if (a > DBL_MAX || a < DBL_MIN)     return 0;
    *number = (double) a;
    return 1;
}

/**
 * @brief Function to validate if a value is within a range
 * 
 * @param testVal Value to be tested
 * @param MIN_VAL Minimum value of range
 * @param MAX_VAL Maximum value of range
 * @return int 
 */
int valRange(const int testVal, const int MIN_VAL, const int MAX_VAL) {
    if (testVal >= MIN_VAL && testVal <= MAX_VAL)   return 1;
    else                                            return 0;
}

#endif //SAFE_INPUT_H
