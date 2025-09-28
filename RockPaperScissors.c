#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Kør dette i terminal før kode, for at godkende emojis
// chcp 65001
// $OutputEncoding = [Console]::OutputEncoding = [System.Text.UTF8Encoding]::new()

enum Outcome { TIE = 0, P1_WIN = 1, P2_WIN = 2 };

int check_winner(char choice) {

    int p1 = choice - '0'; //Fra Char til Int for p1 (User)
    int p2 = rand() % 5; //Computer
    int diff = p2 - p1;

    printf("Agent: %d\n", p2);

    if (diff == 0) {
        return TIE;
    } else if (diff == 1 || diff == 3 || diff == -4 || diff == -2){
        return P1_WIN;
    } else {
        return P2_WIN;
    }
}

int main(void) {

    char allowed_moves[] = {'0', '1', '2', '3', '4'};
    char game_mode; //Single player eller Exit
    char choice;
    int p1_score = 0; //Hvor mange gange p1 har vundet
    int p2_score = 0; //Hvor mange gange p2 har vundet
    srand((unsigned)time(NULL));


    printf("Welcome to 🪨  ✂️  🗒️  🖖  🦎 !"); //Velkomstbesked
    

    while(1) {
        //Indledende beskeder
        printf("\n(s) Single player \n(e) Exit");
        printf("\nSelect an item: ");
        scanf(" %c", &game_mode);

        //Tjekker for input
        if (game_mode == 's') {
            printf("\nStarting game 🎉\n");
        } else if (game_mode == 'e') {
            printf("\nExitting");
            return 0;
        } else {
            printf("\nNot a valid input. Please enter a valid input");
            continue;
        }

        while(1) {

            int valid = 0; //Identifier for om input er tilladt

            printf("\nSelect a shape \n0🪨  || 1🦎  || 2✂️  || 3🗒️  || 4🖖 : ");
            scanf(" %c", &choice);

            //For-loop for at tjekke om korrekt input
            for (int i = 0; i < 5; i++) {
                if (choice == allowed_moves[i]) {
                    valid = 1; //Sætter identifier til 1, hvis input er godkendt
                    break;
                } 
            }

            //Hvis input ikke er godkendt, starter den det indre while-loop forfra
            if (!valid) {
                printf("❌ Shape key %c does not exist. Try again.\n", choice);
                continue;
            }
            
            
            int result = check_winner(choice);

            if (result == P1_WIN) {
                p1_score ++;
            } else if (result == P2_WIN) {
                p2_score ++;
            } else if (result == TIE) {
                printf("👫:🤖  %d : %d\n", p1_score, p2_score);
                continue;
            }

            printf("👫:🤖  %d : %d\n", p1_score, p2_score);


            if (p1_score == 5) {
                printf("👫 Player won!");
                return 0;
            } else if (p2_score == 5) {
                printf("🤖 Agent won!");
                return 0;
            }

        }
    }
}

