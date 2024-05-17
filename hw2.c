#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void clearScreen() {
    system("cls");
}

void showCustomScreen() {
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

int Password() {
    int password = 2024; 
    int inputPassword; 
    int attempts = 0; 

    while (attempts < 3) {
        clearScreen(); 
        showCustomScreen(); 
        printf("Please enter your 4-digit password(2024): ");
        scanf("%d", &inputPassword);
        if (inputPassword == password) {
            printf("Correct password!\n");
            system("pause");
            return 1;
        } 
		else {
            attempts++;
            printf("Incorrect password! Attempts left: %d\n", 3 - attempts);
        }
    }
    printf("You have entered the wrong password too many times. Exiting...\n");
    return 0;
}

void displayMainMenu() {
    clearScreen(); 
    printf("------------------------------------\n");
    printf("|  a. Draw Right-Angled Triangle   |\n");
    printf("|  b. Display Multiplication Table |\n");
    printf("|  c. Exit                         |\n");
    printf("------------------------------------\n");
} 

void Triangle(char ch) {
    clearScreen(); 
    if(ch<'a'||ch>'n'){
        printf("Invalid input! Please enter a character from 'a' to 'n'.\n");
        return;
    }
    int i, j;
    for(i=0;i<=(ch-'a');i++) {
        for(j=(ch-'a');j>i;j--){
            printf(" "); 
        }
        for(j=i;j>=0;j--){
            printf("%c",ch-j); 
        }
        printf("\n");
    }

    printf("\nPress any key to return to the main menu...");
    getch();
} 

void MultiplicationTable() {
    clearScreen(); 
    printf("Enter a number from 1 to 9: ");
    int num,i,j;
    scanf("%d", &num);
    if (num<1||num>9){
        printf("Invalid input! Please enter a number from 1 to 9.\n");
        return;
    }
    for( i=1;i<=num;i++) {
        for (j=1;j<=num;j++) {
            printf("%d\t",i*j);
        }
        printf("\n");
    }
    printf("\nPress any key to return to the main menu...");
    getch(); 
} 

int main() {
    if (Password()) {
        char choice;
        do {
            displayMainMenu(); 
            printf("Enter option: ");
            choice = getch(); 
            switch(choice) {
                case 'a':
                case 'A':
                    clearScreen(); 
                    printf("Enter a character from 'a' to 'n': ");
                    char ch;
                    scanf("%c",&ch); 
                    Triangle(ch); 
                    break;
                case 'b':
                case 'B':
                    MultiplicationTable(); 
                    break;
                case 'c':
                case 'C':
                    break;
                default:
                    printf("Invalid option! Please enter a, b, or c.\n");
            }
            if(choice=='C'||choice=='c'){
                printf("Continue? (y/n):");
                char cont;
                scanf("%c",&cont); 
                if (cont=='n'||cont=='N'){
                    printf("Exiting the program...\n");
                    break;
                }
                else if(cont=='y'||cont=='Y'){
                	displayMainMenu();
                	printf("Enter option:");
                  	choice = getch(); 
            		switch(choice){
                		case 'a':
                		case 'A':
                    		clearScreen(); 
                    		printf("Enter a character from 'a' to 'n': ");
                    		char ch;
                    		scanf(" %c", &ch); 
                    		Triangle(ch); 
                    		break;
                		case 'b':
                		case 'B':
                   			MultiplicationTable();
                    		break;
                		case 'c':
                		case 'C':
                    		break;
                		default:
                    		printf("Invalid option! Please enter a, b, or c.\n");
            		}
				}
            }
		system("pause");
        } 
		while (choice != 'c' && choice != 'C');
    }
    return 0;
}

