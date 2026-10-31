#pragma once
#include<iostream>
using namespace std;
template <typename T>
class MyVector {
     T* arr;
     int size; // elementin sayini
     int capacity; // arrin ramda ne qeder yer tutdugunu gosterir

public:

     MyVector() {
          this->capacity = 10;
          this->arr = new T[this->capacity]{};
          this->size = 0;
     }

     int GetSize() const {
          return size;
     }

     int GetCapacity() const {
          return capacity;
     }


     // cout overload
     friend ostream& operator<<(ostream& out, const MyVector& object) {
          for (size_t i = 0; i < object.size; i++)
          {
               out << object.arr[i] << "  ";
          }
          out << endl;
          return out;
     }


     // index overload
     T& operator[](size_t index) {
          return this->arr[index];
     }

     void push_back(T data) {

          if (this->size == this->capacity) {

               this->capacity += 10;

               T* temp_arr = new T[this->capacity]{};

               for (size_t i = 0; i < this->size; i++)
               {
                    temp_arr[i] = this->arr[i];
               }

               temp_arr[this->size] = data;

               delete[] this->arr;

               this->size += 1;
               this->arr = temp_arr;
          }
          else {
               this->arr[this->size] = data;
               this->size += 1;
          }
     }



     void push_front(T data) {

          if (this->size == this->capacity) {

               this->capacity += 10;

               T* temp_arr = new T[this->capacity]{};

               temp_arr[0] = data;

               for (size_t i = 0; i < this->size; i++)
               {
                    temp_arr[i + 1] = this->arr[i];
               }

               delete[] this->arr;

               this->arr = temp_arr;
               this->size += 1;
          }
          else {

               for (int i = this->size; i > 0; i--)
               {
                    this->arr[i] = this->arr[i - 1];
               }

               this->arr[0] = data;
               this->size += 1;
          }
     }



     void push_index(size_t index, T data) {

          if (index > this->size) {
               return;
          }

          if (this->size == this->capacity) {

               this->capacity += 10;

               T* temp_arr = new T[this->capacity]{};

               for (size_t i = 0; i < index; i++)
               {
                    temp_arr[i] = this->arr[i];
               }

               temp_arr[index] = data;

               for (size_t i = index; i < this->size; i++)
               {
                    temp_arr[i + 1] = this->arr[i];
               }

               delete[] this->arr;

               this->arr = temp_arr;
               this->size += 1;
          }
          else {

               for (int i = this->size; i > index; i--)
               {
                    this->arr[i] = this->arr[i - 1];
               }

               this->arr[index] = data;
               this->size += 1;
          }
     }



     void pop_back() {

          if (this->size != 0) {

               this->size -= 1;


               if (this->size <= this->capacity - 10) {

                    this->capacity -= 10;

                    T* temp_arr = new T[this->capacity]{};

                    for (size_t i = 0; i < this->size; i++)
                    {
                         temp_arr[i] = this->arr[i];
                    }

                    delete[] this->arr;

                    this->arr = temp_arr;
               }
          }
     }




     void pop_front() {

          if (this->size != 0) {

               for (size_t i = 0; i < this->size - 1; i++)
               {
                    this->arr[i] = this->arr[i + 1];
               }

               this->size -= 1;


               if (this->size <= this->capacity - 10) {

                    this->capacity -= 10;

                    T* temp_arr = new T[this->capacity]{};

                    for (size_t i = 0; i < this->size; i++)
                    {
                         temp_arr[i] = this->arr[i];
                    }

                    delete[] this->arr;

                    this->arr = temp_arr;
               }
          }
     }



     void pop_index(size_t index) {

          if (this->size != 0 && index < this->size) {

               for (size_t i = index; i < this->size - 1; i++)
               {
                    this->arr[i] = this->arr[i + 1];
               }

               this->size -= 1;


               if (this->size <= this->capacity - 10) {

                    this->capacity -= 10;

                    T* temp_arr = new T[this->capacity]{};

                    for (size_t i = 0; i < this->size; i++)
                    {
                         temp_arr[i] = this->arr[i];
                    }

                    delete[] this->arr;

                    this->arr = temp_arr;
               }
          }
     }



     void clear() {

          delete[] arr;

          this->capacity = 10;
          this->size = 0;
          this->arr = new T[this->capacity]{};
     }

     bool is_empty() {

          if (this->size == 0) {
               return true;
          }

          return false;
     }

     ~MyVector() {
          delete[] arr;
     }
};

