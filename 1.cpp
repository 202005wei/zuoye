#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int num_of_problems;        // ��Ŀ����
    char operators[4] = {'+', '-', '*', '/'};  // �����
    int max_number;             // �����
    int use_parentheses;        // �Ƿ�ʹ������
    int use_decimal;            // �Ƿ�ʹ��С��
    int i, j;

    srand(time(NULL));          // ��ʼ�������������

    printf("������Ҫ���ɵ���Ŀ������");
    scanf("%d", &num_of_problems);

    printf("��ѡ���������+ - * /����");
    for (i = 0; i < 4; i++) {
        printf("%c ", operators[i]);
    }
    printf("\n");
    char operator_chosen;
    scanf(" %c", &operator_chosen);

    printf("�������������");
    scanf("%d", &max_number);

    printf("�Ƿ�ʹ�����ţ�0Ϊ��ʹ�ã�1Ϊʹ�ã���");
    scanf("%d", &use_parentheses);

    printf("�Ƿ�ʹ��С����0Ϊ��ʹ�ã�1Ϊʹ�ã���");
    scanf("%d", &use_decimal);

    // ���ɲ������Ŀ
    for (i = 0; i < num_of_problems; i++) {
        // �������������
        int num1 = rand() % max_number + 1;
        int num2 = rand() % max_number + 1;

        // ���ʹ��С����������С��
        if (use_decimal) {
            num1 += rand() % 10 / 10.0;
            num2 += rand() % 10 / 10.0;
        }

        // ѡ�������
        char op = operator_chosen;
        if (op == ' ') {
            op = operators[rand() % 4];
        }

        // ���ʹ�����ţ�����������Ƿ�ʹ������
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
