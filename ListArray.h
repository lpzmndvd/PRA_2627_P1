#include <ostream>
#include <stdexcept>
#include "List.h"

using namespace std;
template<typename T>
class ListArray : public List<T> {

	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE;

	public:
		ListArray(){
			MINSIZE=2;
			arr= new T[MINSIZE];
			max=MINSIZE;
			n=0;
		}
                void insert(int pos, T e) override{
			if (pos<0 || pos>this.size()){
				throw out_of_range("Posición fuera de rango");
			}
			if(n==max){
                                this.resize();
                        }
                        for(int i=n+1; i>pos; i++){
                                arr[i] = arr[i-1];
                        }
                        arr[pos]=e;
                        n++;
		}

                void append(T e) override{
			if(n==max){
                                this.resize();
                        }
			arr[n]=e;
                        n++;
		}

                void prepend(T e) override{
                       	if(n==max){
                                this.resize();
			}	
			this.insert(0, e);
			n++;
		}
                T remove(int pos) override{
			if (pos<0 || pos>=this.size()){
                                throw out_of_range("Posición fuera de rango");
                        }
			T eliminado;
			eliminado = arr[pos];
                        for(int i=pos; i<n; i++){
				arr[i]= arr[i+1];
			}
			arr[n]=NULL;
			n--;

			if(n<max/2){
                                this.resize();
                        }

			return eliminado;
   		}

		
                T get(int pos) override{
			return arr[pos];
		}
                int search(T e) override{
			for(int i=0; i<n; i++){
				if(arr[i]==e){
					return i;
				}
			}
			return -1;
		}
                bool empty() override{
			return (n==0)? true : false;
		}
                int size() override{
			return n;
		}
		

		T operator[](int pos){
			if(pos<0 || pos>this.size()){
				throw out_of_range("Posición fuera de rango");
			}
			return arr[pos];
		}


		friend std::ostream& operator<<(std::ostream &out, ListArray<T> &list){
			for(int i=0; i<list.size(); i++){
				out << list.arr[i] << " ";
			}
		return out;
		}



		~ListArray() override {
			delete[] arr;
		} 

	private:
		void resize(int new_size){
			T* newarr;
			if(n==max){
				max=max*2;
				newarr = new T[max];
			}
			if(n<max/2){
				max=max/2;
				newarr = new T[max];
			}
		for(int i=0; i<this.size(); i++){
			newarr[i]=arr[i];
		}

		delete[] arr;
		
		arr=newarr;
		}
};

