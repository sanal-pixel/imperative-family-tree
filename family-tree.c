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
    printf("Enter %s's name: ", role);
    scanf(" %49[^\n]", name_out);

    printf("Enter %s's age: ", role);
    scanf("%d", age_out);
}


void link_parents(Person *child, Person *father, Person *mother) {
    child->father = father;
    child->mother = mother;
}


void print_family_relationships(const Person *me) {
    printf("\n--- Family Relationships ---\n");

    printf("Name: %s\n", me->name);
    printf("Age: %d\n", me->age);

    if (me->father != NULL) {
        printf("Father: %s\n", me->father->name);
    }

    if (me->mother != NULL) {
        printf("Mother: %s\n", me->mother->name);
    }

    if (me->father != NULL) {
        if (me->father->father != NULL) {
            printf("Paternal grandfather: %s\n",
                   me->father->father->name);
        }

        if (me->father->mother != NULL) {
            printf("Paternal grandmother: %s\n",
                   me->father->mother->name);
        }
    }

    if (me->mother != NULL) {
        if (me->mother->father != NULL) {
            printf("Maternal grandfather: %s\n",
                   me->mother->father->name);
        }

        if (me->mother->mother != NULL) {
            printf("Maternal grandmother: %s\n",
                   me->mother->mother->name);
        }
    }
}


void free_family_tree(Person *people[], int count) {
    for (int i = 0; i < count; i++) {
        free(people[i]);
    }
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

    
    link_parents(people[4], people[0], people[1]);
    link_parents(people[5], people[2], people[3]);
    link_parents(people[6], people[4], people[5]);


    print_family_relationships(people[6]);
    free_family_tree(people, 7);

    return 0;
}

