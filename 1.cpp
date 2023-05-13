#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int num_of_problems;        // 题目数量
    char operators[4] = {'+', '-', '*', '/'};  // 运算符
    int max_number;             // 最大数
    int use_parentheses;        // 是否使用括号
    int use_decimal;            // 是否使用小数
    int i, j;

    srand(time(NULL));          // 初始化随机数生成器

    printf("请输入要生成的题目数量：");
    scanf("%d", &num_of_problems);

    printf("请选择运算符（+ - * /）：");
    for (i = 0; i < 4; i++) {
        printf("%c ", operators[i]);
    }
    printf("\n");
    char operator_chosen;
    scanf(" %c", &operator_chosen);

    printf("请输入最大数：");
    scanf("%d", &max_number);

    printf("是否使用括号（0为不使用，1为使用）：");
    scanf("%d", &use_parentheses);

    printf("是否使用小数（0为不使用，1为使用）：");
    scanf("%d", &use_decimal);

    // 生成并输出题目
    for (i = 0; i < num_of_problems; i++) {
        // 随机生成两个数
        int num1 = rand() % max_number + 1;
        int num2 = rand() % max_number + 1;

        // 如果使用小数，则生成小数
        if (use_decimal) {
            num1 += rand() % 10 / 10.0;
            num2 += rand() % 10 / 10.0;
        }

        // 选择运算符
        char op = operator_chosen;
        if (op == ' ') {
            op = operators[rand() % 4];
        }

        // 如果使用括号，则随机决定是否使用括号
        if (use_parentheses) {
            if (rand() % 2 == 0) {
                printf("(");
            }
        }

        printf("%d %c %d", num1, op, num2);

        if (use_parentheses) {
            if (rand() % 2 == 0) {
                printf(")");
            }
        }

        printf(" =\n");
    }

    return 0;
}
