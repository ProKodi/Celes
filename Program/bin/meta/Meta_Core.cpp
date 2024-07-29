



/** 
Данная модуль реализует следующие:
Содержит следующие мета классы: 
-------------------------------
    * Core_Object - Общий интерфейс для самописных типов данных
    * Core_GUI - Общий интерфейс для самописных виджетов
    * Core_Tab - Общий интерфейс для вкладок

*/




#pragma ones 

#include <iostream>
#include <typeinfo>
#include <string.h> // Это чтобы работать со строками


#define isinstance(obj, Type) (typeid(obj) == typeid(Type))

// Заризервированное место в памяти для вывода сообщений (1 кбайт)
char* inform = new char[1024]; 

/* Общий интерфейс для самописных типов данных*/
class Core_Object{
private:
    /* Виртуальный метод возращающий инфу об объекте для консоли*/
    virtual std::string __str__() const = 0; 

public:
    /* Метод для вывода в консоль через QDebug. Не использовать с моногопоточным/асинхронным программированием*/
    const char* Qprint() const{
        strcpy(inform, this->__str__().c_str());
        return inform;
    }

    /* Вывод в консоль через cout*/
    friend std::ostream& operator<<(std::ostream& os, const Core_Object& self){
        os << self.__str__(); 
        return os;
    }

    /* Определение типа*/
    template <class type> bool isType()const {return isinstance(*this, type);}
};


/* Общий интерфейс для самописных виджетов*/
class Core_GUI: public Core_Object{
public: 
    /* виртуальный метод отображающий виджет*/
    virtual void show() = 0; 
}; 


/* Общий интерфейс для вкладок*/
class Core_Tab: public Core_GUI{
public: 
    /* виртуальный метод для открытия вкладки*/
    virtual void open_tab() = 0; 

    /* виртуальный метод для закрытия вкладки*/
    virtual void close_tab() = 0; 
}; 