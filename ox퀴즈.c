#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// quiz_len�� �迭 quiz�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char** solution(const char* quiz[], size_t quiz_len)
{
    char** answer = (char**)malloc(quiz_len * sizeof(char*));
    for (int i = 0; i < quiz_len; i++)
    {
        char* elements = strtok((char*)quiz[i], " ");
        // strtok�� �̿��� ���ڿ� ������. ������ �������� ��Ҹ� elements �迭�� �����Ѵ�. ex) "3 + 4 = 7" -> 3,+,4,=,7
        // ���⼭�� 3 �� ������. ���� ����� ����ؼ� �� ã��.
        int x, y, z, result;
        char operator;
        // x �ڸ���
        x = atoi(elements);
        // �� ������ �̸� �����ص״� �Ÿ� ������ �� (3)
        elements = strtok(NULL, " ");
        // �ι�° strtok() �� ȣ���� �� �Է¹��ڿ� ��� NULL ���� �ָ� �ٷ� ������ ���Ǿ��� ���ڿ��� ������� ����ϰ� �ȴ�.
        operator = elements[0];
        // operator ���� ���� ���ڰ� �ƴϱ⿡ atoi�� ������� �ʴ´�.
        elements = strtok(NULL, " ");
        y = atoi(elements);
        elements = strtok(NULL, " ");
        // ���� ��ȣ�� ���� �����ε� ��ȣ�� ���� �����Ƿ� operator�� ���� ��������.
        elements = strtok(NULL, " ");
        z = atoi(elements);

        if (operator=='+')
            result = x + y;
        else
            result = x - y;

        if (result == z)
            answer[i] = "O";
        else
            answer[i] = "X";
    }
    return answer;
}
