                           Implement and Test the sequence Class Using a Fixed-Sized Array (Chapter 3)

The Assignment:
You will implement and test the sequence class using an array to store the sequence's items.
Purposes:
Ensure that you can write a small class that uses an array as a private member variable.
Familiarize yourself with the sequence container class (which may also be part of future assignments).
Give us a chance to evaluate your programming skills on a small class.
Before Starting:
Read all of Chapter 3.
Due Date:
Thursday, October 1, 2020 before midnight. Late work may be submitted through Saturday with 10% penalty per day. No work will be accepted after Saturday.
How to Turn In:
Please follow the instructions here.
Files that you must write:
sequence1.h: The header file for the sequence class. Actually, you don't have to write much of this file. Just start with our version and add your name and other information at the top. Also, decide on appropriate private member variables, an declare these in the sequence class definition at the bottom of the header file. If some of your member functions are implemented as inline functions, then you may put those implementations in this file too.
sequence1.cpp: The implementation file for this first sequence class. You will write all of this file, which will have the implementations of all the sequence's member functions.
Other files that you may find helpful:
sequence_test.cpp A simple interactive test program.
sequence_exam.cpp: A non-interactive test program that will be used to grade the correctness of your sequence class.
The sequence Class Using a Fixed-Sized Array
#Discussion of the Assignment
Many of the features of this class are similar to the bag class from Section 3.1, so start by thoroughly reading Section 3.1 and pay attention to new features such as static constant members and the use of a typedef. The sequence class itself is discussed in Section 3.2 of the class text. Notice how the sequence differs from a bag (see page 119). The interactive test program sequence_exam.cpp  is discussed in Section 3.3 of the class text.
Start by declaring the sequence's private member variables in sequence.h. Then write the invariant of your ADT at the top of sequence1.cpp. The invariant describes precisely how all of your private member variables are used. All of the member functions (except for the constructor) may count on the invariant being true when the member function is activated. And all of the member functions are responsible for ensuring that the invariant is true when the function returns.

As always, do your work in small pieces. For example, my first version of the sequence had only a constructor, start, insert, advance, and current. My other member functions started out as stubs.

Use the interactive test program and a debugger to track down errors in your implementation. If you have an error, do not start making changes until you have identified the cause of the error.

The ability to initialize and use a static member constant within the class definition is a relatively new feature. If you have an older compiler that does not support static const members, then you may use

enum {CAPACITY = 30};

instead of

static const size_type CAPACITY = 30;

After this definition, the name bag::CAPACITY is defined to have the integer value 30. Although this is not the intended use of an enum definition, the result is the same as using a static member constant (see more discussions on page 99 in the textbook).
