template<typedef T>
using namespace std

class ListArray : public List {

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
			if (pos<0 || pos>self.size()){
				throw out_of_range("Posición fuera de rango");
			}
			if(n<max){
                           for(int i=n+1; i>pos; i++){
                                arr[i] = arr[i-1];
                           }
			if(n==max){
				//self.resize();
			}
                           arr[pos]=e;
                           n++;
		}

                void append(T e) override{
			if(n<max){
				arr[n]=e;
				n++;
			}
			if(n==max){
                                //self.resize();
                        }
		}

                void prepend(T e) override{
			if(n<max){
                           if(n==0){
			   	arr[0]=e;
			   }
			   else{
			   	self.insert(0, e);
			   }
			}
                       	if(n==max){
                                //self.resize();
                        }

		}
                T remove(int pos) override{
			if (pos<0 || pos>=self.size()){
                                throw out_of_range("Posición fuera de rango");
                        }
			T eliminado;
			eliminado = arreglo[pos];
                        arreglo[pos]=NULL;

			if(/*Hay demasiado espacio*/){
                                //self.resize();
                        }

			return eliminado;
                }

		
                T get(int pos) override{
			
		}
                int search(T e) override{}
                bool empty() override{}
                int size() override{
			return n;
		}
		

		~ListArray() override {
			delete[] arr;
			cout << "ListArray destruido" << endl;
		} 

	private:
		void resize(int new_size){}//Una vez hecho, corregir insert(), append(), prepend() y remove().
};

