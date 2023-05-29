/*
*****************************************************************************
                          Workshop - #7 (P1)
Full Name  : GLEISON VIEIRA DUTRA
Student ID#: 119237220
Email      : gvieira-dutra@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define PATHMIN 10
#define PATHMAX 70
#define MINLIVES 1
#define MAXLIVES 10
#define MULTIPLE 5


int main(void)
{

    struct PlayerInfo
    {
        int lives;
        char symbol;
        int treasure;
        int history[PATHMAX];
    };

    struct GameInfo
    {
        int moves;
        int lenght;
        int bomb[PATHMAX];
        int treasure[PATHMAX];
    };

    int i, j, nMove;

    struct PlayerInfo player1 = { 0 };
    struct GameInfo game1 = { 0 };


    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");


    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player1.symbol);

    do {
        printf("Set the number of lives: ");
        scanf("%d", &player1.lives);
        if (player1.lives < MINLIVES || player1.lives > MAXLIVES)
        {
            printf("     Must be between 1 and 10!\n");
        }
    } while (player1.lives < MINLIVES || player1.lives > MAXLIVES);

    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    do {

        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE, PATHMIN, PATHMAX);
        scanf("%d", &game1.lenght);

        if ((game1.lenght < PATHMIN || game1.lenght > PATHMAX) || (game1.lenght % MULTIPLE != 0))
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, PATHMIN, PATHMAX);
        }

    } while ((game1.lenght < PATHMIN || game1.lenght > PATHMAX) || (game1.lenght % MULTIPLE != 0));

    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game1.moves);
        if (game1.moves < player1.lives || (game1.moves > (int)(game1.lenght * 0.75)))
        {
            printf("    Value must be between %d and %d\n", player1.lives, (int)(game1.lenght * 0.75));
        }
    } while (game1.moves < player1.lives || (game1.moves > (int)(game1.lenght * 0.75)));

    printf("\nBOMB Placement\n");
    printf("--------------\n");

    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game1.lenght);
    
    for (i = 1; i <= game1.lenght; i += MULTIPLE)
    {
        printf("   Positions [%2d-%2d]: ", i, i + MULTIPLE - 1);
        for (j = 0; j < MULTIPLE; j++)
        {
            scanf("%d", &game1.bomb[j + i - 1]);
        }
    }

    printf("BOMB placement set\n");

    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game1.lenght);

    for (i = 1; i <= game1.lenght; i += MULTIPLE) //this loop asks user to input the positions of treasures, user will enter 5 positions at a time. 
    {
        printf("   Positions [%2d-%2d]: ", i, i + MULTIPLE - 1);
        for (j = 0; j < MULTIPLE; j++) // this loop will collect the values of the positions, 5 numbers collected on the same line. 
        {
            scanf("%d", &game1.treasure[j + i - 1]);
        }
    }

    printf("TREASURE placement set\n");

    printf("\nGAME configuration set-up is complete...\n");

    printf("\n------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player1.symbol);
    printf("   Lives      : %d\n", player1.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");

    printf("\nGame:\n");
    printf("   Path Length: %d\n", game1.lenght);


    printf("   Bombs      : ");
    for (i = 0; i < game1.lenght; i++)
    {
        printf("%d", game1.bomb[i]);

    }

    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game1.lenght; i++)
    {
        printf("%d", game1.treasure[i]);

    }

    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    printf("\n  ");
    for (i = 0; i < game1.lenght; i++)
    {
        if (player1.history[i] == 0)
        {
        printf("-");
        }
    }
    printf("\n  ");
    for (i = 1; i <= game1.lenght; i++)
    {
        if (i % 10 != 0)
        {
            printf("|");
        }
        else
        {
            printf("%d",i/10);
        }
    }
     printf("\n  ");
    for (i = 1; i <= game1.lenght; i++)
    {
        printf("%d", i%10);
    }

    printf("\n+---------------------------------------------------+\n");
    printf("  Lives:%3d  | Treasures:%3d  |  Moves Remaining:%3d\n", player1.lives, player1.treasure, game1.moves);
    printf("+---------------------------------------------------+\n");
    
    do {

        do {
        printf("Next Move [1-%d]: ", game1.lenght);
        scanf("%d", &nMove);
        if (nMove < 1 || nMove > game1.lenght)
            {
            printf("  Out of Range!!!\n");
            }
        } while (nMove < 1 || nMove > game1.lenght);

        if (player1.history[nMove-1] != 0) 
        {
            printf("\n===============> Dope! You've been here before!\n");
            printf("\n  ");
            for (i = 0; i < nMove - 1; i++)
            {
                printf(" ");
            }
            printf("%c", player1.symbol);
            printf("\n  ");
            for (i = 0; i < game1.lenght; i++)
            {
                if (player1.history[i] == 0)
                {
                    printf("-");
                }
                else if (player1.history[i] == 1)
                {
                    printf(".");
                }
                else if (player1.history[i] == 2)
                {
                    printf("!");
                }
                else if (player1.history[i] == 3)
                {
                    printf("$");
                }
                else if (player1.history[i] == 4)
                {
                    printf("&");
                }
            }
            printf("\n  ");
            for (i = 1; i <= game1.lenght; i++)
            {
                if (i % 10 != 0)
                {
                    printf("|");
                }
                else
                {
                    printf("%d", i / 10);
                }
            }
            printf("\n  ");
            for (i = 1; i <= game1.lenght; i++)
            {
                printf("%d", i % 10);
            }

            printf("\n+---------------------------------------------------+\n");
            printf("  Lives:%3d  | Treasures:%3d  |  Moves Remaining:%3d\n", player1.lives, player1.treasure, game1.moves);
            printf("+---------------------------------------------------+\n");
        }
        else 
        {
            if (game1.bomb[nMove - 1] == 0 && game1.treasure[nMove - 1] == 0)
            {
                printf("\n===============> [.] ...Nothing found here... [.]\n");
                player1.history[nMove - 1] = 1;
                game1.moves -= 1;
            }
            else if (game1.bomb[nMove - 1] == 1 && game1.treasure[nMove - 1] == 0)
            {
                printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
                player1.history[nMove - 1] = 2;
                player1.lives -= 1;
                game1.moves -= 1;
            }
            else if (game1.bomb[nMove - 1] == 0 && game1.treasure[nMove - 1] == 1)
            {
                printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
                player1.history[nMove - 1] = 3;
                game1.moves -= 1;
                player1.treasure += 1;
            }
            else if (game1.bomb[nMove - 1] == 1 && game1.treasure[nMove - 1] == 1)
            {
                printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                player1.history[nMove - 1] = 4;
                player1.lives -= 1;
                game1.moves -= 1;
                player1.treasure += 1;
            }

            if (player1.lives == 0)
            {
                printf("\nNo more LIVES remaining!\n");
            }
            if (game1.moves == 0)
            {
                printf("\nNo more MOVES remaining!\n");
            }

            printf("\n  ");
            for (i = 0; i < nMove - 1; i++)
            {
                printf(" ");
            }
            printf("%c", player1.symbol);
            printf("\n  ");
            for (i = 0; i < game1.lenght; i++)
            {
                if (player1.history[i] == 0)
                {
                    printf("-");
                }
                else if (player1.history[i] == 1)
                {
                    printf(".");
                }
                else if (player1.history[i] == 2)
                {
                    printf("!");
                }
                else if (player1.history[i] == 3)
                {
                    printf("$");
                }
                else if (player1.history[i] == 4)
                {
                    printf("&");
                }
            }
            printf("\n  ");
            for (i = 1; i <= game1.lenght; i++)
            {
                if (i % 10 != 0)
                {
                    printf("|");
                }
                else
                {
                    printf("%d", i / 10);
                }
            }
            printf("\n  ");
            for (i = 1; i <= game1.lenght; i++)
            {
                printf("%d", i % 10);
            }

            printf("\n+---------------------------------------------------+\n");
            printf("  Lives:%3d  | Treasures:%3d  |  Moves Remaining:%3d\n", player1.lives, player1.treasure, game1.moves);
            printf("+---------------------------------------------------+\n");

        }
    } while (player1.lives > 0 && game1.moves > 0);

    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");

    printf("\nYou should play again and try to beat your score!\n");
    

    return 0;
}