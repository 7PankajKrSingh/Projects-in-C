#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int generatenrandomnumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int greater(char char1, char char2)
{
    if (char1 == char2)
    {
        return -1;
    }
    else if ((char1 == 'r') && (char2 == 's'))
    {
        return 1;
    }
    else if ((char2 == 'r') && (char1 == 's'))
    {
        return 0;
    }
    else if ((char1 == 'p') && (char2 == 'r'))
    {
        return 1;
    }
    else if ((char2 == 'p') && (char1 == 'r'))
    {
        return 0;
    }
    else if ((char1 == 's') && (char2 == 'p'))
    {
        return 1;
    }
    else if ((char2 == 's') && (char1 == 'p'))
    {
        return 0;
    }
}

int main()
{
    int playerscore = 0, compscore = 0, temp, n;
    char playerchar, compchar, name[10];
    char dict[] = {'q', 'r', 'p', 's'};
    printf("WELCOME TO ROCK PAPER SCISSOR GAME\n ENTER YOUR NAME :\n");
    scanf("%s", &name);
    getchar();
    printf("How many rounds you want to play :\n");
    scanf("%d", &n);
    getchar();

   
    for (int i = 0; i < n; i++)
    {

        printf("****%s's Turn****\n", name);
        printf("Choose 1 for Rock 2 for Paper 3 for Scissor\n");
        scanf("%d", &temp);
        getchar();
        playerchar = dict[temp];
        printf("You chose : %c\n", playerchar);

        printf("****CPU Turn****\n");
        temp = generatenrandomnumber(3) +2;
        compchar = dict[temp];
        printf("CPU chose : %c\n\n", compchar);

        
        if (greater(compchar, playerchar) == 1)
        {
            compscore += 1;
            printf("CPU got 1 point\n");
        }
        else if (greater(compchar, playerchar) == -1)
        {
            compscore += 1;
            playerscore += 1;
            printf("It's a Draw\n");
        }
        else
        {
            playerscore += 1;
            printf("You got 1 point\n");
        }
        printf("CPU SCORE : %d\n%s's SCORE : %d\n\n", compscore, name, playerscore);

    }
    if (playerscore > compscore)
    {
        printf("*************CONGRATS,YOU WON THE GAME*************\n");
    }
    else if (playerscore < compscore)
    {
        printf("*************CPU WON THE GAME*************\n");
    }
    else {
        printf("*************IT IS A DRAW*************\n ");
    }


    
return 0;
}
