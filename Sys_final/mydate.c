#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm* time_info;
    char time_string[50];

    // ���� �ð� ������ ������
    time(&current_time);
    time_info = localtime(&current_time);

    // ����ȭ�� �ð� ���ڿ��� ��ȯ
    strftime(time_string, sizeof(time_string), "%c", time_info);

    // ���
    printf("%s\n", time_string);

    return 0;
}
