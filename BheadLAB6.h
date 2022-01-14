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
		//����������� �������
		virtual void insert(const T &) = 0;									//�������
		virtual void extract() = 0;											//���������
		virtual int print() = 0;											//������
};


template<typename T>
class Queue	: public Container <T>
{
	private:
		T * pointer;														//��������� �� �������
		int qe_count;														//���������� ���������
	public:
		//������������
		Queue(); 															//����������� �� ���������
		Queue(const Queue <T> &);											//����������� �����������
		~Queue();															//����������
	
		//������
		Queue <T> & operator = (const Queue <T> &);							//�������� ������������
		const T & operator [] (int) const;									//[] const ������
		T & operator [] (int); 												//[] ��-const ������/������
		bool empty() const;													//����� �� �������
		int Qcount() const;  												//���-�� ���������
		
		void insert(const T &);												//�������
		void extract();														//���������	
		int print();														//������
};


template<typename T>
class Stack	: public Container <T>
{
	private:
		T * pointer;														//��������� �� ����
		int sk_count;														//���������� ���������
	public:
		//������������
		Stack(); 															//����������� �� ���������
		Stack(const Stack <T> &);											//����������� �����������
		~Stack();															//����������
	
		//������
		Stack <T> & operator = (const Stack <T> &);							//�������� ������������
		const T & operator [] (int) const;									//[] const ������
		T & operator [] (int); 												//[] ��-const ������/������
		bool Skempty() const;												//���� �� ����
		int Skcount() const;  												//���-�� ���������
		
		void insert(const T &);												//�������
		void extract();														//���������	
		int print();														//������	
};
