#include "BheadLAB6.h"


//класс Queue

//конструктор по умолчанию
template<typename T>
Queue<T>::Queue()
{
	qe_count = 1;
	pointer = new T [qe_count];	
	pointer[0] = 0;
}											


//конструктор копирования
template<typename T>
Queue<T>::Queue(const Queue <T> & other)
{
	//копирование кол-ва элементов очереди
	qe_count = other.qe_count;
		
	try {
		//выделение памяти
		pointer = new T [qe_count];
		
		//заполнение значениями
		for (int i = 0; i < qe_count; i++)
			pointer[i] = other.pointer[i];
			
	} catch (bad_alloc e) {
		//если память не выделена, сообщить об ошибке
		cout << e.what() << endl;
		//обнуляем очередь
		qe_count = 0;	
	}
}


//деструктор
template<typename T>
Queue<T>::~Queue()
{ 
	delete [] pointer;
}

//оператор присваивания
template<typename T>
Queue <T> & Queue<T>::operator = (const Queue <T> & other)
{
	//присваивание самому себе
	if (this == &other)
		return *this; 	
	
	//очищаем память		
	delete[] pointer;
	
	//размер 
	qe_count = other.qe_count;
	
	try {
		//выделяем память
	   	pointer = new T [qe_count];
	    
	    //заполняем значениями
	    for (int i = 0; i < qe_count; i++)
	        pointer[i] = other.pointer[i];
		
		//возвращаем
		return *this;
		
	} catch (bad_alloc e) {
		//если память не выделена, сообщить об ошибке
		cout << e.what() << endl;
		qe_count = 0;
	}
}


//вставка
template<typename T>
void Queue<T>::insert(const T & other) 
{
	//выделяем память на 1 больше, чем было
	T * pointer2 = new T [qe_count + 1];
		
    try {
      	//копируем старые данные
      	for (int i = 0; i < qe_count; i++)
        	pointer2[i] = pointer[i];

      	//добавляем в конец новый элемент
      	pointer2[qe_count] = other;

      	//увеличиваем кол-во элементов
      	qe_count++;

      	//освобождаем память, которую выделяли
      	if (qe_count > 0)
        	delete [] pointer;
        
        //переопределяем указатель
        pointer = pointer2;
        
    } catch (bad_alloc e) {
      	//если память не выделилась, выводим сообщение об ошибке
      	cout << e.what() << endl; 
    }
}
													

//извлечение	
template<typename T>
void Queue<T>::extract() 
{
	//если очередь пуста, выводим 0
    if (empty()) {
    	cout << "\nОчередь пуста.\n";
    	return;
	}

    try {
    	//выделяем память на 1 меньше, чем было
      	T *pointer2 = new T[qe_count - 1];
      	
		//уменьшаем кол-во элементов
      	qe_count--; 

      	//заполняем значениями, кроме первого
      	for (int i = 0; i < qe_count; i++)
        	pointer2[i] = pointer[i + 1]; 

      	//удаляем старую память
      	if (qe_count > 0)
        	delete [] pointer;

      	//переопределяем указатель
      	pointer = pointer2;
      	
	} catch (bad_alloc e) {
      	//если память не выделена, выводим 0
      	cout << e.what() << endl;
    }	
}


//пуста ли очередь
template<typename T>
bool Queue<T>::empty() const
{
	return qe_count == 0;
}


//кол-во элементов
template<typename T>
int Queue<T>::Qcount() const
{
	return qe_count;
}
 										

//вывод элемента const чтение
template<typename T>
const T & Queue<T>::operator [] (int i) const
{
	return pointer[i];
}
										

//вывод элемента не-const чтение/запись
template<typename T>
T & Queue<T>::operator [] (int i)
{
	return pointer[i];
}


//печать
template<typename T>
int Queue<T>::print()
{	
	cout << "\nОчередь:\n";
	for (int i = 0; i < qe_count; i++)
        cout << pointer[i] << "  "; 	
}


