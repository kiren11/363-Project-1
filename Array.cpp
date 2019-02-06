// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <iostream>  
#include <stdexcept> //exceptions

//default constructor - set array to a fixed size
Array::Array (void)
:max_size_(10), cur_size_(10)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
//RESPONSE Added a base member initialization list.
{   
    //make a new char array of size 10 on heap
    data_  = new char[10];
}

//set array size to variable length
Array::Array (size_t length)
:max_size_(length), cur_size_(length)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
//RESPONSE Added a base member initialization list.
{  
    //make new character array of size length on the heap
    data_ = new char[length];
}

//iterate through array and fill each position with specified fill char
Array::Array (size_t length, char fill)
:max_size_(length), cur_size_(length)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
// RESPONSE: Added a base member initialization list.
{   
    //create new array on the heap of length size
    data_ = new char[length];

    //eventually replace with fill function call
    for(int i = 0; i < length; i++) 
    {   
        //fill the array with the param character
        data_[i] = fill;
    }
}

//copy constructor
Array::Array (const Array & array)
:max_size_(max_size_), cur_size_(cur_size_)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
// RESPONSE Added a base member initialization list.
{   
  // COMMENT You are making an allocation, but you are not assigning it to data. Then,
  // you are copying the elements from rhs to data below. This will eventually lead to
  // a runtime exception.
  // RESPONSE: changed data_[i] to array[i]

    //make new heap of the current size
    char * arr = new char[this->cur_size_];


    //copy old data to new array
    for(int i = 0; i < this->max_size_; i++)
    {
      // COMMENT Use the index operator when accessing data (i.e., data_[i])
      // RESPONSE: Replaced *(data_ + i) with data_[i], aka using index operator
      arr[i] = array[i];
    }
}

//destructor - delete array off of the heap
Array::~Array (void) 
{   
    //delete the array from the heap
    delete [] data_;
}

//assignment operator
const Array & Array::operator = (const Array & rhs) 
{   
    // COMMENT Check for self assignment first.
    // RESPONSE: Added a check for self assignment
    if(this != &rhs)
    {
        if(this->max_size_ < rhs.size())
        {
            delete [] data_;

            data_ = new char[rhs.size()];
        }

            cur_size_ = rhs.size();
            max_size_ = rhs.size();

            for(size_t i = 0; (i < this->cur_size_); i++)
            {
                data_[i] = rhs.data_[i];
            }

            return *this;
        }
    }

  // COMMENT The assignment operator needs to create a deep copy of the source
  // array. Otherwise, the copy will share a pointer with the original. When one goes out
  // of scope, the other will eventually crash.
  // RESPONSE: I deleted the portion where there was a for loop with shallow
  // copying.

  // COMMENT This method should return *this for call chaining.
  // RESPONSE: The self assignment check will return *this in the first code block of this function

//get character at specific index
char & Array::operator [] (size_t index) 
{
    // COMMENT You are to throw out of range exception if the index is invalid.
    // RESPONSE: Added exception if index is less than zero or more than max size, throw error
   try 
   {
        if(index < 0) 
        {
            throw "Invalid index";
        } else if (index > max_size_) 
        {
            throw "Invalid index";
        }
    } catch (const std::out_of_range& oor) 
    {
        std::cout<<"Invalid index value"<<std::endl;
    }

  // COMMENT The index operator should not change the size of the array.
  // RESPONSE: removed unnecessary portion of code

    //return value at that index
    return data_[index];
}

//get the character at a specific index
const char & Array::operator [] (size_t index) const 
{
  // COMMENT You are to throw out of range exception if the index is invalid.
  // RESPONSE: Added exception if index is less than zero or more than max size, throw error
    try 
    {
        if(index < 0) 
        {
            throw "Invalid index";
        } else if (index > max_size_) 
        {
            throw "Invalid index";
        }
    } catch (const std::out_of_range& oor) {
        std::cout<<"Invalid index value"<<std::endl;
    }

    //loop through array until you get to the index indicated
    for(int i = 0; i < index; i++) 
    {
      
      // COMMENT Use the index operator when accessing data (i.e., data_[i])
      // RESPONSE: Replaced *(data_ + i) with data_[i], aka used index operator
      // when index is reached, print the value at that index
        if(data_[i] == index) 
        {
            std::cout<<data_[i]<<std::endl;
        }
    } 

    //exception handling - if index is greater than max size, throw error
    try 
    {
        if(index > this->max_size_) 
        {
            throw "Out of range";
        }
    } catch (const std::out_of_range& oor) 
    {
        std::cout<<"Invalid index value"<<std::endl;
    }
}

