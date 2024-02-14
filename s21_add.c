#include "decimal.h"


// Нет банковского округления 
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
    unsigned int rem = 0, temp = 0, scale = 0;
    int error = 0; 
    int sign_1 = get_bit(&value_1, 127), sign_2 = get_bit(&value_2, 127);
    s21_decimal nul;

    zeroing_decimal(&nul);
    error = normalize(&value_1, &value_2);
    scale = get_scale(value_1);
    set_scale(result, scale);
    if (sign_1 != sign_2){
        s21_decimal value_modul_1, value_modul_2;
        value_modul_1 = value_1;
        value_modul_2 = value_2;
        set_bit(&value_modul_1, 127, 0);
        set_bit(&value_modul_2, 127, 0);
        if (s21_is_less(value_modul_1, value_modul_2) && sign_2)
            set_bit(result, 127, 1);
        else if (s21_is_less(value_modul_2, value_modul_1) && sign_1)
            set_bit(result, 127, 1);
    }
    if (get_bit(&value_1, 127) == 1)
        invert_decimal(&value_1);
    if (get_bit(&value_2, 127) == 1)
        invert_decimal(&value_2);
    for (int i = 0; i < 96; i++){
        unsigned int bit_1 = get_bit(&value_1, i), bit_2 = get_bit(&value_2, i), temp = 0;
        temp = bit_1 + bit_2 + rem;
        rem = get_bit_int(temp, 1);
        set_bit_int(&temp, 1, 0);
        set_bit(result, i, temp);
    }
    // Сравнение с нулём
    if (s21_is_less(*result, nul))
        invert_decimal(result);
    if (temp != 0)
        if (!get_bit(result, 127))
            error = 1;
        else
            error = 2;
    return error;
}

void zeroing_decimal(s21_decimal *dec){
    dec->bits[0] = 0;
    dec->bits[1] = 0;
    dec->bits[2] = 0;
    dec->bits[3] = 0;
}















