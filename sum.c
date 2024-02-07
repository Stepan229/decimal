#include "decimal.h"



int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
    unsigned int rem = 0, temp = 0;
    int error = 0;
    if (get_bit(&value_1, 127) == 1)
        invert_decimal(&value_1);
    if (get_bit(&value_2, 127) == 1)
        invert_decimal(&value_2);
    for (int i = 0; i < 96; i++){
        unsigned int bit_1 = get_bit(&value_1, i), bit_2 = get_bit(&value_2, i), temp =0;
        temp = bit_1 + bit_2 + rem;
        rem = get_bit_int(temp, 1);
        set_bit_int(&temp, 1, 0);
        set_bit(result, i, temp);
    }
    if (temp != 0)
        error = 1;
    return error;
}

void zeroing_decimal(s21_decimal *dec){
    dec->bits[0] = 0;
    dec->bits[1] = 0;
    dec->bits[2] = 0;
    dec->bits[3] = 0;
}















