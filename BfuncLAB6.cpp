#include "BheadLAB6.h"


//����� Queue

//����������� �� ���������
template<typename T>
Queue<T>::Queue()
{
	qe_count = 1;
	pointer = new T [qe_count];	
	pointer[0] = 0;
}											


//����������� �����������
template<typename T>
Queue<T>::Queue(const Queue <T> & other)
{
	//����������� ���-�� ��������� �������
	qe_count = other.qe_count;
		
	try {
		//��������� ������
		pointer = new T [qe_count];
		
		//���������� ����������
		for (int i = 0; i < qe_count; i++)
			pointer[i] = other.pointer[i];
			
	} catch (bad_alloc e) {
		//���� ������ �� ��������, �������� �� ������
		cout << e.what() << endl;
		//�������� �������
		qe_count = 0;	
	}
}


//����������
template<typename T>
Queue<T>::~Queue()
{ 
	delete [] pointer;
}

//�������� ������������
template<typename T>
Queue <T> & Queue<T>::operator = (const Queue <T> & other)
{
	//������������ ������ ����
	if (this == &other)
		return *this; 	
	
	//������� ������		
	delete[] pointer;
	
	//������ 
	qe_count = other.qe_count;
	
	try {
		//�������� ������
	   	pointer = new T [qe_count];
	    
	    //��������� ����������
	    for (int i = 0; i < qe_count; i++)
	        pointer[i] = other.pointer[i];
		
		//����������
		return *this;
		
	} catch (bad_alloc e) {
		//���� ������ �� ��������, �������� �� ������
		cout << e.what() << endl;
		qe_count = 0;
	}
}


//�������
template<typename T>
void Queue<T>::insert(const T & other) 
{
	//�������� ������ �� 1 ������, ��� ����
	T * pointer2 = new T [qe_count + 1];
		
    try {
      	//�������� ������ ������
      	for (int i = 0; i < qe_count; i++)
        	pointer2[i] = pointer[i];

      	//��������� � ����� ����� �������
      	pointer2[qe_count] = other;

      	//����������� ���-�� ���������
      	qe_count++;

      	//����������� ������, ������� ��������
      	if (qe_count > 0)
        	delete [] pointer;
        
        //�������������� ���������
        pointer = pointer2;
        
    } catch (bad_alloc e) {
      	//���� ������ �� ����������, ������� ��������� �� ������
      	cout << e.what() << endl; 
    }
}
													

//����������	
template<typename T>
void Queue<T>::extract() 
{
	//���� ������� �����, ������� 0
    if (empty()) {
    	cout << "\n������� �����.\n";
    	return;
	}

    try {
    	//�������� ������ �� 1 ������, ��� ����
      	T *pointer2 = new T[qe_count - 1];
      	
		//��������� ���-�� ���������
      	qe_count--; 

      	//��������� ����������, ����� �������
      	for (int i = 0; i < qe_count; i++)
        	pointer2[i] = pointer[i + 1]; 

      	//������� ������ ������
      	if (qe_count > 0)
        	delete [] pointer;

      	//�������������� ���������
      	pointer = pointer2;
      	
	} catch (bad_alloc e) {
      	//���� ������ �� ��������, ������� 0
      	cout << e.what() << endl;
    }	
}


//����� �� �������
template<typename T>
bool Queue<T>::empty() const
{
	return qe_count == 0;
}


//���-�� ���������
template<typename T>
int Queue<T>::Qcount() const
{
	return qe_count;
}
 										

//����� �������� const ������
template<typename T>
const T & Queue<T>::operator [] (int i) const
{
	return pointer[i];
}
										

//����� �������� ��-const ������/������
template<typename T>
T & Queue<T>::operator [] (int i)
{
	return pointer[i];
}


//������
template<typename T>
int Queue<T>::print()
{	
	cout << "\n�������:\n";
	for (int i = 0; i < qe_count; i++)
        cout << pointer[i] << "  "; 	
}


