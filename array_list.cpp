#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;


class ArrayList{

  private:
  int size;
  int capacity;
  int *data = nullptr;
  public:

    //creates an emty ArrayList
    ArrayList(){
      size=0;
      data = new int[1];
      capacity=1;

    }
//Creates ArrayList with element from vector
    ArrayList(const vector<int>& v){
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
      delete data;
    }
//Adds element to end of ArrayList. Uses resize(). Complexity is normally O(1). If resize is called it becomes O(n)
    void append(const int& var){
      if (size+1 > capacity){
        resize();
      }
      *(data+size)=var;
      size ++;

    }


    //Double capacity of ArrayList, complexity is O(n)
    void resize(){
      capacity = 2*capacity;
      int *data_new = new int[capacity];
      for   (int i=0;i<size;i++) {
          *(data_new+i) = *(data+i);
        }
      delete data;
       data = data_new;
    }

    void shrink_to_fit(){
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
      data = new int[capacity];
      int *data_new = new int[capacity];
      for   (int i=0;i<size;i++) {
          *(data_new+i) = *(data+i);
        }
      delete data;
       data = data_new;
    }
    //Returns length of ArrayList
    int length(){
      return size;
    }
    //Print-function, prints out content of array. Complexity is O(n)
    void print(){
      cout <<"(";
      for   (int i=0;i<size-1;i++)  {
        cout <<*(data+i)<<", ";
      }
      cout <<*(data+size-1)<<")\n";
    }
    //[]-operator, access value at input-location. Complexity is O(1)
    int &operator [] (const int &index) {
      if (index > size-1 || index < 0){
        throw range_error("Index out of range");
      }
      return *(data+index);
    }
    //Insert function, uses resize function. Complexity is normally O(n-i). If Resize is called it is O(n)
    void insert(const int& val, const int& index) {
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
    //Remove function. Complexity is =(n-i)
    void remove(const int& index) {
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
   //pop-function, uses remove function. Complexity is O(n-i)
   int pop(const int& index){
     if (index > size-1 || index < 0){
       throw range_error("Index out of range");
     }
     int val = *(data+index);
     remove(index);
     return val;
   }

   int pop(){
     int val = *(data+size-1);
     remove(size-1);
     return val;
   }
};



int main() {




  ArrayList list({3,23,35,0,23,84,32});
  list.print();
  list.remove(0);
  list.append(32);
  list[0]=48;

  list.print();

}
