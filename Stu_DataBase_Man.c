#include <stdio.h>
#include <string.h>

struct student {
    int rollno;
    char name[50];
    char course[50];
    float marks[3];
    float total;
    float average;
};

// Function to calculate total and average
void calculate(struct student *s) {
    s->total = s->marks[0] + s->marks[1] + s->marks[2];
    s->average = s->total / 3.0;
}

// Function to display all student records
void display(struct student s[], int n) {
    printf("\nRollNo\tName\t\tCourse\t\tTotal\tAverage\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-10s\t%-10s\t%.2f\t%.2f\n", s[i].rollno, s[i].name, s[i].course, s[i].total, s[i].average);
    }
}

// Function to search student by roll number
void search(struct student s[], int n) {
    int r, found = 0;
    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &r);
    for (int i = 0; i < n; i++) {
        if (s[i].rollno == r) {
            printf("\nRecord Found:\n");
            printf("Roll No: %d\nName: %s\nCourse: %s\nTotal: %.2f\nAverage: %.2f\n",
                   s[i].rollno, s[i].name, s[i].course, s[i].total, s[i].average);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Record not found!\n");
}

// Function to sort students by total marks (descending order)
void sort(struct student s[], int n) {
    struct student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].total < s[j].total) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    printf("\nRecords Sorted by Total Marks (Descending Order):\n");
    display(s, n);
}

// Main Function
int main() {
    struct student s[50];
    int n, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter Roll No, Name, Course and 3 Subject Marks:\n");
        scanf("%d %s %s %f %f %f", &s[i].rollno, s[i].name, s[i].course,
              &s[i].marks[0], &s[i].marks[1], &s[i].marks[2]);
        calculate(&s[i]);
    }

    do {
        printf("\n--- STUDENT DATABASE MENU ---\n");
        printf("1. Display All Records\n");
        printf("2. Search by Roll Number\n");
        printf("3. Sort by Total Marks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            display(s, n);
            break;
        case 2:
            search(s, n);
            break;
        case 3:
            sort(s, n);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
