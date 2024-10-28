#include <stdio.h>

int somaArray(int array[], int n) {
    if (n == 0) {
        return 0;
    }
    return array[n - 1] + somaArray(array, n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int resultado = somaArray(arr, n);
    printf("%d", resultado);

    return 0;
}
