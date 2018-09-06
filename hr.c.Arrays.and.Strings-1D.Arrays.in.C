#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);
    
    int sum = 0;
    int *arr = (int*)malloc(n * sizeof(int));//*arr points to the base address of the array
    
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    printf("%d", sum);
    return 0;
}
