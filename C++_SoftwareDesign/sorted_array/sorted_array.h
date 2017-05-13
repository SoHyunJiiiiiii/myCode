#ifndef _SORTED_ARRAY_H_
#define _SORTED_ARRAY_H_
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

template <typename T>
class SortedArray
{
	public:
		SortedArray(){
			values_=NULL;
			size_=0;
			alloc_=0;
		}

		SortedArray(const SortedArray& a){
			size_=a.size_;
            values_ = new T[size_];
            for(int i=0; i<size_; i++){
                values_[i] = a.values_[i];
            }
			alloc_=a.alloc_;
		}

		SortedArray(int size){
            size_=size;
           // cout << "size" << size_ << endl;
			values_= new T[size_];
			alloc_=0;
		}

		SortedArray& operator=(const SortedArray& a){
            if(this == &a)
                return *this;
   
            delete []values_;
            
            size_ = a.size_;
            alloc_ = a.alloc_;
            values_ = new T[size_];
            for(int i=0; i< size_; i++){
                values_[i] = a.values[i];
            }
            return *this;
		}

    
        void Print() const{
            for(int i=0; i<size_; i++){
                cout << values_[i] << " ";
            }
            cout << endl;
        }
		int size() const{
			return size_;
		}

		T& operator[](int idx){
			return values_[idx];
		}
        void Sort(){
            bool exchanges;
            do {
                exchanges = false;  // assume no exchanges
                for (int i=0; i<size_-1; i++) {
                    if (values_[i] > values_[i+1]) {
                        T temp = values_[i];
                        values_[i] = values_[i+1];
                        values_[i+1] = temp;
                        exchanges = true;  // after exchange, must look again
                    }
                }
            } while (exchanges);
        }
		void Reserve(int size){
            values_ = new T[size];
		}

		void Add(const T& value){
            //cout << value << "input " << endl;
            values_[alloc_++] = value;
        }

		int Find(const T& value){
            for(int i=0; i<size_; i++){
                if(values_[i] == value){
                    return i;
                }
            }
            return -1;
		}
      
	private:
		T* values_;
		int size_, alloc_;
};


#endif
