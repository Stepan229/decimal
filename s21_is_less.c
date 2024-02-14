#include "decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2){
    int ans = 0;
    normalize(&value_1, &value_2);
    int sign_1 = get_bit(&value_1, 127), sign_2 = get_bit(&value_2, 127);
    if (sign_1 != sign_2){
        if (sign_1 == 1)
            ans = 1;
    }
    else
    {    
        if (value_1.bits[2] < value_2.bits[2])
            ans = 1;
        else if (value_1.bits[1] < value_2.bits[1])
            ans = 1;
        else if (value_1.bits[0] < value_2.bits[0])
            ans = 1;
    }
    return ans;
}
