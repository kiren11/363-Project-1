#include "Array.h"

int main (int argc, char * argv [])
{
  
  //use default constructor to make a Array
  //Array();

  //make an array of fixed length
  //Array(10);

  //prints out 10 'a's
  Array * arr = new Array(8, 'a');

  arr->set(1, 'b');
  arr->set(2, 'c');
  arr->set(3, 'd');
  arr->set(4, 'e');
  arr->set(5, 'f');
  arr->set(6, 'g');
  arr->set(7, 'h');

  //reverse the array
  //arr->reverse();

  //get position at index 4
  //arr->get(4);

  // //resize array from size 8 to 5
  // arr->resize(10);

  //find the character e, return its index
  //arr->find('e');

  //should not return anything
  //since array has been resized
  //arr->find('h', 7);

  //slice array starting at index 5
  //arr->slice(5);

  //this slice has a beginning and end
  //arr->slice(1, 5);

  //delete the array object
  delete arr;

  return 0;
}
