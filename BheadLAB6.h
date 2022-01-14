#include <Windows.h>
#include <stdlib.h> 	
#include <math.h>   				
#include <conio.h>  	
#include <iomanip> 
#include <iostream>	 
#include <new>


using namespace std;


template<typename T>
class Container 	
{
	public: 				
		//виртуальные функции
		virtual void insert(const T &) = 0;									//вставка
		virtual void extract() = 0;											//излечение
		virtual int print() = 0;											//печать
};


template<typename T>
class Queue	: public Container <T>
{
	private:
		T * pointer;														//указатель на очередь
		int qe_count;														//количество элементов
	public:
		//конструкторы
		Queue(); 															//конструктор по умолчанию
		Queue(const Queue <T> &);											//конструктор копирования
		~Queue();															//деструктор
	
		//методы
		Queue <T> & operator = (const Queue <T> &);							//оператор присваивания
		const T & operator [] (int) const;									//[] const чтение
		T & operator [] (int); 												//[] не-const чтение/запись
		bool empty() const;													//пуста ли очередь
		int Qcount() const;  												//кол-во элементов
		
		void insert(const T &);												//вставка
		void extract();														//излечение	
		int print();														//печать
};


template<typename T>
class Stack	: public Container <T>
{
	private:
		T * pointer;														//указатель на стек
		int sk_count;														//количество элементов
	public:
		//конструкторы
		Stack(); 															//конструктор по умолчанию
		Stack(const Stack <T> &);											//конструктор копирования
		~Stack();															//деструктор
	
		//методы
		Stack <T> & operator = (const Stack <T> &);							//оператор присваивания
		const T & operator [] (int) const;									//[] const чтение
		T & operator [] (int); 												//[] не-const чтение/запись
		bool Skempty() const;												//пуст ли стек
		int Skcount() const;  												//кол-во элементов
		
		void insert(const T &);												//вставка
		void extract();														//излечение	
		int print();														//печать	
};
