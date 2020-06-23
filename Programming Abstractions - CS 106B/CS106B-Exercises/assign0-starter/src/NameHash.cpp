/**
 * This program creates a simple "hash" of
 * a person's name. A hash is an integer that is
 * mathematically derived from another object.
 * In this case, a string (the first and last name)
 * is accessed character by character and the hash
 * is built up from a number generated by each character.
 * While this function does not necessarily produce
 * unique hashes (different names can hash to the
 * same value), there is a relatively low possibility
 * of a "collision" with a class of roughly 400 students.
 *
 * We will learn more about hashing later this quarter!
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"  // for getLine
using namespace std;

/* Prototype for the nameHash function. This lets us use the function
 * in main and then define it later in the program.
 */
int nameHash(string first, string last);

int main() {
    string first = getLine("What is your first name? ");
    string last = getLine("What is your last name?  ");

    int hashValue = nameHash(first, last);

    cout << "The hash of your name is: " << hashValue << endl;
    return 0;
}

/* This is the actual function that computes the hash code. We're going
 * to talk more about what hash functions do later in the quarter. In
 * the meantime, think of it as a function that scrambles up the characters
 * of the input and produces a number.
 *
 * For those of you who are more mathematically inclined, this function
 * treats each character in the input name as a number between 0 and 128.
 * It then uses them as coefficients in a polynomial over the finite field
 * F_p, where p is a large prime number, and evaluates that polynomial at
 * some smaller prime number q. (You aren't expected to know this for CS106B,
 * but we thought it might be fun!)
 */
int nameHash(string first, string last){
    /* This hashing scheme needs two prime numbers, a large prime and a small
     * prime. These numbers were chosen because their product is less than
     * 2^31 - kLargePrime - 1.
     */
    static const int kLargePrime = 16908799;
    static const int kSmallPrime = 127;

    int hashVal = 0;

    /* Iterate across all the characters in the first name, then the last
     * name, updating the hash at each step.
     */
    for (char ch: first + last) {
        /* Convert the input character to lower case. The numeric values of
         * lower-case letters are always less than 127.
         */
            ch = tolower(ch);
        hashVal = (kSmallPrime * hashVal + ch) % kLargePrime;
    }
    return hashVal;
}
