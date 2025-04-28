#include <stdio.h>
#include <string.h>
#include <omp.h>

int isPalindrome(char *str) {
    int l = 0, r = strlen(str) - 1;
    while (l < r) {
        if (str[l++] != str[r--]) return 0;
    }
    return 1;
}

int main() {
    char *arr[] = {"racecar", "hello", "madam", "openai"};
    int n = 4;

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        if (isPalindrome(arr[i]))
            printf("Thread %d: %s is a palindrome\n", omp_get_thread_num(), arr[i]);
        else
            printf("Thread %d: %s is NOT a palindrome\n", omp_get_thread_num(), arr[i]);
    }
}
