#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int day;
    char *month;
    int year;
} Dob;

typedef struct
{
    int reg_no;
    char *name;
    char address[20];
} Info;

typedef struct
{
    char *coll;
    char uni[15];
} College;

typedef struct
{
    Dob *dob;
    Info info;
    College college;
} Student;

void display(Student *stu)
{
    printf("The details are:\n");
    printf("\nDate of Birth is :\n");
    printf("%d %s %d", stu->dob->day, stu->dob->month, stu->dob->year);
    printf("\nThe roll no name and adress is:\n");
    printf("%d %s %s", stu->info.reg_no, stu->info.name, stu->info.address);
    printf("\nThe name of College and University is:\n");
    printf("%s %s", stu->college.coll, stu->college.uni);
}

void main()
{
    Student *stu;
    stu = (Student *)malloc(sizeof(Student));
    stu->dob = (Dob *)malloc(sizeof(Dob));
    stu->dob->month = (char *)malloc(10 * sizeof(char));
    stu->info.name = (char *)malloc(10 * sizeof(char));
    stu->college.coll = (char *)malloc(10 * sizeof(char));
    printf("\nEnter day month and year of birth:\n");
    scanf("%d %s %d", &(stu->dob->day), stu->dob->month, &(stu->dob->year));
    printf("\nEnter roll no name and address:\n");
    scanf("%d %s %s", &(stu->info.reg_no), stu->info.name, stu->info.address);
    printf("Enter name of College and University:\n");
    scanf("%s %s", stu->college.coll, stu->college.uni);
    display(stu);
}