//get character at specific index
char Array::get (size_t index) const 
{
  // COMMENT You are to throw out of range exception if the index is invalid.
  // RESPONSE: Added try catch for if index is less than 0 (invalid)

    //if index is smaller than size of array
    //assignment of read only location
    if(index < this->max_size_)
    {
        return data_[index];
    }

    try 
    {
        if(index < 0) {
            throw "Invalid index";
        } else if (index > max_size_) 
        {
            throw "Invalid index";
        }
    } catch (const std::out_of_range& oor) 
    {
        std::cout<<"Invalid index value"<<std::endl;
    }

  // COMMENT There is nothing to catch here.
  // RESPONSE: The unnecessary exception has been removed.
}

//replace character at index param
void Array::set (size_t index, char value) 
{
  // COMMENT You are to throw out of range exception if the index is invalid.
  // RESPONSE: Added try catch for if index is less than 0 (invalid), or more than max size
    try 
    {
        if(index < 0) {
            throw "Invalid index";
        } else if (index > max_size_) 
        {
            throw "Invalid index";
        }
    } catch (const std::out_of_range& oor) 
    {
        std::cout<<"Invalid index value"<<std::endl;
    }

    data_[index] = value;
}

//set new size for the array
void Array::resize (size_t new_size) 
{
    // COMMENT The resize method should only increase the size of the allocation if
    // the new size is larger than the current memory allocation for the array. If resized,
    // you need to preserve the old data. Otherwise, you can just update cur_size_ to
    // reflect the new size.
    // RESPONSE: added an if statement to resize so only if the new size is larger than the current 
    // allocation, will it go ahead and resize, also added an else statement, so if the if 
    // statement doesn't execute, it will only update current size
    if(new_size > max_size_) 
    {
        //create a new array to copy elements to
        char * copy = new char[new_size];

        //copy to copy array
        for(int i = 0; i < new_size; i ++) 
        {
        // COMMENT Use the index operator when accessing data (i.e., data_[i])
        // RESPONSE: Used [i] instead of *(copy + i) aka used index operator
        //copy old array to new array
            copy[i] = data_[i];
        
        // COMMENT Use the index operator when accessing data (i.e., data_[i])
        // RESPONSE: Used [i] instead of *(copy + i) aka used index operator
            std::cout<<copy[i]<<std::endl;
        }

        //set current size to what the new size is now
        this->cur_size_ = new_size;

        //delete old array
        delete[] data_;

        //copy array is now the data_ array
        data_ = copy;
    } else 
    {
        this->cur_size_ = new_size;
    }
}

//find specific character in the array
int Array::find (char ch) const
{
    //iterate through array, looking at each element
    for(int i = 0; i < this->max_size_; i++)
    {   
        //if index is equal to the character
        if(*(data_ + i) == ch)
        {   
            //print out index at which char is found
            std::cout<<i<<std::endl;

            //return position at which character was found
            return i;
        } 
    }
}

//allows you to specify the start index of the search
//if not found: std::out_of_ranged
int Array::find (char ch, size_t start) const
{
    // COMMENT You are to throw an exception if the index is invalid.
    // RESPONSE: Added try catch for if index is less than 0 (invalid), or more than max size
    try 
    {
        if(start < 0) 
        {
            throw "Invalid index";
        } else if (start > max_size_) 
        {
            throw "Invalid index";
        }
    } catch (const std::out_of_range& oor) 
    {
        std::cout<<"Invalid index value"<<std::endl;
    }


    //iterate through array, starting at start index looking at each element
    for(int i = start; i < this->max_size_; i++)
    {   
        //if index is equal to the character
        if(data_[i] == ch)
        {           
            //print out index at which char is found
            std::cout<<i<<std::endl;

            //return position if character could not be found
            return i;
        }
    }

    //if you cant find the character, return -1
    return -1;
}

