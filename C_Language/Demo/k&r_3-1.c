#include <stdio.h>

int dichotomy(int x);

int main(void) {
    int target = 80;
    printf("%d",dichotomy(target));
}

int dichotomy(int x) {
    int low = 0,high = 100;

    if (x > high || x < low) {
        return -1;
    }

    int mid = (low + (high - low) / 2);
    while (high > low && mid != x) {
        if (mid > x) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
        mid = (low + (high - low) / 2);
    }
    return mid;
}