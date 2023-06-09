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
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes+=1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Go through the list and find the max
    int maxCandVotes = candidates[0].votes;
    string maxCandName = candidates[0].name;
    for (int i = 0; i < candidate_count; i++)
    {
        if (maxCandVotes < candidates[i].votes)
        {
            maxCandVotes = candidates[i].votes;
            maxCandName = candidates[i].name;
            // printf("%s is more than %s\n", candidates[i].name, candidates[i+1].name);
        }
    }
    // Go through the list again and see if there are similar vote to max that's not first max
    printf("%s\n", maxCandName);
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == maxCandVotes && candidates[j].name != maxCandName)
        {
            printf("%s\n", candidates[j].name);
        }
    }
    return;
}