// This program takes in a fraction
// calculates and outputs its terms
// based on Euclidean method of GCD

// include header files
#include <stdio.h>
#include <math.h>
// function prototype inclusions
int possible_answer(int x, int y);
void result(int x, int y, int possible_answer);

int main(int returned){ // function main() starts execution
    // declare variables
    int m, n, temp, gcd, menu;

    while (menu!=-1){
        // prompt user to input m and n
        printf("Enter a fraction: ");
        if(scanf("%d/%d", &m, &n)!=2){ // if input does not consist of two integers
            printf("Invalid input.\n"); // alert user
            break; // end program
        } else { // if input consists of two integers
            // make sure m is positive
            if (m<0)
                m = -m;

            // make sure n is positive
            if (n<0)
                n = -n;

            if (m==0)
                gcd = n; //set gcd to value of m following Euclidean rules
            else {
                returned = possible_answer(m,n); // call function possible_answer()
                result(m,n,returned); // call function result()
            }
        }
        // prompt user to determine next operation
        printf("\n(1) to restart program, (-1) to end program.\n");
        scanf("%d", &menu);
    }
    return 0; // to indicate successful execution
}


// function possible_answer()
// takes in two inputs and outputs their GCD
int possible_answer(int x, int y){
     // declare variables
    int rem;

    // loop until y==0
    while (y != 0){
        // find remainder then swap values following the Euclidean Method
        rem = x%y;
        x = y;
        y = rem;
    }
    return x; // return GCD value to caller
} // function possible_answer() ends execution


// function result()
// takes in three inputs and outputs the possible fractions
void result(int x, int y, int possible_answer){
    // declare variables
    int i, j, counter=0;

    // loop to find number of common factors (counter)//
    for (i=2; i<=x; i++){
        if (x%i==0 && y%i==0)
            counter++;
    }
    // output number of factors
    printf("\nThere will be %d answers for this fraction.\n\n", counter);

    // output possible terms
    for (j=2; j<x; j++){
        if (x%j==0 && y%j==0)
            // output terms by dividing numerator and denominator by every common factor
            printf("One of the terms: %d/%d\n", (x/j), (y/j));
    }

    // output lowest term by dividing numerator and denominator by GCD
    printf("Lowest term: %d/%d\n", (x/possible_answer), (y/possible_answer));
} // function result() ends execution
