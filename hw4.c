#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_STUDENTS 10
#define MIN_STUDENTS 5
#define ID_LENGTH 6
#define MAX_NAME_LENGTH 100

int password();
void personalscreen();
void grade_system();
void mainmenu();
void enter_grades();
void display_grades();
void search_grades();
void grade_ranking();
void exit_confirmation();

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

int main(){
    char choice;
    if(password()){
        do{
            mainmenu();
            printf("Enter option: ");
            choice=getch();
            switch (choice) {
                case 'a':
                case 'A':
                    system("cls");
                    enter_grades();
                    break;
                case 'b':
                case 'B':
                    system("cls");
                    display_grades();
                    break;
                case 'c':
                case 'C':
                    system("cls");
                    search_grades();
                    break;
                case 'd':
                case 'D':
                    system("cls");
                    grade_ranking();
                    break;
                case 'e':
                case 'E':
                    system("cls");
                    exit_confirmation();
                    break;
            }
        } while (1);
    }
    return 0;
}

void personalscreen(){
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

password(){
    int a=2024;
    int b;
    int c=0;
    while(c<3){
        system("cls");
        personalscreen();
        printf("Please enter your 4-digit password (2024): ");
        scanf("%d",&b);
        if(b==a){
            printf("Correct password!\n");
            system("pause");
            return 1;
        } 
		else{
            c++;
            printf("Incorrect password! Attempts left: %d\n", 3 - c);
        }
    }
    printf("You have entered the wrong password too many times. Exiting...\n");
    return 0;
}

mainmenu(){
    system("CLS");
    printf("------------------------------------\n");
    printf("|  a. Enter student grades         |\n");
    printf("|  b. Display student grades       |\n");
    printf("|  c. Search for student grades    |\n");
    printf("|  d. Grade ranking                |\n");
    printf("|  e. Exit system                  |\n");
    printf("------------------------------------\n");
}

void clear_screen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void flush_input(){
    int c;
    while((c=getchar())!='\n'&&c!=EOF);
}

int get_valid_integer(const char* prompt,int min,int max){
    int value;
    printf("%s", prompt);
    while (scanf("%d",&value)!= 1||value<min||value>max){
        flush_input();
        printf("Invalid input. %s",prompt);
    }
    flush_input();
    return value;
}

void get_student_data(Student* student){
    printf("Enter student name: ");
    fgets(student->name, MAX_NAME_LENGTH, stdin);
    student->name[strcspn(student->name,"\n")]='\0';

    student->id = get_valid_integer("Student ID (6 digit integer): ",100000,999999);
    student->math = get_valid_integer("Math score (0-100): ",0,100);
    student->physics = get_valid_integer("Physics score (0-100): ",0,100);
    student->english = get_valid_integer("English score (0-100): ",0,100);
    student->average = (student->math + student->physics + student->english) / 3.0;
}

enter_grades(){
    int n,i;
    n=get_valid_integer("Please enter the number of students (5~10): ",MIN_STUDENTS,MAX_STUDENTS);
    for(i=0;i<n;i++){
        printf("\nEnter details for student %d\n",i+1);
        get_student_data(&students[student_count]);
        student_count++;
    }
    printf("\nAll student data entered successfully.\n");
    system("pause");
}

display_grades(){
	int i;
    clear_screen();
    if(student_count==0){
        printf("No student data available.\n");
    } 
	else{
        for(i=0;i<student_count;i++){
            printf("Name: %s, ID: %06d, Math: %d, Physics: %d, English: %d, Average: %.1f\n",
                   students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
        }
    }
    printf("\nPress any key to return to the main menu...\n");
    getch();
}

search_grades(){
	int i;
    char search_name[MAX_NAME_LENGTH];
    int found=0;
    clear_screen();
    printf("Enter the name of the student to search: ");
    fgets(search_name,MAX_NAME_LENGTH,stdin);
    search_name[strcspn(search_name,"\n")]='\0'; 
    for(i=0;i<student_count;i++){
        if(strcmp(students[i].name,search_name)==0){
            printf("Name: %s, ID: %06d, Math: %d, Physics: %d, English: %d, Average: %.1f\n",
                   students[i].name, students[i].id, students[i].math, students[i].physics, students[i].english, students[i].average);
            found=1;
            break;
        }
    }
    if(!found){
        printf("Student with name '%s' not found.\n",search_name);
    }
    printf("\nPress any key to return to the main menu...\n");
    getch();
}

grade_ranking(){
    clear_screen();
    int i,j;
    if(student_count==0){
        printf("No student data available.\n");
    } 
	else{
        Student temp_students[MAX_STUDENTS];
        memcpy(temp_students, students, sizeof(students));
        for(i=0;i<student_count-1;i++){
            for(j=0;j<student_count-i-1;j++){
                if(temp_students[j].average<temp_students[j+1].average){
                    Student temp=temp_students[j];
                    temp_students[j]=temp_students[j+1];
                    temp_students[j+1]=temp;
                }
            }
        }
        
        for (i = 0; i < student_count; i++) {
            printf("Name: %s, ID: %06d, Average: %.1f\n",
                   temp_students[i].name, temp_students[i].id, temp_students[i].average);
        }
    }
    printf("\nPress any key to return to the main menu...\n");
    getch();
}

exit_confirmation(){
    char choice;
    printf("Are you sure you want to exit? (y/n): ");
    while(1){
        choice=getch();
        if(choice =='y'||choice=='Y'){
            exit(0);
        }
		else if(choice=='n'||choice=='N'){
            return;
        } 
		else{
            printf("\nInvalid input. Please enter 'y' or 'n': ");
        }
    }
}
