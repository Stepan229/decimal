#include "decimal.h"
#include <math.h>

int normalize(s21_decimal *value_1, s21_decimal *value_2){
    unsigned int scale_1 = 0, scale_2 = 0;
    int difference_scale = 0, error = 0;
    s21_decimal ten;
    zeroing_decimal(&ten);
    ten.bits[0] = 10;
    scale_1 = get_scale(*value_1);
    scale_2 = get_scale(*value_2);
    difference_scale = scale_1 - scale_2;
    if (difference_scale < 0 && scale_2 < 29)
    {
        difference_scale = -difference_scale;
        scale_1 += difference_scale;
        for (int i = 0; i < difference_scale; i++)
        {
            error = s21_mul(*value_1, ten, value_1);
        }
        error = set_scale(value_1, scale_1);

    } 
    else if (difference_scale > 0 && scale_1 < 29)
    {
        scale_2  += difference_scale;
        for (int i = 0; i < difference_scale; i++)
        {
            error = s21_mul(*value_2, ten, value_2);
        }
        error = set_scale(value_2, scale_2);
    }
    return error;
}

int set_scale(s21_decimal *value,unsigned int scale){
    int error = 0;
    if (scale > 28)
        error = 1;
    scale = scale << 16;
    value->bits[3] = value->bits[3] | scale;
    return error;
}