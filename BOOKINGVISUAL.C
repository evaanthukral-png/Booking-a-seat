#include <stdio.h>
#define row 8
#define col 5
void function(int a[row][col]) {
    printf("=====================================\n");
    printf("\nTrain Seat Layout (O = Free, X = Booked)\n");
    printf("=====================================\n");
    for(int i=0; i<row; i++) {
        printf("Row %d:\t", i + 1);
        for(int j=0; j<col; j++) {
            if(a[i][j] == 0)
                printf("O\t");
            else
                printf("X\t");
        }
        printf("\n");
    }
    printf("=====================================\n");
}
int main() {
    int a[row][col] = {0};  
    char ch;
    int nos, i, j, t;
    int tbooked = 0;
    int tseats = 40;

    do {
        if (tbooked == tseats) {
            printf("Train fully booked. No seats available.\n");
            break;
        }

        printf("Enter B to book seats (Enter E to exit)\n");
        printf("Enter your choice: ");
        scanf(" %c", &ch);

        if (ch != 'B' && ch != 'E') {
            printf("Invalid choice. Try again.\n");
            continue;
        }


        if (ch == 'B') {
            function(a);
            while (1) {
                printf("Enter no of seats to book (1-%d): ",tseats - tbooked);
                if (scanf("%d", &nos) == 0) {
                    printf("Invalid input. Please enter a number.\n");
                    int c;
                    while (getchar() != '\n');
                    continue;
                }

                if (nos > 0 && nos <= (40 - tbooked))
                    break;
                else
                    printf("Not a valid input. Try again\n");
            }

            t = nos;
            for (i = 0; i < 8 && t > 0; i++) {
                for (j = 0; j < 5 && t > 0; j++) {
                    if (a[i][j] == 0) {
                        a[i][j] = 1;
                        tbooked++;
                        printf("Seat booked -> Row %d Seat %d\n", i+1, j+1);
                        t--;
                    }
                }
            }

            if (t > 0) {
                printf("Not enough seats left to complete booking.\n");
            }
        }

    } while (ch != 'E');
    return 0;
}
