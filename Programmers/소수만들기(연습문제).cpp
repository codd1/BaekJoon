// Summer/Winter Coding(~2018) > �Ҽ� ����� (Level 1) - 100��
// https://school.programmers.co.kr/learn/courses/30/lessons/12977

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// nums_len�� �迭 nums�� �����Դϴ�.
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    int num = 0;

    int prime_num = 0;
    int loop_count = 0;

    for (int i = 0; i < nums_len; i++) {
        for (int j = i + 1; j < nums_len; j++) {
            for (int k = j + 1; k < nums_len; k++) {
                num = nums[i] + nums[j] + nums[k];
                loop_count++;
                for (int l = 2; l < num; l++) {
                    if (num % l == 0) {
                        prime_num++;
                        break;
                    }
                }
            }
        }
    }

    /*printf("loop_count == %d\n", loop_count);
    printf("prime_num == %d\n", prime_num);*/

    answer = loop_count - prime_num;
    printf("%d", answer);

    return answer;
}

int main() {
    // �Ʒ� �����Ϳ� ���� ��: 4
    int nums[] = { 1,2,7,6,4 };
    size_t nums_len = 5;

    solution(nums, nums_len);
}