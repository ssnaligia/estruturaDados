#include <stdio.h>

int main() {
    int C;
    scanf("%d", &C);  
    
    int compareceram = 0; 
    
    for (int i = 0; i < C; i++) {
        int status;
        scanf("%d", &status);
        if (status == 1) {
            compareceram++; 
        }
    }
    
    printf("%d\n", compareceram); 
    
    return 0;
}
