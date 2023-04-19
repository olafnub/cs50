#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define Data
    int cnum;
    float pnum;
    int day;
    int year;

    // Input Area
    printf("Enter Course Number ");
    scanf("%i", &cnum);
    printf("Enter project number ");
    scanf("%f", &pnum);
    printf("Enter day and year ");
    scanf("%i%i", &day, &year);

    // Output 
    printf("Andy Li\n\n");
    printf("Course Number Is: CSCI %i\n", cnum);
    printf("Introduction To Computing and Problem\n");
    printf("Project Number is: %f\n\n", pnum);
    printf("April %i, %i\n", day, year);

}