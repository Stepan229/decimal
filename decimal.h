#include <stdlib.h>
#include <stdio.h>


typedef struct 
{
    unsigned int bits[4];
} s21_decimal;
// СЕТЫ
unsigned int get_bit(s21_decimal *decimal, int num);
int set_bit(s21_decimal *decimal, int num, int bit);
int set_scale(s21_decimal *value,unsigned int scale);
unsigned int get_scale(s21_decimal dec);

int set_bit_int(unsigned int *bits, int num, int bit);
int get_bit_int(unsigned int value, int i);
// Математика
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

unsigned int dec2bin(unsigned int num);
int decimal2int(s21_decimal src, int *dst);
int int2decimal(int src, s21_decimal *dst);




void norm_byte_a(int num, unsigned int *a, int *num_int);

void view_bit(unsigned int);

void invert_decimal(s21_decimal *value);



int bit_shift(s21_decimal *val, int shift);

void zeroing_decimal(s21_decimal *dec);

int normalize(s21_decimal *value_1, s21_decimal *value_2);

// Сравнение
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);