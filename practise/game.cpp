#include <stdio.h>

void shape();
int checkWinner(char arr[3][3], char sign);

int main() {
    char arr[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int i, j;
    char name1[20];
    char name2[20];
    char signature1, signature2;

    shape();
    printf("\n\n");
    printf("Instruction Of Games:\n-You have to choose a unique box at every move\n-And mark it with your signature sign\n-If you mark three consecutive boxes with your sign you win.\n");
    printf("\n");
    printf("Player 1\nEnter your name: ");
    fgets(name1, sizeof(name1), stdin);

    printf("Enter your signature (must be any character): ");
    scanf(" %c", &signature1);

    while ((getchar()) != '\n'); // Clear input buffer

    printf("Player 2\nEnter your name: ");
    fgets(name2, sizeof(name2), stdin);

    do {
        printf("Enter your signature (must be any character different from Player 1): ");
        scanf(" %c", &signature2);
        if (signature2 != signature1) {
            break;
        }
        printf("Your signature matches Player 1's. Please enter a different signature.\n");
    } while (1);

    printf("Choose the box by selecting row and column number (1 to 3)\n\n");
int turn;
    for (turn = 0; turn < 9; turn++) {
        printf("\nMove for Player 1:\n");
        printf("Enter your box: ");
        scanf("%d %d", &i, &j);
        if (arr[i - 1][j - 1] == signature1 || arr[i - 1][j - 1] == signature2) {
            printf("This box is already used\n");
            turn--;
            continue;
        }
        arr[i - 1][j - 1] = signature1;

        if (checkWinner(arr, signature1)) {
            printf("The Winner is Player 1. Champion %s\n", name1);
            break;
        }

        printf("\nMove for Player 2:\n");
        printf("Enter your box: ");
        scanf("%d %d", &i, &j);
        if (arr[i - 1][j - 1] == signature1 || arr[i - 1][j - 1] == signature2) {
            printf("This box is already used\n");
            turn--;
            continue;
        }
        arr[i - 1][j - 1] = signature2;

        if (checkWinner(arr, signature2)) {
            printf("The Winner is Player 2. Champion %s\n", name2);
            break;
        }
    }

    if(turn == 9) {
        printf("It's a draw!\n");
    }

    printf("Filled Array:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void shape() {
    printf("\n");
    printf("All boxes are empty and waiting for your move\n");

    int i, j;

    for (i = 0; i < 3; i++) {
        printf("\t\t");
        for (j = 0; j < 3; j++) {
            printf("____");
        }
        printf("_\n");
        printf("\t\t");
        for (j = 0; j < 3; j++) {
            printf("|   ");
        }
        printf("|\n");
    }

    printf("\t\t");
    for (i = 0; i < 3; i++) {
        printf("____");
    }
    printf("_\n");
}

int checkWinner(char arr[3][3], char sign) {
    for (int i = 0; i < 3; i++) {
        if ((arr[i][0] == sign && arr[i][1] == sign && arr[i][2] == sign) ||  
            (arr[0][i] == sign && arr[1][i] == sign && arr[2][i] == sign)) {
            return 1;
        }
    }
    if ((arr[0][0] == sign && arr[1][1] == sign && arr[2][2] == sign) ||  
        (arr[0][2] == sign && arr[1][1] == sign && arr[2][0] == sign)) {
        return 1;
    }
    return 0;
}

