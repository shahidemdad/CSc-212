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
    statistician::statistician( ) {
        count = 0;
        total = 0;
    }

    //modified constructor
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
    void statistician::reset( ) {
        count = 0;
        total = 0;
        tinyest = 0;
        largest = 0;
    }

    //constant member functions
    int statistician::length( ) const{
        return count;
    }
    double statistician::sum( ) const{
        return total;
    }
    double statistician::mean( ) const{
        assert(length() > 0);
        return total / count;
    }
    double statistician::minimum( ) const{
        assert(length() > 0);
        return tinyest;
    }
    double statistician::maximum( ) const{
        assert(length() > 0);
        return largest;
    }

    //friend functions
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

    // NON-MEMBER functions
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