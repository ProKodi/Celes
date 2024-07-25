



#include <iostream>
#include <typeinfo>


#define isinstance(obj, Type) (typeid(obj) == typeid(Type))


using namespace std; 


class My{
private:
    /* Возращает инфу об объекте для консоли*/
    virtual string __str__() const{
        return "My class"; 
    }

public:

    /* Вывод в консоль через cout. Только в этом классе*/
    friend ostream& operator<<(ostream& os, const My& self){
        os <<  self.__str__(); 
        return os;
    }

    /* Определение типа. Только в этом классе*/
    template <class type> 
    bool isType() const{
        return isinstance(*this, type); 
    }


};


class Super: public My{
private:
    /* Возращает инфу об объекте для консоли*/
    virtual string __str__() const{
        return "Super class"; 
    }

public:


}; 




int main(){
    My obj; 


    cout << obj << "\n"; 


    cout << obj.isType<My>() << " " << obj.isType<int>() << "\n"; 

    printf("Vectors\n"); 

    My* uk = nullptr; 

    uk = new My(); 



    cout << uk->isType<My>() << " " << uk->isType<Super>() << "\n"; 
    cout << *uk << "\n";


    delete uk; 


    uk = new Super(); 



    cout << uk->isType<My>() << " " << uk->isType<Super>() << "\n"; 
    cout << *uk << "\n";

    system("pause"); 
}