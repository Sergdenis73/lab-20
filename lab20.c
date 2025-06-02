#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char surname[50];
    char name[50];
    char group[20];
    float scholarship;
} Student;

void input_students(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\nВведіть дані про студента #%d:\n", i + 1);
        printf("Прізвище: ");
        scanf("%s", students[i].surname);
        printf("Ім'я: ");
        scanf("%s", students[i].name);
        printf("Група: ");
        scanf("%s", students[i].group);
        printf("Стипендія (грн): ");
        scanf("%f", &students[i].scholarship);
    }
}

void print_students(const Student students[], int count) {
    printf("\nСписок студентів:\n");
    printf("------------------------------------------------------------\n");
    printf("| №  | Прізвище  | Ім'я    | Група   | Стипендія (грн) |\n");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("| %-2d | %-9s | %-7s | %-7s | %-15.2f |\n", 
               i + 1, 
               students[i].surname, 
               students[i].name, 
               students[i].group, 
               students[i].scholarship);
    }
    printf("------------------------------------------------------------\n");
}

int change_scholarship(Student students[], int count, const char *surname, float new_scholarship) {
    int found = 0;
    for (int i = 0; i < count; i++) {

        if (strcasecmp(students[i].surname, surname) == 0) {
            students[i].scholarship = new_scholarship;
            found = 1;
        }
    }
    return found;
}

int main() {
    system("chcp 65001");
    int student_count;
    printf("Введіть кількість студентів: ");
    scanf("%d", &student_count);
 
    Student students[student_count];
 
    input_students(students, student_count);
 
    printf("\nПочаткові дані:");
    print_students(students, student_count);
  
    char surname_to_find[50];
    float new_scholarship;
    
    printf("\nВведіть прізвище студента для зміни стипендії: ");
    scanf("%s", surname_to_find);
    printf("Введіть нову стипендію (грн): ");
    scanf("%f", &new_scholarship);
    
    if (change_scholarship(students, student_count, surname_to_find, new_scholarship)) {
        printf("\nДані успішно оновлені!\n");
    } else {
        printf("\nСтудента з прізвищем '%s' не знайдено.\n", surname_to_find);
    }
 
    printf("\nОновлені дані:");
    print_students(students, student_count);
    
    return 0;
}