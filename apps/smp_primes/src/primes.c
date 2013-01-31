// ------------------------------------------------------------
// Prime Number Generator Code
//
// Copyright (c) 2011-2012 ARM Ltd.  All rights reserved.
// ------------------------------------------------------------

#include "sdk.h"
//#include <stdio.h>
//#include <time.h>
//#include "MP_Mutexes.h"

#define TARGET_COUNT (100) //Number of primes to find

// ------------------------------------------------------------
unsigned int target_count; // Number of primes to find, will equal TARGET_COUNT. Safe to reduce at debug time.
unsigned int prime_numbers[TARGET_COUNT];
unsigned int next_number;

volatile unsigned int prime_count;

// Align the mutexes to the cache line size
//mutex_t prime_lock    __attribute__ ((aligned (32)));
//mutex_t next_num_lock __attribute__ ((aligned (32)));

// ------------------------------------------------------------

static unsigned int getNextNumber()
{
  unsigned int number;

//  lockMutex(&next_num_lock);
  number = next_number;
  next_number = next_number + 2;
//  unlockMutex(&next_num_lock);

  return number;
}

// ------------------------------------------------------------

static void addPrime(unsigned int number, unsigned int id)
{
//  lockMutex(&prime_lock);

  // It is possible a CPU could skid past the target number of primes
  // so adding a check to avoid potential writes past the end of the array
  if (prime_count < target_count)
  {
    prime_numbers[prime_count] = number;
    prime_count++;
    printf("CPU %d: %d (prime %d of %d)\n", id, number, prime_count, target_count);
  }

//  unlockMutex(&prime_lock);

  return;
}

// ------------------------------------------------------------

void initPrimes(void)
{
  // Initialize mutexes
//  initMutex(&prime_lock);
//  initMutex(&next_num_lock);

  // Set initial
  target_count = TARGET_COUNT;
  prime_count = 0;

  // Give it the first few primes to get going...
  prime_numbers[prime_count] = 2;
  prime_count++;
  prime_numbers[prime_count] = 3;
  prime_count++;
  prime_numbers[prime_count] = 5;
  prime_count++;
  prime_numbers[prime_count] = 7;
  prime_count++;
  prime_numbers[prime_count] = 11;
  prime_count++;
  prime_numbers[prime_count] = 13;
  prime_count++;
  prime_numbers[prime_count] = 17;
  prime_count++;
  prime_numbers[prime_count] = 19;
  prime_count++;
  prime_numbers[prime_count] = 23;
  prime_count++;
  prime_numbers[prime_count] = 29;
  prime_count++;
  prime_numbers[prime_count] = 31;
  prime_count++;
  prime_numbers[prime_count] = 37;
  prime_count++;

  next_number = 39;

  return;
}

// ------------------------------------------------------------

void calculatePrimes(unsigned int id)
{
  int number;
  int square;
  int remainder;
  int root = 1;
  int prime;
  int i;

  while(prime_count < target_count)
  {
    // Get the next number
    number = getNextNumber();

    square = root * root;

    while(number > square)
    {
      root++;
      square = root * root;
    }

    for(i=1; i < prime_count; i++)
    {
      prime = prime_numbers[i];

      if (prime > root)
      {
        addPrime(number, id);
        break;
      }

      remainder = number % prime;

      if (remainder == 0)
      {
        // not a prime, so discard number
        break;
      }
    }

    // Not holding any locks
    // Delay to give other cores a chance, because semihosting is quite slow

    //for( i=0; i <= 100000; i++) { __nop(); }

  }
  return;
}

// ------------------------------------------------------------
// End of primes.c
// ------------------------------------------------------------
