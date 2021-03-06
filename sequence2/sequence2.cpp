#include <assert.h>
#include "sequence2.h"
#include <algorithm> // for copy operator

namespace main_savitch_4
{
  const sequence::size_type sequence::DEFAULT_CAPACITY;
//     sequence::DEFAULT_CAPACITY is the initial capacity of a sequence that is
//     created by the default constructor.

// CONSTRUCTOR for the sequence class:

   sequence::sequence(size_type initial_capacity)
   {
//     Postcondition: The sequence has been initialized as an empty sequence.
//     The insert/attach functions will work efficiently (without allocating
//     new memory) until this capacity is reached.
      capacity=initial_capacity;
      data=new value_type [capacity];
      used=0;
      current_index=0;
   }
//   sequence(const sequence& source)
//     Precondition: Argument is another valid sequence object
//     Postcondition: If the sequence in the argument is the same as the sequence who's copy constructor
//     is being called upon nothing is done, otherwise, the sequence being constructed get's the same properties
//     aka is copies those of the sequence in the parameters.
    sequence::sequence(const sequence& source)
    {
      data= new value_type[source.capacity];
      capacity=source.capacity;
      used=source.used;
      current_index=source.current_index;
      for(size_t i=0;i<used;i++)
        {
          data[i]=source.data[i];
        }
	  }

	sequence::~sequence() // destructor
	{
		delete [] data;
	}

// MODIFICATION MEMBER FUNCTIONS for the sequence class:

//   void resize(size_type new_capacity)
//     Postcondition: The sequence's current capacity is changed to the 
//     new_capacity (but not less that the number of items already on the
//     sequence). The insert/attach functions will work efficiently (without
//     allocating new memory) until this new capacity is reached.

  void sequence::resize(size_type new_capacity)
  {
     value_type* new_sequence;
     if(new_capacity==capacity) 
        return;
     if(new_capacity<used)
        new_capacity=used;
     
    new_sequence= new value_type[new_capacity];
     
     for(size_t i=0;i!=used;i++)
       {
        new_sequence[i]=data[i];
       }

     delete [] data;
     data=new_sequence;
     capacity=new_capacity;
   }

   void sequence::start( )
   {
    //if(size()>0) useless
      current_index=0;
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
   }
   void sequence::advance( ){
//     Precondition: is_item returns true.
    assert(is_item());
//     Postcondition: If the current item was already the last item on the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
    current_index++;
   }

//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence before
//     the current item. If there was no current item, then the new entry has 
//     been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.

   void sequence::insert(const value_type& entry)
   {
      if(capacity<=used)
        resize(used+1);
      if(!is_item())
      {
        current_index=0;
        for(size_t i=used;i>current_index;i--)
        {
          data[i]=data[i-1];
        }
        data[0]=entry;
      }
      else{
        for(size_t i=used;i>current_index;i--)
        {
          data[i]=data[i-1];
        }
        data[current_index]=entry;
      }
      //data[current_index]=entry;
      used++;
   }

//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has 
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.

   void sequence::attach(const value_type& entry)
   {
      if(capacity<=used)
        resize(used+1);
      if(!is_item())
      {
       // current_index=used-1;
       data[current_index]=entry;
        //used++;
      }
      else
      {
        //current_index++;
        for(size_t i=used;i>current_index;i--)
        {
          data[i]=data[i-1];
        }
        //++current_index;
       data[++current_index]=entry;
      }
      
      used++;
   }

   void sequence::remove_current( )
   {
//     Precondition: is_item returns true.
       assert(is_item());

    //     Postcondition: The current item has been removed from the sequence, and the
    //     item after this (if there is one) is now the new current item.
       for(size_t i=current_index;i<used;i++)
       {
       	data[i]=data[i+1];//shift everything
       }
       used--;
    }

// CONSTANT MEMBER FUNCTIONS for the sequence class:
   sequence::value_type sequence::current( ) const
   {
//     Precondition: is_item( ) returns true.
   	assert(is_item());
//     Postcondition: The item returned is the current item on the sequence.
   	return data[current_index];
  }

// void operator=(const sequence& source);
//   Postcondition: The bag that activated this function has the same items
//   and capacity as source.

  void sequence::operator=(const sequence& source)
  {
   //value_type *new_data;
    if(this==&source)
      return;
    else
    {
      delete [] data;
      data=new value_type[source.capacity];
      //data=new_data;
      capacity=source.capacity;
      current_index=source.current_index;
      used=source.used;
        // copy(source.data,source.data + used,data);
      for(size_t i=0;i<used;i++)
      {
        data[i]=source.data[i];
      }
    }

  }

// void operator+=(const sequence& source);
//    Postcondition: sequence x += sequence y appends all the items in y to the end of what's already in x.
  
  void sequence::operator+=(const sequence& addend)
  {
    size_type add=used+addend.used;
    if(capacity<add)
      resize(addend.used+capacity);
    for(size_t i=0;i!=addend.used;i++)
    {
      data[used+i]=addend.data[i];
    }
    used+=addend.used;
  }

// value_type operator[](size_type idx);
//    Precondition: A positive integer index less than the amount of items in the sequence is entered
//    Postcondition: The value at that index is returned

  sequence::value_type sequence::operator[](size_type idx) const
  {
    assert(is_item());
    return data[current_index];
  }
// void operator+(const sequence& source);
//    Postcondition: sequence x + sequence y contains all the items of x, followed by all the items in y.

  sequence operator+(const sequence& s1, const sequence& s2) 
  {
    sequence s3=s1;
    s3+=s2;
    return s3;
  }
}

// END OF CODE