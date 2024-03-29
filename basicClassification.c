#include "NumClass.h"
#define EPS 0.1        // Epsilon is 10^-1

// Declaring helper functions
int getFactorial(int);
int getSqrt(int);
double getAbs(double);

int isStrong(int num){
    int digit, sum = 0;
    int originNum = num;
    while(num > 0){
        digit = num%10;
        sum += getFactorial(digit);
        num /= 10;
    }
    return (sum == originNum) ? 1 : 0;
}

int isPrime(int num){
    if(num == 1 || num == 2){
        return 1;
    }
    int i=2;
    while(i<=getSqrt(num)){
        if(num%i == 0){
            return 0;
        }
        i++;
    }
    return 1;
}

int getFactorial(int num) {
    int factorial = 1;
    for(int i=1;i<=num;i++){
        factorial *= i;
    }
    return factorial;
}

/* Using Heron's method to calculate the square root of a number
sqrt(n+1)=(sqrt(n)+(num/sqrt(n)))*0.5
https://en.wikipedia.org/wiki/Methods_of_computing_square_roots
*/
int getSqrt(int num){
    double sqrt_i = 1;     // square root of 1
    while (getAbs((sqrt_i*sqrt_i) - num) > EPS){
        sqrt_i = (sqrt_i+(num/sqrt_i))*0.5;
    }
    return (int)sqrt_i;
}


/* Returns the number, in power of pow*/
int getPow(int num, int pow) {
    int result = 1;
    for(int i = 1; i <= pow; i++){
        result *= num;
    }
    return result;
}

double getAbs(double num){
    return (num < 0) ? -num : num;
}