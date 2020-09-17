/*
Editor: MdShahid Bin Emdad
File: stats.cpp
Professor: George Wolberg
*/

#include "stats.h"
#include <iostream>
#include <assert.h>

using namespace std;

namespace main_savitch_2C{

    //default constructor

//   statistician( );
//     Postcondition: The object has been initialized, and is ready to accept
//     a sequence of numbers. Various statistics will be calculated about the
//     sequence.

    statistician::statistician( ) {
        count = 0;
        total = 0;
    }

    //modified constructor

//   void next(double r)
//     The number r has been given to the statistician as the next number in
//     its sequence of numbers.

    void statistician::next(double r) {
        count += 1;
        total += r;
        if(length( ) == 1){
            tinyest = r;
            largest = r;
        }
        else if (r < minimum( )){
            tinyest = r;
        }
        else if (r > maximum( )){
            largest = r;
        }
    }

    // reset function

//   void reset( );
//     Postcondition: The statistician has been cleared, as if no numbers had
//     yet been given to it.

    void statistician::reset( ) {
        count = 0;
        total = 0;
        tinyest = 0;
        largest = 0;
    }

    //constant member functions

//   int length( ) const
//     Postcondition: The return value is the length of the sequence that has
//     been given to the statistician (i.e., the number of times that the
//     next(r) function has been activated).

    int statistician::length( ) const{
        return count;
    }

//   double sum( ) const
//     Postcondition: The return value is the sum of all the numbers in the
//     statistician's sequence.

    double statistician::sum( ) const{
        return total;
    }

//   double mean( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the arithmetic mean (i.e., the
//     average of all the numbers in the statistician's sequence).

    double statistician::mean( ) const{
        assert(length() > 0);
        return total / count;
    }

//   double minimum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the tinyest number in the
//     statistician's sequence.

    double statistician::minimum( ) const{
        assert(length() > 0);
        return tinyest;
    }

//   double maximum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the largest number in the
//     statistician's sequence.

    double statistician::maximum( ) const{
        assert(length() > 0);
        return largest;
    }

    // NON-MEMBER functions for the statistician class:

//   statistician operator +(const statistician& s1, const statistician& s2)
//     Postcondition: The statistician that is returned contains all the
//     numbers of the sequences of s1 and s2.

    statistician operator +(const statistician& s1, const statistician& s2){
        statistician s3;
        if (s1.length() == 0 && s2.length() == 0) return s3;
        else if (s1.length() == 0) return s2;
        else if (s2.length() == 0) return s1;

        else {
            s3.count = s1.length() + s2.length();
            s3.total = s1.sum() + s2.sum();
            if(s1.minimum() < s2.minimum()) {
                s3.tinyest = s1.minimum();
            }
            else { 
                s3.tinyest = s2.minimum();
            }
            if(s1.maximum() > s2.maximum()){
                s3.largest = s1.maximum();
            }
            else s3.largest = s2.maximum();
        }
        return s3;
    }

//   statistician operator *(double scale, const statistician& s)
//     Postcondition: The statistician that is returned contains the same
//     numbers that s does, but each number has been multiplied by the
//     scale number.

    statistician operator* (double scale, const statistician& s) {
        statistician x;
        x.count = s.count;
        x.total = scale * s.total;
        if(s.length() == 0){
            x = s;
        }
        if(scale >= 0){
            x.tinyest = scale * s.tinyest;
            x.largest = scale * s.largest;
        }
        else {
            x.tinyest = scale * s.largest;
            x.largest = scale * s.tinyest;
        }
        return x;
        
    }

//   bool operator ==(const statistician& s1, const statistician& s2)
//     Postcondition: The return value is true if s1 and s2 have the zero
//     length. Also, if the length is greater than zero, then s1 and s2 must
//     have the same length, the same  mean, the same minimum, 
//     the same maximum, and the same sum.
    
    bool operator ==(const statistician& s1, const statistician& s2) {
        if (s1.length() == 0 && s2.length() == 0){
            return true;
        }
        else if (s1.length() == s2.length() && s1.sum() == s2.sum() && s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum()){
            return true;
        }
        else return false;
    }
};

// end of the code
