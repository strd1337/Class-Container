/*

Создать абстрактный базовый класс Container с виртуальными функциями вставки и
извлечения. Создать производные классы Stack и Queue, в которых данные функция
определены. В функции main определить массив указателей на абстрактный класс, которым
присваиваются адреса объектов производных классов. 

*/


#include "BfuncLAB6.cpp"


int main(void) {
	
	SetConsoleCP(1251);				
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	cout << "Очередь:\n";
	Queue<int> A;
	cout << "\nПечать A(int):\n";
    for(int i = 0; i < 10; i++)
        A.insert(i);
      
    for(int i = 0; i < A.Qcount(); i++)
        cout << A[i] << " ";
	
	cout << "\n\nКопирование B(A) (int):\n";
	Queue<int> B(A);
	for(int i = 0; i < B.Qcount(); i++)
        cout << B[i] << " ";
	
	Queue<char> C;
	cout << "\n\nПечать C(char):\n";
	C.insert('a');
	C.insert('f');
	C.insert('G');
	
	for(int i = 0; i < C.Qcount(); i++)
        cout << C[i] << " ";
	
	C[2] = 'F';
	cout << "\n\nПечать C(char) C[2] = 'F':\n";
	for(int i = 0; i < C.Qcount(); i++)
        cout << C[i] << " ";
	
	cout << "\n\nУдаление 4-х элементов из B (int):\n";
	cout << "\nПечать B(int):\n";
	for(int i = 0; i < B.Qcount(); i++)
        cout << B[i] << " ";
	
	for(int i = 0; i < 4; i++)
		B.extract();

	cout << "\n\nПечать B(int):\n";
	for(int i = 0; i < B.Qcount(); i++)
        cout << B[i] << " ";
 	
 	cout << "\n\nСтек:\n";
	Stack<int> G;
	cout << "\nПечать G(int):\n";
    for(int i = 0; i < 10; i++)
        G.insert(i);
      
    for(int i = 0; i < G.Skcount(); i++)
        cout << G[i] << " ";
	
	cout << "\n\nКопирование B(A) (int):\n";
	Stack<int> J(G);
	for(int i = 0; i < J.Skcount(); i++)
        cout << J[i] << " ";
	
	Stack<char> L;
	cout << "\n\nПечать L(char):\n";
	L.insert('a');
	L.insert('f');
	L.insert('G');
	L.insert('u');
	L.insert('к');
	L.insert('5');
	
	for(int i = 0; i < L.Skcount(); i++)
        cout << L[i] << " ";
	
	L[2] = 'F';
	cout << "\n\nПечать L(char):\n";
	for(int i = 0; i < L.Skcount(); i++)
        cout << L[i] << " ";
	
	cout << "\n\nУдаление 2-х элементов из L (char):\n";
	cout << "\nПечать L(int):\n";
	for(int i = 0; i < L.Skcount(); i++)
        cout << L[i] << " ";
	
	for(int i = 0; i < 2; i++)
		L.extract();

	cout << "\n\nПечать L(char):\n";
 	for(int i = 0; i < L.Skcount(); i++)
        cout << L[i] << " ";
	
	cout << "\nКонтейнер №1 Queue<int> и Stack<int>:\n";
    Container<int> *arr [3]; 
    Stack<int> AD; 
    arr[0] = new Queue<int>(A); 
    arr[1] = new Queue<int>(B); 
    arr[2] = new Stack<int>(AD); 
	
    for ( int i = 0; i < 3; i++ )
        arr[i]->insert(i + 1);
    
    arr[2]->insert(54);
    arr[2]->insert(13);
    arr[2]->insert(-4);
    
    for ( int i = 0; i < 3; i++ )
        arr[i]->print();
    
    cout << "\n\nУдаляем 3 элемента у 2 очереди:\n";
    
    arr[1]->extract();
    arr[1]->extract();
    arr[1]->extract();
    for ( int i = 0; i < 3; i++ )
        arr[i]->print();
    
    Stack<char> V;
	V.insert('A');
	V.insert('b');
	V.insert('u');
	V.insert('г');
	V.insert('о');
	
	cout << "\n\nПечать L(char):\n";
 	for(int i = 0; i < L.Skcount(); i++)
        cout << L[i] << " ";
        
	cout << "\n\nПечать V(char):\n";
 	for(int i = 0; i < V.Skcount(); i++)
        cout << V[i] << " ";
    
    cout << "\n\nКонтейнер №2 Stack<char>:\n";
    Container<char> *arr2 [2];
    arr2[0] = new Stack<char>(L); 
    arr2[1] = new Stack<char>(V); 
	
    for ( int i = 0; i < 2; i++ )
        arr2[i]->print();
	
	cout << "\n\nДобавляем 4 элемента 2 стеку:\n";  
	
	arr2[1]->insert('f');
    arr2[1]->insert('и');
    arr2[1]->insert('н');
    arr2[1]->insert('ф');
    
    for ( int i = 0; i < 2; i++ )
        arr2[i]->print();
     
	cout << "\n\nУдаляем 2 элемента у 2 стека:\n";  
   	arr2[1]->extract();
   	arr2[1]->extract();
   
   	for ( int i = 0; i < 2; i++ )
        arr2[i]->print();   
	
	return 0;
}
