#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first;
	int n;

    public:

        void insert(int pos, T e) override{
                        if (pos<0 || pos>this->size()){
                                throw out_of_range("Posición fuera de rango");
                        }
                        if(n==max){
                                this->resize(max*2);
                        }
                        for(int i=n; i>pos; i--){
                                //CORREGIR
                        }
                        //CORREGIR
                        n++;
                }

                void append(T e) override{
                        if(n==max){
                                this->resize(max*2);
                        }
                        //CORREGIR
                        n++;
                }

                void prepend(T e) override{
                        if(n==max){
                                this->resize(max*2);
                        }
                        this->insert(0, e);
                }
                T remove(int pos) override{
                        if (pos<0 || pos>=this->size()){
                                throw out_of_range("Posición fuera de rango");
                        }
                        T eliminado;
                        eliminado = //CORREGIR
                        for(int i=pos; i<n; i++){
                                arr[i]= arr[i+1];
                        }
                        //CORREGIR
                        n--;

                        if(n<max/2){
                                this->resize(max/2);
                        }

                        return eliminado;
                }


                T get(int pos) override{
                        if (pos<0 || pos>=this->size()){
                                throw out_of_range("Posición fuera de rango");
			}
			//ACABAR
                }
                int search(T e) override{
                }
                bool empty() override{
                        return (n==0)? true : false;
                }
                int size() override{
                        return n;
                }

};

#endif LIST_LINKED_H
