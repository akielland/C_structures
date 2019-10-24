#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;


class ArrayList{
/*Class that implements a list data structure with public methods append(),
insert(), remove(), pop() and length() and private methods resize() and
shrink_to_fit()*/
  private:
    /*Variables containing current size, capacity and a pointer to first element of the list*/
    int size;
    int capacity;
    int *data = nullptr;

    void resize(){
      /*Double capacity of ArrayList by deleting the old array and creating a
      new one with the same data, but twice the capacity, complexity is O(n)*/
      capacity = 2*capacity;
      int *data_new = new int[capacity];
      for   (int i=0;i<size;i++) {
        *(data_new+i) = *(data+i);
      }
      delete data;
      data = data_new;
    }


    void shrink_to_fit(){
      /*Determines the smallest power of two that can contain all the data in
      the array, then creates a new array with that capacity and transfers
      the contents of the old array and deletes it, complexity is O(n) */
      if (size>0){
      unsigned int x = (unsigned int)size;
      x--;
      x|x>>1;
      x|x>>2;
      x|x>>4;
      x|x>>8;
      x|x>>16;
      x++;
      capacity = x;}
      else {
        capacity = 1;
      }
      int *data_new = new int[capacity];
      for   (int i=0;i<size;i++) {
        *(data_new+i) = *(data+i);
        }
      delete data;
      data = data_new;
    }

  public:

    ArrayList(){
      /*creates an emty ArrayList with size 0 and capacity 1*/
      size=0;
      data = new int[1];
      capacity=1;
    }


    ArrayList(const vector<int>& v){
      /*creates an ArrayList filled with values from an input vector with size
      equal to the size of the vector and capacityequal to the largest power
      of two bigger than the vector size*/
      unsigned int x = v.size();
      size = (int)x;
      x--;
      x|x>>1;
      x|x>>2;
      x|x>>4;
      x|x>>8;
      x|x>>16;
      x++;
      capacity = (int)x;
      data = new int[capacity];
      for (int i=0;i<size;i++){
        *(data+i)=v[i];
      }
    }


    ~ArrayList(){
      /*Deconstructor for ArrayList, simply deletes the
      arrray pointed to by data*/
      delete data;
    }


    void append(const int& var){
      /*Adds element to end of ArrayList. If the array is not big enough it
      uses to resize to double the size of the array. Complexity is normally
      O(1). If resize() is called it becomes O(n)*/
      if (size+1 > capacity){
        resize();
      }
      *(data+size)=var;
      size ++;
    }








    int length(){
      //Returns the array length
      return size;
    }


    void print(){
      //Print-function, prints out the content of the list. Complexity is O(n)
      cout <<"(";
      for   (int i=0;i<size-1;i++)  {
        cout <<*(data+i)<<", ";
      }
      cout <<*(data+size-1)<<")\n";
    }


    int &operator [] (const int &index) {
      /*Accesss values at input index. Throws and error if index is out of
      range, complexity is O(1)*/
      if (index > size-1 || index < 0){
        throw range_error("Index out of range");
      }
      return *(data+index);
    }


    void insert(const int& val, const int& index) {
      /*Insert function inserts an int with value val at index. Moves all
      elements above up one index. Complexity is therfore normally O(n-i).
      If the array is to small resize is called, then complexity is O(n)*/
      if (index > size-1 || index < 0){
        throw range_error("Index out of range");
      }
      if (size+1 > capacity){
        resize();
      }
      for (int i=size-1;i<index;i--){
        *(data+i+1)=*(data+i);
      }
      *(data+index) = val;
      size++;
    }


    void remove(const int& index) {
      /*removes elements at index and moves alle elements above it one down,
      Complexity is therfore normally O(n-i). If the array becomes small
      shrink_to_fit is called and the complexity becomes O(n)*/
      if (index > size-1 || index < 0){
        throw range_error("Index out of range");
      }

      for (int i=index;i<size;i++){
        *(data+i)=*(data+i+1);
      }
      size--;
      if (4*size<=capacity) {
        shrink_to_fit();
      }
   }
   /*pop-function, is the same as remove function but return the value it
   removes. Complexity is O(n-i) unless is shrink_to_fit is called then it
   is complexity O(n)*/
   int pop(const int& index){
     if (index > size-1 || index < 0){
       throw range_error("Index out of range");
     }
     int val = *(data+index);
     remove(index);
     return val;
   }

   int pop(){
     /*Same as pop with index, but pops the last element, complexity therefore
     becomes O(1) since i=n. If shrink_to_fit is called complexity becomes O(n)*/
     if (size<=1){
       throw range_error("List has no elements to pop");
     }
     int val = *(data+size-1);
     remove(size-1);
     return val;
   }
};


bool is_prime(int n){
  //Returns true if n is prime, slow implementation. Complexity O(n)
  if (n==2){
    return true;
  }
  else if (n%2==0){
    return false;
  }

  for (int i=3;2*i<=n;i=i+2){
    if (n%i==0){
      return false;
  }
}
  return true;
}


//Tests ArrayList by generating primes and appending them to an ArrayList
int main() {
  int count = 0;
  int n = 2;
  ArrayList primes;
  while (count<10) {
    if (is_prime(n)==true){
      primes.append(n);
      count ++;
    }
    n++;
  }
primes.print();
return 0;
}
