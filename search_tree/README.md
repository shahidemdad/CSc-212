                              Programming Assignment 5  The Bag Class with a Binary Search Tree
The Assignment:
Implement the bag template class from Section 10.5, using a binary search tree to store the items.
Purpose:
Ensure that you understand and can use binary search tree.
Before Starting:
Read all of Chapter 10, especially Sections 10.3 and 10.5.
Due Date:
Tuesday, November 19, 2020 before midnight. Late work may be submitted through Saturday with 10% penalty per day. No work will be accepted after Saturday.
How to Turn In:
Pack your files in ONE WinZip file (Windows) or ONE tar file (Unix). Attach the file in your email with "CSC212 Assignment 5" in your message Subject line, send it to the TA at ccny.cs212@gmail.com.
Files that you must write and turn in :
bag5.h: The header file for this version of the bag class. You don't have to write much of this file. Just copy our version from bag5.h and add your name and other information at the top.
bag5.template: The implementation file for the new bag class. I have written much of this to get you started. You can download my starting file from bag5.template

There are four functions in this implementation file that you must implement. These files are marked with the words STUDENT WORK
Other files that you may find helpful:
bintree.h: and bintree.template This is the binary tree node template class from Section 10.3. You can download them from bintree.h and bintree.template

NOTE:This version of the binary tree node has a small change from the original version that appears in the first printing of the second edition of the textbook ( and has a major change from the version in the first edition of the book!). In particular, the authors have changed the return values from the non-const versions of the left() and right() functions so that they return a reference to the pointer in the node. This is indicated by the & symbol here:

  binary_tree_node*& left( )
The use of a "reference" (indicated by the ampersand) in the return value has two advantages that simplify the material of Chapter 10:
It now allows a direct assignment such as: p->left() = NULL. This is not a huge advantage since the same thing can be accomplished by using the set_left function.
The expression p->left() can be passed as the argument to a function such as: tree_clear(p->left()); The parameter of tree_clear is a reference parameter, so that any changes that tree_clear makes to p->left() will now affect the actual left pointer in the node *p. In this example, the tree_clear function does set its parameter to NULL, so that the total effect of tree_clear(p->left()) is to clear the left subtree of p and to set p's left pointer to NULL.
In the case of tree_clear, this is not a huge advantage because we could have just set p's left pointer to NULL ourselves. But, in this assignment, there are two functions, bst_remove and bst_remove_max, which are easier to write if we can use p->left() and p->right() as the parameters of recursive calls. See my implementations in bag5.template for details.
bagtest.cpp: A simple interactive test program.
bagexam.cpp: A non-interactive test program that will be used to grade the correctness of your bag class.
The Bag Class Using a Binary Search Tree
Discussion of the Assignment
Start by understanding the entire pseudocode for the binary search tree operations (from Section 10.5). Then read through the portions that I have already implemented for you. Implement the rest of your work in two parts: (1) The insert and count functions, and (2) The bst_remove_all and bst_remove_max functions. Don't move to step 2 until you have completely finished and tested step 1.
Since this is a template class, debugging can be more difficult (some debuggers don't permit breakpoints in a template function. To help in debugging, you can call b.debug() in a program to print the binary search tree for the bag b (using the format shown on page 484).

If you use a makefile, you must also be careful in specifying what files are to be compiled. For example:

bagexam: bagexam.o
       
	g++ -Wall -gstabs bagexam.o -o bagexam
	

bagexam.o: bagexam.cpp bag5.h bag5.template bintree.h bintree.template
	
        g++ -c -Wall -gstabs bagexam.cpp
The bag and bintree templates are never compiled on their own, but in order to create bagexam.o, all the template files must be present in the current directory.
Most of your grade will be based on the correctness of your implementation. However, I will also look at your work and assign some points for clarity and programming style. Make sure that your name is on all your work.
