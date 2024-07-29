



#include <iostream>
#include "..\Meta"


using namespace std; 

class My_object: public Core_Object{
private:
    /* Виртуальный метод возращающий инфу об объекте для консоли*/
    virtual string __str__() const{
        string temp = "some inform from my class"; 
        return temp; 
    } 
};




int main(){
    system("chcp 65001"); 
    // Тестирование через переменную
    {
    My_object temp; 
    cout << "Test for print\n"; 

    cout << temp.Qprint() << "\n"; 
    cout << temp << "\n"; 

    cout << "Test for type\n"; 
    cout << temp.isType<My_object>() << " " << temp.isType<Core_Object>() << "\n"; 
    }

    // Тестирование через указатель
    {
    Core_Object* temp = new My_object(); 
    cout << "Test for print\n"; 

    cout << temp->Qprint() << "\n"; 
    cout << *temp << "\n"; 

    cout << "Test for type\n"; 
    cout << temp->isType<My_object>() << " " << temp->isType<Core_Object>() << "\n"; 
    }

    system("pause"); 
}