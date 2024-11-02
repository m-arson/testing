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

	User user1, user2;
	snprintf(user1.firstName, sizeof(user1.firstName), "Arson");
	snprintf(user1.lastName, sizeof(user1.lastName), "Marianus");
	user1.age = 26;

	memcpy(head->data, &user1, sizeof(User));
	head->next = NULL;

	current = (Node*) malloc(sizeof(Node));
	if (current == NULL) {
		free(head);
		free(head->data);
		perror("Cannot allocate more memory for Node");
		exit(EXIT_FAILURE);
	}

	current->data = malloc(sizeof(User));
	if (current->data == NULL) {
		free(head);
		free(head->data);
		free(current);
		perror("Cannot allocate more memory for User Data");
		exit(EXIT_FAILURE);
	}

	snprintf(user2.firstName, sizeof(user2.firstName), "Koila");
	snprintf(user2.lastName, sizeof(user2.lastName), "Jeniffer");
	user2.age = 30;

	memcpy(current->data, &user2, sizeof(User));
	current->next = NULL;

	head->next = current;

	User *userdata1 = (User*) head->data;
	User *userdata2 = (User*) head->next->data;

	printf("User 1 :\n");
	printf("FirstName : %s\n", userdata1->firstName);
	printf("LastName  : %s\n", userdata1->lastName);
	printf("Age       : %d\n", userdata1->age);

	printf("\nUser 2 :\n");
	printf("FirstName : %s\n", userdata2->firstName);
	printf("LastName  : %s\n", userdata2->lastName);
	printf("Age       : %d\n", userdata2->age);

	free(current->data);
	free(current);
	free(head->data);
	free(head);

	return 0;
}
