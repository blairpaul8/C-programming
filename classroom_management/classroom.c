#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void manage_math() {
  system("clear");
  int a;
  printf("\n=== Math Class ===\n\n");
  printf("1.) Print Students\n");
  printf("2.) Add Student\n");
  printf("3.) Print Assignments\n");
  printf("4.) Add Assignment\n");
  printf("5.) Show indvidual students grades\n");
  printf("6.) Return to main menu\n\n");

  while (a != 6) {
    printf("Enter the number of the action you would like to take\n");
    printf(">> ");
    scanf("%d", &a);
    if (a == 6) {
      break;
    }
  }


}

int main() {
  int input;
  while (input != 5) {
    system("clear");
    printf("=== Classroom Management System ===\n\n");
    printf("1.) Math\n");
    printf("2.) English\n");
    printf("3.) Science\n");
    printf("4.) History\n\n");
    printf("5.) Close program\n\n");

    printf("Enter the number of the class to view\n");
    printf(">> ");
    scanf("%d", &input);

    if (input == 1) {
      manage_math();
    }
    if (input == 5) {
      break;
    }

  }


}
