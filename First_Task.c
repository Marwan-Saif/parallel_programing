#include <stdio.h>
#include <string.h>

#define USERNAME_LENGTH 50
#define PASSWORD_LENGTH 50
#define MAX_USERS 100

typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int numUsers = 0;

void registerUser( char* username,  char* password) {
    if (numUsers >= MAX_USERS) {
        printf("Max number of users reached!\n");
        return;
    }

    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);
    numUsers++;
    printf("User registered successfully!\n");
}

int loginUser( char* username,  char* password) {
    for (int i = 0; i < numUsers; i++) {
        User* currentUser = &users[i];
        if (strcmp(currentUser->username, username) == 0 &&
            strcmp(currentUser->password, password) == 0) {
            return i;
        }
    }
    return -1;
}

void getInput( char* prompt, char* input) {
    printf("%s", prompt);
    scanf("%s", input);
}

int main() {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];

    printf("Registration\n");
    getInput("username: ", username);
    getInput("password: ", password);
    registerUser(username, password);

    printf("\nLogin\n");
    getInput("your username: ", username);
    getInput("your password: ", password);
    int loggedInUserIndex = loginUser(username, password);
    if (loggedInUserIndex != -1) {
        printf("Loged in successfuly User_index: %d\n", loggedInUserIndex);
    } else {
        printf("Invalid data!\n");
    }

    return 0;
}
