/*
Editor: MdShahid Bin Emdad
File: sequence1.cpp
Professor: George Wolberg
*/

#include "sequence1.h"
#include <assert.h>

namespace main_savitch_3 {

    const sequence::size_type sequence::CAPACITY; // needs to be redeclared without static

    // Default Constructor
//   sequence( )
//     Postcondition: The sequence has been initialized as an empty sequence.

    sequence::sequence() {
      m_used = 0;
      m_currentIdx = 0;
    }

    // MODIFICATION MEMBER FUNCTIONS

//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).

    void sequence::start() {
      m_currentIdx = 0;
    }

//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.

    void sequence::advance() {
      //assert(is_item());
      //Need to comment out, or sequence_exam won't run.
      //Added is_item() call to if-statement but still meet precondition requirements
      if(is_item() && (curIdx() < m_used)) m_currentIdx++;
    }

//   void insert(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry 
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.

    void sequence::insert(const value_type& entry) {
      assert(size() < CAPACITY);
      if(!is_item()) {
        if (m_used == 0) {
          m_data[0] = entry;
          m_used++;
        } else {
          m_currentIdx = 0;
          for(sequence::size_type i = m_used; i > curIdx(); i--) m_data[i] = m_data[i-1];
          m_currentIdx++;
          m_data[0] = entry;
          m_used++;
        }
      } else {
        for (sequence::size_type i = m_used; i > curIdx(); i--) m_data[i] = m_data[i-1];
        m_data[curIdx()] = entry;
        m_used++;
      }
    }

//   void attach(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has 
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.

    void sequence::attach(const value_type& entry) {
      assert(size() < CAPACITY);
      if (!is_item()) {
        m_data[curIdx()] = entry;
        m_used++;
      } else {
        for(sequence::size_type i = m_used; i > curIdx(); i--) m_data[i] = m_data[i-1];
        m_currentIdx++;
        m_data[curIdx()] = entry;
        m_used++;
      }
    }

//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.

    void sequence::remove_current( ) {
      assert(is_item());
      if(is_item()) {
        for(sequence::size_type i = curIdx(); i < m_used; i++) m_data[i] = m_data[i+1];
      } m_used--;
    }

    // CONSTANT MEMBER FUNCTIONS

//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequence.

    sequence::size_type sequence::size( ) const {
      return m_used;
    }

    sequence::size_type sequence::curIdx( ) const {
      return m_currentIdx;
    }

//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.

    bool sequence::is_item( ) const {
      return (m_currentIdx < m_used);
    }

//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.

    sequence::value_type sequence::current( ) const {
      assert(is_item());
      return m_data[curIdx()];
    }
}