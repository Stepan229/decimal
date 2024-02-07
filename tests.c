#include "decimal.h"

int main(){
    s21_decimal dec;
    s21_decimal dec2;
    s21_decimal result;
    zeroing_decimal(&result);
    zeroing_decimal(&dec);
    zeroing_decimal(&dec2);
    //dec.bits[0] = 0b11111111111111111111111111111111;
    dec.bits[0] = 11;
    write_scale(&dec, 10);

    dec2.bits[0] = 3;
    write_scale(&dec2, 10);
    view_bit(result.bits[0]);
    s21_mul(dec, dec2, &result);
    view_bit(result.bits[0]);
    view_bit(get_scale(result));
}