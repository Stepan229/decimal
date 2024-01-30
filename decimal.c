#include <stdlib.h>
#include <stdio.h>


typedef struct 
{
    unsigned int bits[4];
} s21_decimal;

unsigned int get_bit(s21_decimal *decimal, int num);
int set_bit(s21_decimal *decimal, int num, int bit);
unsigned int dec2bin(unsigned int num);
void norm_byte_a(int num, unsigned int *a, int *num_int);
int decimal2int(s21_decimal src, int *dst);
int int2decimal(int src, s21_decimal *dst);

int main(){
    s21_decimal dec;
    dec.bits[0] = 10;
    dec.bits[1] = 11;
    dec.bits[2] = 12;
    int byte = 0, val_int = -10, val_int2 = 0;
    printf("%d до\n", dec.bits[byte]);
    printf("%d до\n", dec2bin(dec.bits[byte]));
    int2decimal(val_int, &dec);
    decimal2int(dec, &val_int2);
    printf("%d после\n", val_int2);
    printf("%d после\n", dec.bits[byte]);
    printf("%u после\n", dec2bin(dec.bits[byte]));
}

int int2decimal(int src, s21_decimal *dst){
    unsigned int var_int = 0;
    int shift = 1;
    for (int i = 0; i < 31; i++){
        var_int = src & (shift << i);
        set_bit(dst, i, var_int);
    }
    var_int = src & (shift << 31);
    set_bit(dst, 127, var_int);
    return 0;
}

int decimal2int(s21_decimal src, int *dst){
    unsigned int var_bit = 0;
    int shift = 1, error = 0;
    if (src.bits[1] == 0 && src.bits[2] == 0){
        for (int i = 0; i < 31; i++){
            var_bit = get_bit(&src, i);
            if (var_bit == 0)
                *dst = *dst & ~(shift << i);
            else
                *dst = *dst | (shift << i);
        }
        var_bit = get_bit(&src, 127);
        if (var_bit == 0)
            *dst = *dst & ~(shift << 31);
        else
            *dst = *dst | (shift << 31);
    }
    else
        error = 1;
    return error;
}

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
    unsigned int a = 1, bit = 0;
    int num_int = 0;
    norm_byte_a(num, &a, &num_int);
    bit = decimal->bits[num_int] & a;
    return bit;
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
}