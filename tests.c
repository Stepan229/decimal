#include "decimal.h"

int main(){
    s21_decimal dec;
    s21_decimal dec2;
    s21_decimal result;
    int error = 0;
    zeroing_decimal(&result);
    zeroing_decimal(&dec);
    zeroing_decimal(&dec2);

    //dec.bits[0] = 0b11111111111111111111111111111111;
    dec.bits[0] = 4;
    dec2.bits[0] = 6;
    // Задание степени
    set_scale(&dec, 0);
    set_scale(&dec2, 0);
    // Задание знака
    set_bit(&dec, 127, 1);
    set_bit(&dec2, 127, 0);
    ////////
    s21_add(dec, dec2, &result);

    // Результат
    // view_bit(dec.bits[0]);
    // view_bit(dec2.bits[0]);
    // view_bit(get_scale(dec));
    // view_bit(get_scale(dec2));
    printf("\n");
    printf("%d\n", result.bits[0]);
    view_bit(result.bits[0]);
    printf("%d\n", get_scale(result));
    view_bit(result.bits[3]);
    printf("%d\n", error);
}