//����� Stack

//����������� �� ���������
template<typename T>
Stack<T>::Stack()
{
	sk_count = 1;
	pointer = new T [sk_count];	
	pointer[0] = 0;
}											


//����������� �����������
template<typename T>
Stack<T>::Stack(const Stack <T> & other)
{
	//����������� ���-�� ���������
	sk_count = other.sk_count;
	
	try {
		//��������� ������
		pointer = new T [sk_count];
		
		//���������� ����������
		for (int i = 0; i < sk_count; i++)
			pointer[i] = other.pointer[i];
			
	} catch (bad_alloc e) {
		//���� ������ �� ��������, �������� �� ������
		cout << e.what() << endl;
		//��������
		sk_count = 0;	
	}
}


//����������
template<typename T>
Stack<T>::~Stack()
{ 
	delete [] pointer;
}


//�������� ������������
template<typename T>
Stack <T> & Stack<T>::operator = (const Stack <T> & other)
{
	//������������ ������ ����
	if (this == &other)
		return *this; 	
	
	//������� ������		
	delete[] pointer;
	
	//������ 
	sk_count = other.sk_count;
	
	try {
		//�������� ������
	   	pointer = new T [sk_count];
	    
	    //��������� ����������
	    for (int i = 0; i < sk_count; i++)
	        pointer[i] = other.pointer[i];
		
		//����������
		return *this;
		
	} catch (bad_alloc e) {
		//���� ������ �� ��������, �������� �� ������
		cout << e.what() << endl;
		sk_count = 0;
	}
}


//�������
template<typename T>
void Stack<T>::insert(const T & other) 
{
	//�������� ������ �� 1 ������, ��� ����
	T * pointer2 = new T [sk_count + 1];
		
    try {
      	//�������� ������ ������
      	for (int i = 0; i < sk_count; i++)
        	pointer2[i] = pointer[i];

      	//��������� � ����� ����� �������
      	pointer2[sk_count] = other;

      	//����������� ���-�� ���������
      	sk_count++;

      	//����������� ������, ������� ��������
      	if (sk_count > 0)
        	delete [] pointer;
        
        //�������������� ���������
        pointer = pointer2;
        
    } catch (bad_alloc e) {
      	//���� ������ �� ����������, ������� ��������� �� ������
      	cout << e.what() << endl; 
    }
}
													

//����������	
template<typename T>
void Stack<T>::extract() 
{
	//���� ������� �����, ������� 0
    if (Skempty()) {
    	cout << "\n������� �����.\n";
    	return;
	}

    try {
    	//�������� ������ �� 1 ������, ��� ����
      	T *pointer2 = new T[sk_count - 1];
      	 
      	//��������� ���-�� ���������
      	sk_count--;
      	
      	//��������� ����������, ����� �������
      	for (int i = 0; i < sk_count; i++)
        	pointer2[i] = pointer[i]; 
		
      	//������� ������ ������
      	if (sk_count > 0)
        	delete [] pointer;

      	//��������������� ����� ������
      	pointer = pointer2;
      	
	} catch (bad_alloc e) {
      	//���� ������ �� ��������, ������� 0
      	cout << e.what() << endl;
    }	
}


//���� �� ����
template<typename T>
bool Stack<T>::Skempty() const
{
	return sk_count == 0;
}


//���-�� ���������
template<typename T>
int Stack<T>::Skcount() const
{
	return sk_count;
}
 										

//����� �������� const ������
template<typename T>
const T & Stack<T>::operator [] (int i) const
{
	return pointer[i];
}
										

//����� �������� ��-const ������/������
template<typename T>
T & Stack<T>::operator [] (int i)
{
	return pointer[i];
}


//������
template<typename T>
int Stack<T>::print()
{	
	cout << "\n����:\n";
	for (int i = 0; i < sk_count; i++)
        cout << pointer[i] << "  "; 	
}					
