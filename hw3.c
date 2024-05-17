#include <stdio.h>
#include <stdlib.h>
void function_1();

int main(){
	Password();
} 

void function_1(){
	printf("  ***     ***     ***     ***  \n");
    printf(" *****   *****   *****   ***** \n");
    printf("*************** ***************\n");
    printf(" *************   ************* \n");
    printf("  ***********     ***********  \n");
    printf("   *********       *********   \n");
    printf("    *******         *******    \n");
    printf("     *****           *****     \n");
    printf("      ***             ***      \n");
    printf("       *               *       \n");
    printf("       *               *       \n");
    printf("      * *             * *      \n");
    printf("     *   *           *   *     \n");
    printf("    *     *         *     *    \n");
    printf("   *       *       *       *   \n");
    printf("  *         *     *         *  \n");
    printf(" *           *   *           * \n");
    printf("*             * *             *\n");
    printf(" *   *   *   *   *   *   *   * \n");
    printf("  * *     * *     * *     * *  \n");
}

int Password(){
    int a=2024; 
    int b; 
    int c=0; 

    while(c<3){
        system("cls");
        function_1();
        printf("Please enter your 4-digit password(2024): ");
        scanf("%d", &b);
        if (b==a) {
            printf("Correct password!\n");
            system("pause");
            return 1;
        } 
		else {
            c++;
            printf("Incorrect password! Attempts left: %d\n", 3-c);
        }
    }
    printf("You have entered the wrong password too many times. Exiting...\n");
    return 0;
}
