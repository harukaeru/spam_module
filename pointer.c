#include <stdio.h>

int main() {
    int num = 3;

    printf("%s", "int num;\n");
    printf("num: %d\n", num);
    // &: メモリアドレスを見る
    // *: メモリアドレスを指定するとそこににある値をとってくる
    printf("&num: %d\n", &num);

    *(&num) = 5;

    printf("\n%s", "*(&num);\n");
    printf("num: %d\n", num);
    printf("&num: %d\n", &num);

    int *pointer;

    pointer = &num;

    printf("\n%s", "int *pointer;\n");
    printf("*pointer: %d\n", *pointer);
    printf("pointer: %d\n", pointer);

    return(0);
}
