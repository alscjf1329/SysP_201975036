#include <stdio.h>

int main(int argc, char *argv[]) {
    // ���ڰ� ���� ��
    if (argc > 1){
        while (1){
            for (int i=1; i<argc; i++){
                printf("%s ", argv[i]);
            }
            printf("\n");
        }
    }
    // ���ڰ� ���� ��
    else {
        while (1) {
            printf("y\n");
        }
    }

    return 0;
}