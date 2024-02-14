#include "decimal.h"



int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
    zeroing_decimal(result);
    unsigned int temp = 0;
    int error = 0;
    s21_decimal null;
    zeroing_decimal(&null); 
    if (get_bit(&value_1, 127) != get_bit(&value_2, 127))
        set_bit(result, 127, 1);

    for (int i = 0; i < 96; i++)
    {
        temp = get_bit(&value_2, i);
        if (i != 0)
            error = bit_shift(&value_1, 1);
        if (temp != 0)
            s21_add(*result, value_1, result);
    }
    return error;
}
int bit_shift(s21_decimal *val, int shift){
    int error = 0;
    unsigned int temp = 0;
    for (int i = 95; i > (95 - shift); i--)
    {
        if (get_bit(val, i) == 1)
            error = 1;
    }
    if (error == 0)
    {
        for (int k = 95 - shift; k >= 0; k--)
        {
            temp = get_bit(val, k);
            set_bit(val, k + shift, temp);
        }
        for (int i = 0; i < shift; i++)
            set_bit(val, i, 0);
    }
    return error;
}













