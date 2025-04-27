#include <stdio.h>
#include <stdlib.h>

struct batsman
{
    char name[20];
    int runs, score, balls, to_runs, to_bal, one_s, two_s, three_s, fours, sixes;
    int max_six, max_run, max_four;
    float str;
} player1[100], player3;

struct bowler
{
    char name[20];
    int run_given, wicket_taken, over;
    int max_wicket;
    float economy;
} player2[100], player4;

int main()
{
    int playerno, choice;
    int n, m, i;
    printf("enter the Batsman details\n");
    printf("enter the number of batsman:\n");
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        printf("enter the name of batsman %d:\n", i + 1);
        scanf("%s", player1[i].name);

        printf("enter the number of ones scored by player %d:\n", i + 1);
        scanf("%d", &player1[i].one_s);

        printf("enter the number of twos scored by player %d:\n", i + 1);
        scanf("%d", &player1[i].two_s);

        printf("enter the number of threes scored by player %d:\n", i + 1);
        scanf("%d", &player1[i].three_s);

        printf("enter the number of fours scored by player %d:\n", i + 1);
        scanf("%d", &player1[i].fours);

        printf("enter the number of sixes scored by player %d:\n", i + 1);
        scanf("%d", &player1[i].sixes);

        printf("enter the balls played by the  player %d:\n", i + 1);
        scanf("%d", &player1[i].balls);
    }

    printf("\nenter the Bowler details \n");
    printf("enter the number of bowler :\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("enter the name of bowler %d:\n", i + 1);
        scanf("%s", player2[i].name);

        printf("enter the runs given by the bowler %d:\n", i + 1);
        scanf("%d", &player2[i].run_given);

        printf("enter the over bowled by the bowler %d:\n", i + 1);
        scanf("%d", &player2[i].over);

        printf("enter the wickets taken by the bowler %d:\n", i + 1);
        scanf("%d", &player2[i].wicket_taken);
    }

    printf("\nThank you all details are recorded\n\n");

    do
    {
        printf("\n===========================================\n");
        printf("Enter your choice:\n");
        printf("1. Batsman details\n");
        printf("2. Bowler details\n");
        printf("3. Match summary\n");
        printf("4. Record\n");
        printf("5. Exit\n");
        printf("===========================================\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the batsman number to see his details:\n");
            scanf("%d", &playerno);
            if (playerno <= 0 || playerno > m)
            {
                printf("Invalid batsman number!\n");
                break;
            }
            playerno--;
            printf("\n+-----------------------------------------------------------------------------------+\n");
            printf("|                                BATSMAN DETAILS                                     |\n");
            printf("+------------------+--------+----------+--------+--------+------------------+\n");
            printf("| %-16s | %-6s | %-8s | %-6s | %-6s | %-16s |\n", "Batsman", "Runs", "Balls", "Fours", "Sixes", "Strike Rate");
            printf("+------------------+--------+----------+--------+--------+------------------+\n");

            player1[playerno].runs = (1 * player1[playerno].one_s) + (2 * player1[playerno].two_s) + (3 * player1[playerno].three_s) + (4 * player1[playerno].fours) + (6 * player1[playerno].sixes);
            player1[playerno].str = (player1[playerno].runs * 100.00) / player1[playerno].balls;
            printf("| %-16s | %-6d | %-8d | %-6d | %-6d | %-16.2f |\n",
                   player1[playerno].name,
                   player1[playerno].runs,
                   player1[playerno].balls,
                   player1[playerno].fours,
                   player1[playerno].sixes,
                   player1[playerno].str);
            printf("+------------------+--------+----------+--------+--------+------------------+\n");
            break;

        case 2:
            printf("Enter the bowler number to see his details:\n");
            scanf("%d", &playerno);
            if (playerno <= 0 || playerno > n)
            {
                printf("Invalid bowler number!\n");
                break;
            }
            playerno--;
            printf("\n+-----------------------------------------------------------------------+\n");
            printf("|                          BOWLER DETAILS                               |\n");
            printf("+------------------+--------+----------+--------+------------------+\n");
            printf("| %-16s | %-6s | %-8s | %-6s | %-16s |\n", "Bowler", "Overs", "Runs", "Wickets", "Economy");
            printf("+------------------+--------+----------+--------+------------------+\n");

            player2[playerno].economy = (float)player2[playerno].run_given / player2[playerno].over;
            printf("| %-16s | %-6d | %-8d | %-6d | %-16.2f |\n",
                   player2[playerno].name,
                   player2[playerno].over,
                   player2[playerno].run_given,
                   player2[playerno].wicket_taken,
                   player2[playerno].economy);
            printf("+------------------+--------+----------+--------+------------------+\n");
            break;

        case 3:
            player3.to_runs = 0;
            printf("\n+-----------------------------------------------------------------------------------+\n");
            printf("|                                MATCH SUMMARY                                      |\n");
            printf("+-----------------------------------------------------------------------------------+\n");
            printf("|                                BATTING SCORECARD                                  |\n");
            printf("+------------------+--------+----------+--------+--------+------------------+\n");
            printf("| %-16s | %-6s | %-8s | %-6s | %-6s | %-16s |\n", "Batsman", "Runs", "Balls", "Fours", "Sixes", "Strike Rate");
            printf("+------------------+--------+----------+--------+--------+------------------+\n");

            for (i = 0; i < m; i++)
            {
                player1[i].runs = (1 * player1[i].one_s) + (2 * player1[i].two_s) + (3 * player1[i].three_s) + (4 * player1[i].fours) + (6 * player1[i].sixes);
                player3.to_runs += player1[i].runs;
                player1[i].str = (player1[i].runs * 100.00) / player1[i].balls;
                printf("| %-16s | %-6d | %-8d | %-6d | %-6d | %-16.2f |\n",
                       player1[i].name,
                       player1[i].runs,
                       player1[i].balls,
                       player1[i].fours,
                       player1[i].sixes,
                       player1[i].str);
            }
            printf("+------------------+--------+----------+--------+--------+------------------+\n");
            printf("| TOTAL RUNS: %-51d                |\n", player3.to_runs);
            printf("+-----------------------------------------------------------------------------------+\n");

            printf("\n+-----------------------------------------------------------------------+\n");
            printf("|                          BOWLING SCORECARD                            |\n");
            printf("+------------------+--------+----------+--------+------------------+\n");
            printf("| %-16s | %-6s | %-8s | %-6s | %-16s |\n", "Bowler", "Overs", "Runs", "Wickets", "Economy");
            printf("+------------------+--------+----------+--------+------------------+\n");

            for (i = 0; i < n; i++)
            {
                player2[i].economy = (float)player2[i].run_given / player2[i].over;
                printf("| %-16s | %-6d | %-8d | %-6d | %-16.2f |\n",
                       player2[i].name,
                       player2[i].over,
                       player2[i].run_given,
                       player2[i].wicket_taken,
                       player2[i].economy);
            }
            printf("+------------------+--------+----------+--------+------------------+\n");
            break;

        case 4:
            player3.max_run = 0;
            player4.max_wicket = 0;
            player3.max_four = 0;
            player3.max_six = 0;

            for (i = 0; i < m; i++)
            {
                player1[i].runs = (1 * player1[i].one_s) + (2 * player1[i].two_s) + (3 * player1[i].three_s) + (4 * player1[i].fours) + (6 * player1[i].sixes);
                if (player3.max_run < player1[i].runs)
                {
                    player3.max_run = player1[i].runs;
                }

                if (player3.max_six < player1[i].sixes)
                {
                    player3.max_six = player1[i].sixes;
                }

                if (player3.max_four < player1[i].fours)
                {
                    player3.max_four = player1[i].fours;
                }
            }

            for (i = 0; i < n; i++)
            {
                if (player4.max_wicket < player2[i].wicket_taken)
                {
                    player4.max_wicket = player2[i].wicket_taken;
                }
            }

            printf("\n+-----------------------------------------------------------------------+\n");
            printf("|                          MATCH RECORDS                                |\n");
            printf("+-----------------------------------------------------------------------+\n");
            printf("| Highest runs scored by a batsman:  %-33d |\n", player3.max_run);
            printf("| Maximum fours scored by a batsman: %-33d |\n", player3.max_four);
            printf("| Maximum sixes scored by a batsman: %-33d |\n", player3.max_six);
            printf("| Maximum wickets taken by a bowler: %-33d |\n", player4.max_wicket);
            printf("+-----------------------------------------------------------------------+\n");
            break;

        case 5:
            printf("\nExiting program. Thank you!\n");
            exit(1);

        default:
            printf("\nPlease enter a correct choice (1-5)\n");
            break;
        }

    } while (choice != 5);

    return 0;
}
