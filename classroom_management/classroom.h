#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct Student {
  char fname[20];
  char lname[20];
  int id;
  ClassList *classes;
  struct Student *next;
} Student;

typedef struct Class {
  char name[30];
  StudentList *students;
  AssignmentList *assignments;
  struct Class *next;
} Class;

typedef struct Assignment {
  char name[30];
  char category[30];
  HashTable *grades;
  struct Assignment *next;
} Assignment;
