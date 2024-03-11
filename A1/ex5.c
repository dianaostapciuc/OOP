#include <stdio.h>
#include <stdlib.h>

// a. Print the exponent of a prime number p from the decomposition in prime factors of a 
// given number n (n is a non-null natural number).

// b. Given a vector of numbers, find the longest contiguous subsequence such that any two
// consecutive elements are relatively prime.



int biggest_common_divisor(int a, int b)
{
    while (a!=b)
        if (a>b)
            a=a-b;
        else b=b-a;
    return a;
}

void menu()
{
    int choice;
    int number, prime_number, divisor, exponent, ok=0;
    int i, v[1000], length_vector, subsequence_end_position, common_divisor, length_subsequence=1, max_length=0, max_position=0, current_max_position;

    printf("1. Read a vector.\n");
    printf("2. Print the exponent of a prime number p from the decomposition in prime factors of a given number n (n is a non-null natural number).\n");
    printf("3. Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime.\n");
    printf("0. Exit.\n");
    while(1)
    {
        printf("What do you want to do? ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Length of vector: ");
            scanf("%d", &length_vector);
            printf("The vector: ");
            for (i=1; i<=length_vector; i++)
                scanf("%d", &v[i]);
            break;
        case 2:
            printf("The number is: ");
            scanf("%d", &number);
            printf("We take the exponent of the following prime number: ");
            scanf("%d", &prime_number);

            divisor=2;
            while (number>1)
            {
                exponent = 0;
                while (number%divisor == 0)
                {
                    exponent++;
                    number = number/divisor;
                }
                if (divisor == prime_number)
                {
                    ok=1;
                    printf("The exponent of the prime number that has been read is: %d",exponent);
                    printf("\n");
                    number = 1;
                }        
                divisor++;

            }
            if (ok == 0)
                printf("The prime number input is NOT in the decomposition :(.\n");
            break;
        case 3:
            length_subsequence=1, max_length=0, max_position=0;

            for (i=1; i<length_vector; i++)
            {
                common_divisor = biggest_common_divisor(v[i], v[i+1]);
                if (common_divisor==1)
                    length_subsequence++;
                else if (length_subsequence>max_length)
                    {            
                        max_length = length_subsequence;
                        max_position = i;
                        length_subsequence = 1;

                    }
            }

            if (length_subsequence>max_length)
            {
                max_length = length_subsequence;
                max_position = i;
            }
            current_max_position = max_position-max_length+1;
            subsequence_end_position = current_max_position+max_length;
            if (max_length > 1)
                for(i = current_max_position; i<max_length+current_max_position; i++)
                {
                    printf("%d", v[i]);
                    printf(" ");
                }
            else printf("No subsequences found :<!");
            printf("\n");
            break;
        case 0:
            exit(0);
        default:
            printf("Unknown command, try another.\n");
        }

    }
}

int main()
{
    menu();
    return 0;
}
