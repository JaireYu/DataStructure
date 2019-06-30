#include <iostream>
#define n 10
void change(int num[], int i);
void print(int *num);
int main() {
    int i, flag = 0, left = 0, right = n - 1;
    int num[n];
    for(i = 0; i < n; i ++) {
        scanf("%d", &num[i]);
    }
    while(left < right) {
        switch(flag) {
            case 0: {
                for(i = left; i < right; i ++) {
                    if(num[i] > num[i + 1]) {
                        change(num, i);
                    }
                }
                right --;
                flag = 1;
            }
            break;
            default: {
                for(i = right; i > left; i --) {
                    if(num[i] < num[i - 1]) {
                        change(num, i - 1);
                    }
                }
                left ++;
                flag = 0;
            }
        }

    }
    print(num);
    return 0;
}
void change(int num[], int i) {
    int temp;
    temp = num[i];
    num[i] = num[i + 1];
    num[i + 1] = temp;
}
void print(int *num) {
    int i;
    for(i = 0; i < n ; i ++) {
        printf("%d", *num + i);
    }
}