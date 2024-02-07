#include "decimal.h"

//Полная залупа
// int int2decimal(int src, s21_decimal *dst){
//     // unsigned int var_int = 0;
//     // int shift = 1;
//     // var_int = src & (shift << 31);
//     // // printf("%u\n", var_int);
//     // set_bit(dst, 127, var_int);
//     // // printf("%u\n", var_int);
//     // // printf("%u\n", get_bit(dst, 127));
//     // if (src < 0)
//     //     src = ~src + 1;
//     // for (int i = 0; i < 31; i++){
//     //     var_int = src & (shift << i);
//     //     set_bit(dst, i, var_int);
//     // }
//     int var_int = 0;
//     for (int i = 0; i < 96; i++){
//         var_int += get_bit(dst, i);


//     }
//     return 0;
// }
// // Добавить проверку на степень и последнего бита
// int decimal2int(s21_decimal src, int *dst){
//     unsigned int sign = 0;
//     int shift = 1, error = 0;
//     if (src.bits[1] == 0 & src.bits[2] == 0){
//         if (get_bit(&src, 127) == 1)
//             *dst = (~src.bits[0] + 1);
//         else
//             *dst = src.bits[0];
//     }
//     else
//         error = 1;
//     return error;
// }