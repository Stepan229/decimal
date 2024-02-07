#include <stdlib.h>
#include <stdio.h>


typedef struct 
{
    unsigned int bits[4];
} s21_decimal;

unsigned int get_bit(s21_decimal *decimal, int num);
int set_bit(s21_decimal *decimal, int num, int bit);


unsigned int dec2bin(unsigned int num);
int decimal2int(s21_decimal src, int *dst);
int int2decimal(int src, s21_decimal *dst);


int set_bit_int(unsigned int *bits, int num, int bit);
int get_bit_int(unsigned int value, int i);

void norm_byte_a(int num, unsigned int *a, int *num_int);

void view_bit(unsigned int);
unsigned int get_scale(s21_decimal dec);
void invert_decimal(s21_decimal *value);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int bit_shift(s21_decimal *val, int shift);

void zeroing_decimal(s21_decimal *dec);
int write_scale(s21_decimal *value,unsigned int scale);