//класс Stack

//конструктор по умолчанию
template<typename T>
Stack<T>::Stack()
{
	sk_count = 1;
	pointer = new T [sk_count];	
	pointer[0] = 0;
}											


//конструктор копирования
template<typename T>
Stack<T>::Stack(const Stack <T> & other)
{
	//копирование кол-ва элементов
	sk_count = other.sk_count;
	
	try {
		//выделение памяти
		pointer = new T [sk_count];
		
		//заполнение значениями
		for (int i = 0; i < sk_count; i++)
			pointer[i] = other.pointer[i];
			
	} catch (bad_alloc e) {
		//если память не выделена, сообщить об ошибке
		cout << e.what() << endl;
		//обнуляем
		sk_count = 0;	
	}
}


//деструктор
template<typename T>
Stack<T>::~Stack()
{ 
	delete [] pointer;
}


//оператор присваивания
template<typename T>
Stack <T> & Stack<T>::operator = (const Stack <T> & other)
{
	//присваивание самому себе
	if (this == &other)
		return *this; 	
	
	//очищаем память		
	delete[] pointer;
	
	//размер 
	sk_count = other.sk_count;
	
	try {
		//выделяем память
	   	pointer = new T [sk_count];
	    
	    //заполняем значениями
	    for (int i = 0; i < sk_count; i++)
	        pointer[i] = other.pointer[i];
		
		//возвращаем
		return *this;
		
	} catch (bad_alloc e) {
		//если память не выделена, сообщить об ошибке
		cout << e.what() << endl;
		sk_count = 0;
	}
}


//вставка
template<typename T>
void Stack<T>::insert(const T & other) 
{
	//выделяем память на 1 больше, чем было
	T * pointer2 = new T [sk_count + 1];
		
    try {
      	//копируем старые данные
      	for (int i = 0; i < sk_count; i++)
        	pointer2[i] = pointer[i];

      	//добавляем в конец новый элемент
      	pointer2[sk_count] = other;

      	//увеличиваем кол-во элементов
      	sk_count++;

      	//освобождаем память, которую выделяли
      	if (sk_count > 0)
        	delete [] pointer;
        
        //переопределяем указатель
        pointer = pointer2;
        
    } catch (bad_alloc e) {
      	//если память не выделилась, выводим сообщение об ошибке
      	cout << e.what() << endl; 
    }
}
													

//извлечение	
template<typename T>
void Stack<T>::extract() 
{
	//если очередь пуста, выводим 0
    if (Skempty()) {
    	cout << "\nОчередь пуста.\n";
    	return;
	}

    try {
    	//выделяем память на 1 меньше, чем было
      	T *pointer2 = new T[sk_count - 1];
      	 
      	//уменьшаем кол-во элементов
      	sk_count--;
      	
      	//заполняем значениями, кроме первого
      	for (int i = 0; i < sk_count; i++)
        	pointer2[i] = pointer[i]; 
		
      	//удаляем старую память
      	if (sk_count > 0)
        	delete [] pointer;

      	//переприсваиваем новую память
      	pointer = pointer2;
      	
	} catch (bad_alloc e) {
      	//если память не выделена, выводим 0
      	cout << e.what() << endl;
    }	
}


//пуст ли стек
template<typename T>
bool Stack<T>::Skempty() const
{
	return sk_count == 0;
}


//кол-во элементов
template<typename T>
int Stack<T>::Skcount() const
{
	return sk_count;
}
 										

//вывод элемента const чтение
template<typename T>
const T & Stack<T>::operator [] (int i) const
{
	return pointer[i];
}
										

//вывод элемента не-const чтение/запись
template<typename T>
T & Stack<T>::operator [] (int i)
{
	return pointer[i];
}


//печать
template<typename T>
int Stack<T>::print()
{	
	cout << "\nСтек:\n";
	for (int i = 0; i < sk_count; i++)
        cout << pointer[i] << "  "; 	
}					
