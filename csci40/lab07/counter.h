#ifndef COUNTER_H
#define COUNTER_H

/*
 * We're going to make our own Counter "class" without using C++'s class
 * support!  When a member function is called in C++, a pointer the
 * object gets implicitly passed in as a variable called "this".
 * Instead of "this", we'll use "self" (so that the compiler doesn't 
 * complain that we're using a reserved keyword).
 *
 * Each of our "methods" will have a first parameter for the "object"
 */

struct Counter {
  int count;
};

// initialize the Counter--give it a starting value
// in your implementation you need to remove the "= 0"--the default parameter
// can only exist once, and it needs to stay in the header file
void Counter_construct(Counter* self, int startingValue = 0);

// increment the Counter's count
void Counter_inc(Counter* self);

// reset the Counter's count to another value
void Counter_reset(Counter* self, int startingValue);

// retrieve the Counter's count
int Counter_getCount(const Counter* self);

#endif /* end of include guard: COUNTER_H */
