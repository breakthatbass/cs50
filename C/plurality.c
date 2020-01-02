#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{ 
    // array to store all the numbers of votes
    int votes_arr[candidate_count], index_num; 
    int double_num = 0;
    string win_one, win_two;
    // loop through votes array and add each element to the votes_array
    for (int i = 0; i < candidate_count; i++)
    {
        votes_arr[i] = candidates[i].votes;
    }

    // now loop through again to find any doubles
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (candidates[i].votes == candidates[j].votes)
            {
                double_num = candidates[i].votes;
                win_one = candidates[i].name;
                win_two = candidates[j].name;
            }
        }
    }
    //now loop through the votes_arr to find the largest number
    for (int i = 1; i < candidate_count; i++)
    {
        if (votes_arr[0] < votes_arr[i])
        {
            votes_arr[0] = votes_arr[i];
            // store the index number to late extract name associated with that number of votes
            index_num = i;
        }
    }

    if (double_num == 0)
        {
            printf("%s wins!\n", candidates[index_num].name);
        }
    else
    {
        printf("%s and %s win!\n", win_one, win_two);
    } 
}