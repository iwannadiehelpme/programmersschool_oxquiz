#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// quiz_len은 배열 quiz의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* quiz[], size_t quiz_len)
{
    char** answer = (char**)malloc(quiz_len * sizeof(char*));
    for (int i = 0; i < quiz_len; i++)
    {
        char* elements = strtok((char*)quiz[i], " ");
        // strtok을 이용한 문자열 가르기. 공백을 기준으로 요소를 elements 배열에 저장한다. ex) "3 + 4 = 7" -> 3,+,4,=,7
        // 여기서는 3 만 저장함. 같은 방식을 사용해서 또 찾음.
        int x, y, z, result;
        char operator;
        // x 자릿값
        x = atoi(elements);
        // 저 위에서 미리 저장해뒀던 거를 꺼내서 씀 (3)
        elements = strtok(NULL, " ");
        // 두번째 strtok() 를 호출할 때 입력문자열 대신 NULL 값을 주면 바로 이전에 사용되었던 문자열을 끄집어내서 사용하게 된다.
        operator = elements[0];
        // operator 같은 경우는 숫자가 아니기에 atoi를 사용하지 않는다.
        elements = strtok(NULL, " ");
        y = atoi(elements);
        elements = strtok(NULL, " ");
        // 이제 등호가 나올 차례인데 등호는 쓰지 않으므로 operator에 넣지 않을거임.
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
