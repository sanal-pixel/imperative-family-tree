#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;


Person *create_person(const char *name, int age) {
    Person *person = malloc(sizeof(Person));

    if (person == NULL) {
        return NULL;
    }

    strcpy(person->name, name);
    person->age = age;
    person->father = NULL;
    person->mother = NULL;

    return person;
}


void person_info(const char *role, char *name_out, int *age_out) {
    printf("Enter name and age for %s: ", role);
    scanf("%s %d", name_out, age_out);
}




    
int main(void) {
    char name[50];
    int age;

    Person *people[7];

    person_info("paternal grandfather", name, &age);
    people[0] = create_person(name, age);

    person_info("paternal grandmother", name, &age);
    people[1] = create_person(name, age);

    person_info("maternal grandfather", name, &age);
    people[2] = create_person(name, age);

    person_info("maternal grandmother", name, &age);
    people[3] = create_person(name, age);

    person_info("father", name, &age);
    people[4] = create_person(name, age);

    person_info("mother", name, &age);
    people[5] = create_person(name, age);

    person_info("yourself", name, &age);
    people[6] = create_person(name, age);

    printf("\nAll seven family members have been entered!\n");

    return 0;
}


    
