#include <stdio.h>
#include <stdlib.h>

long long getMaxCombination(long long num) {
    int counts[10] = {0};
    while (num > 0) {
        counts[num % 10]++;
        num /= 10;
    }
    
    long long maxNum = 0;
    for (int i = 9; i >= 0; i--) {
        while (counts[i] > 0) {
            maxNum = maxNum * 10 + i;
            counts[i]--;
        }
    }
    return maxNum;
}

int compare(const void *a, const void *b) {
    long long valA = *(const long long *)a;
    long long valB = *(const long long *)b;
    
    if (valA < valB) return -1;
    if (valA > valB) return 1;
    return 0;
}

int main() {
    long long arr[10000]; 
    int count = 0;
    long long input;
    
    while (scanf("%lld", &input) == 1 && input != 0) {
        arr[count] = getMaxCombination(input);
        count++;
    }
    qsort(arr, count, sizeof(long long), compare);
    
    for (int i = 0; i < count; i++) {
        printf("%lld\n", arr[i]);
    }
    
    return 0;
}