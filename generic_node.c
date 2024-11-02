#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User {
	char firstName[60];
	char lastName[60];
	int age;
} User;

typedef struct Node {
	void* data;
	struct Node* next;
} Node;


int main(void) {

	printf("############## User List\n");
	Node* head = NULL;
	Node* current = NULL;

	head = (Node*) malloc(sizeof(Node));

	if (head == NULL) {
		perror("Cannot allocate more memory for Node");
		exit(EXIT_FAILURE);
	}

	head->data = malloc(sizeof(User));
	if (head->data == NULL) {
		perror("Cannot allocate more memory for User data");
		free(head);
		exit(EXIT_FAILURE);
	}

	User user1;
	snprintf(user1.firstName, sizeof(user1.firstName), "Arson");
	snprintf(user1.lastName, sizeof(user1.lastName), "Marianus");
	user1.age = 26;

	memcpy(head->data, &user1, sizeof(User));
	head->next = current;

	User *userData1 = (User*) head->data;

	printf("First Name : %s\n", userData1->firstName);
	printf("Last Name  : %s\n", userData1->lastName);
	printf("Age        : %d\n", userData1->age);


	free(head->data);
	free(head);

	return 0;
}
