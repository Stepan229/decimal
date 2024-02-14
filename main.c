#include "decimal.h"


// занулить decimal в начале
unsigned int dec2bin(unsigned int num)
{
    unsigned long long int bin = 0, k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return bin;
}

unsigned int get_bit(s21_decimal *decimal, int num){
    unsigned int a = 1;
    int num_int = 0;
    norm_byte_a(num, &a, &num_int);
    return (decimal->bits[num_int] & a) == 0 ? 0 : 1;
}

int set_bit(s21_decimal *decimal, int num, int bit){
    unsigned int a = 1;
    int error = 0, num_byte = 0;
    norm_byte_a(num, &a, &num_byte);
    if (bit == 0){
        a = ~a;
        decimal->bits[num_byte] = decimal->bits[num_byte] & a;
    }
    else
        decimal->bits[num_byte] = decimal->bits[num_byte] | a;
    return error;
}

int set_bit_int(unsigned int *bits, int num, int bit){
    unsigned int a = 1;
    int error = 0;
    a = a << num;
    if (bit == 0)
        *bits = *bits & ~a;
    else
        *bits = *bits | a;
    return error;
}

int get_bit_int(unsigned int value, int i){
    unsigned int a = 1;
    return (value & a << i) == 0 ? 0 : 1;

}

void norm_byte_a(int num, unsigned int *a, int *num_int){
    if (num < 32)
    {   
        *num_int = 0;
        *a = *a << num;
    }
    else if (32 <= num && num < 64)
    {
        *num_int = 1;
        *a = *a << (num - 32);
    }
    else if (64 <= num && num < 96)
    {
        *num_int = 2;
        *a = *a << (num - 64);
    }
    else if (96 <= num && num < 128)
    {
        *num_int = 3;
        *a = *a << (num - 96);
    }
}

unsigned int get_scale(s21_decimal dec){
    unsigned int shift = 0b11111111;
    unsigned int scale = dec.bits[3] & (shift << 16);
    return scale >> 16;
}
// Инвертирует всё кроме знака и степени
void invert_decimal(s21_decimal *value){
    value->bits[0] = ~value->bits[0] + 1;
    for (int i = 1; i < 3; i++){
        value->bits[i] = ~value->bits[i];
    }
}

void view_bit(unsigned int bits){
    unsigned int a = 1;
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", ((bits & a << i) == 0 ? 0 : 1));
    }
    printf("\n");
}