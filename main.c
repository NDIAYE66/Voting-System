#include <stdio.h>
#include <stdlib.h>
#include "Candidate.h"        ///file of the candidates's structure

void bubbleSort(struct Candidate *can, const int n);
void printResult(struct Candidate *can, const int n);

int main()
{

    int i, j, N_Candidates, N_vote, tmp;
    char b[20];
    do{
         printf("Input the number of Candidates: \n");
         scanf("%d", &N_Candidates);
         if(N_Candidates <= 0 )
            printf("Please input a valid number \n");
    }
    while(N_Candidates <= 0);                       ///To check if the number inputted is valid

    printf("Input their code or voting ID: \n");
    for(i=0; i<N_Candidates; i++)
    {
        scanf("%s", candidates[i].code);
    }
    do{
         printf("Input the numbers of voters: \n");
         scanf("%d", &N_vote);
         if(N_vote <= 0 )
            printf("Please input a valid number \n");
      }
    while(N_vote <= 0);                             ///To check if the number inputted is valid

    printf("\n\n\n\n");
    printf("You may start the vote\n");
    printf("===========================================================================\n");


    printf("Press ENTER after inputing the code or voting ID of your candidate\n");

    for(i=0; i<N_vote; i++)
    {
      do{
        tmp=0;
        scanf("%s", b);                         /// Input the code of the candidate

        for (j=0; j<N_Candidates; j++)
        {
            if(strcmp(b,candidates[j].code)==0){/// go through all the candidates to check if the code inputed correspond to any candidates
                candidates[j].score++;          /// if yes then increment the score of that candidate
                tmp = 1;                        /// validate the vote
            }
        }
        if(tmp==0)                             /// if the vote has not been validated the value of tmp is still 0
            printf("Invalid vote !\n Please input a valid candidate ID\n");
       }
     while(tmp == 0);                         /// Loop if the vote is invalid

    }

    bubbleSort(candidates, N_Candidates);      /// Sort the results using the bubble sort algo, check its implementation below
    printResult(candidates, N_Candidates);     /// Print the results, find its implementation below

    if(candidates[0].score == candidates[1].score) /// After sorting if the first two candidates has the same score,
                                                   ///then they may vote again
        printf("You may vote again !\n");
    else
        printf("Congratulations on %s for winning the Championship\n", candidates[0].code);


    return 0;
}


///Sorting Function
void bubbleSort(struct Candidate *can, const int n)
{
    int i, j;
    struct Candidate tp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(candidates[j+1].score > candidates[j].score)
            {                                              ///switch orders
                tp = candidates[j];
                candidates[j] = candidates[j+1];
                candidates[j+1] = tp;
            }
        }
    }

}

///Printing Function to print the results
void printResult(struct Candidate *can, const int n)
{
    int i, j;
    printf("*************************************************************************\n");
    printf("Here are the Results\n");
    for(i=0;i<n;i++){
        printf("%s: %d\n", candidates[i].code, candidates[i].score);
    }

}