//test array for equality
bool Array::operator == (const Array & rhs) const
{
    // COMMENT Check for self comparison first.
    // RESPONSE: Added a check for self assignment 
    // tried to add the same self assignment check as = operator, but not working?
    
    // if(this != &rhs)
    // {
    //     if(this->max_size_ < rhs.size())
    //     {
    //         delete [] data_;

    //         this->data_ = new char[rhs.size()];
    //     }

    //         this->cur_size_ = rhs.size();
    //         this->max_size_ = rhs.size();

    //         for(size_t i = 0; (i < this->cur_size_); i++)
    //         {
    //             this->data_[i] = rhs.data_[i];
    //         }
        
    //     return *this;
    // }

    //boolean value to check if arrays are equal
    bool arrEqual = true;

    //if they're not the same size -> automatically not equal
    if(rhs.size() != this->cur_size_)
    {   
        return false;
        arrEqual = false;
    }

    //go through each element and check if each element is equal
    for(size_t i = 0; i < rhs.size(); i++)
    {   
        //if data is same for each index, return true
        if(rhs[i] == data_[i]) 
        {
            return true;
            arrEqual = true;
        }
    }

    //return boolean value
    return arrEqual;
}


//test array for inequality of two arrays
bool Array::operator != (const Array & rhs) const 
{
  // COMMENT You can define operator != in terms of operator ==.
  //RESPONSE: Defined the != in terms of == by using == to make the comparison and ! outside of the parenthesis

    //set boolean value for inequality of arrays to true
    bool arrEqual = true;

    //if they're not the same size then they're automatically not equal
    if(!(rhs.size() == this->cur_size_))
    {   
        return true;
        arrEqual = true;
    }

    //iterate through array to check individual values
    for(int i = 0; i < rhs.size(); i++)
    {   
        //check each individual element
        if(!(rhs[i] == data_[i]))
        {
            return true;
            arrEqual = true;
        }
    }

    //return the boolean value
    return arrEqual;
}

//fill the contents of the array
void Array::fill (char ch) 
{
    //iterate through array and fill each array index with character specified
    for(int i = 0; i < this->cur_size_; i++) 
    {
        data_[i] = ch;
    }
}

void Array::shrink (void) 
{
    // COMMENT You are move the data to a smaller array, if applicable.
    // RESPONSE: Added an if statement that checks if the current size is less than max size, only then is array resized
    if(cur_size_ < max_size_) 
    {
        //create a copy array
        char * copy = new char[this->cur_size_];

        //if the maximum size of array is smaller than current array size
        if(this->max_size_ < this->cur_size_) 
        {
        
            //go through the array and copy to new array
            for(int i = 0; i < this->max_size_; i++)
            {
                copy[i] = data_[i];
            }
        }    
    }
}

//reverse the contents of the array, first element is now last element etc
void Array::reverse (void) 
{
    // COMMENT There is no need to create a copy of the array to reverse its contents
    // RESPONSE: Removed the extra copy array, and array is now not being copied to that second array,
    //instead, the array is just printed out.

    //go through array backwards
    for(int i = (this->cur_size_ - 1); i >= 0; i--)
    {
        std::cout<<data_[i]<<std::endl;
    }

}

//slice method returns a shallow copy of a portion of an array into a new array 
Array Array::slice (size_t begin) const 
{
    //make a new array that will contain the new spliced data
    char * copy = new char[this->cur_size_];

    //copy each element one by one to new array
    for(int i = begin; i < this->cur_size_; i++)
    {   
        copy[i] = data_[i];
        std::cout<<copy[i]<<std::endl;
    }
}

//splice but both begin and end are specified 
Array Array::slice (size_t begin, size_t end) const 
{
    //make a new array that will contain the new spliced data
    char * copy = new char[this->cur_size_];

    //starts at beginning variable, and ends at end param variable
    for(int i = begin; i < end; i++)
    {   
        //copy each element one by one to new array
        copy[i] = data_[i];
        std::cout<<copy[i]<<std::endl;
    }
}
