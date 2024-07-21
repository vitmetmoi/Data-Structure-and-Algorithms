#include <stdio.h>
#include <stdlib.h>

// Define the structure for a student node
struct Student {
    int id;
    int score;
    struct Student* next;
};

// Function to create a new student node
struct Student* createStudent(int id, int score) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->id = id;
    newStudent->score = score;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a student at the end of the list
void insertStudent(struct Student** head, int id, int score) {
    struct Student* newStudent = createStudent(id, score);
    if (*head == NULL) {
        *head = newStudent;
        return;
    }
    struct Student* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newStudent;
}

// Function to print eligible students and count
void printEligibleStudents(struct Student* head, int Dmin) {
    struct Student* temp = head;
    int count = 0;
    struct Student* eligibleHead = NULL;

    // First pass: count eligible students and create a new list
    while (temp != NULL) {
        if (temp->score >= Dmin) {
            insertStudent(&eligibleHead, temp->id, temp->score);
            count++;
        }
        temp = temp->next;
    }

    // Print the count and eligible students
    printf("Tong so sinh vien tham du ky thi cuoi ky: %d\n", count);
    temp = eligibleHead;
    while (temp != NULL) {
        printf("%d %d\n", temp->id, temp->score);
        temp = temp->next;
    }

    // Free the eligible students list
    while (eligibleHead != NULL) {
        struct Student* toDelete = eligibleHead;
        eligibleHead = eligibleHead->next;
        free(toDelete);
    }
}

int main() {
    int n, Dmin;
    scanf("%d %d", &n, &Dmin);

    struct Student* head = NULL;

    // Read student data and create the linked list
    for (int i = 0; i < n; i++) {
        int id, score;
        scanf("%d %d", &id, &score);
        insertStudent(&head, id, score);
    }

    // Print eligible students
    printEligibleStudents(head, Dmin);

    // Free the memory
    while (head != NULL) {
        struct Student* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}