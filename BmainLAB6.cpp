/*

������� ����������� ������� ����� Container � ������������ ��������� ������� �
����������. ������� ����������� ������ Stack � Queue, � ������� ������ �������
����������. � ������� main ���������� ������ ���������� �� ����������� �����, �������
������������� ������ �������� ����������� �������. 

*/


#include "BfuncLAB6.cpp"


int main(void) {
	
	SetConsoleCP(1251);				
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	cout << "�������:\n";
	Queue<int> A;
	cout << "\n������ A(int):\n";
    for(int i = 0; i < 10; i++)
        A.insert(i);
      
    for(int i = 0; i < A.Qcount(); i++)
        cout << A[i] << " ";
	
	cout << "\n\n����������� B(A) (int):\n";
	Queue<int> B(A);
	for(int i = 0; i < B.Qcount(); i++)
        cout << B[i] << " ";
	
	Queue<char> C;
	cout << "\n\n������ C(char):\n";
	C.insert('a');
	C.insert('f');
	C.insert('G');
	
	for(int i = 0; i < C.Qcount(); i++)
        cout << C[i] << " ";
	
	C[2] = 'F';
	cout << "\n\n������ C(char) C[2] = 'F':\n";
	for(int i = 0; i < C.Qcount(); i++)
        cout << C[i] << " ";
	
	cout << "\n\n�������� 4-� ��������� �� B (int):\n";
	cout << "\n������ B(int):\n";
	for(int i = 0; i < B.Qcount(); i++)
        cout << B[i] << " ";
	
	for(int i = 0; i < 4; i++)
		B.extract();

	cout << "\n\n������ B(int):\n";
	for(int i = 0; i < B.Qcount(); i++)
        cout << B[i] << " ";
 	
 	cout << "\n\n����:\n";
	Stack<int> G;
	cout << "\n������ G(int):\n";
    for(int i = 0; i < 10; i++)
        G.insert(i);
      
    for(int i = 0; i < G.Skcount(); i++)
        cout << G[i] << " ";
	
	cout << "\n\n����������� B(A) (int):\n";
	Stack<int> J(G);
	for(int i = 0; i < J.Skcount(); i++)
        cout << J[i] << " ";
	
	Stack<char> L;
	cout << "\n\n������ L(char):\n";
	L.insert('a');
	L.insert('f');
	L.insert('G');
	L.insert('u');
	L.insert('�');
	L.insert('5');
	
	for(int i = 0; i < L.Skcount(); i++)
        cout << L[i] << " ";
	
	L[2] = 'F';
	cout << "\n\n������ L(char):\n";
	for(int i = 0; i < L.Skcount(); i++)
        cout << L[i] << " ";
	
	cout << "\n\n�������� 2-� ��������� �� L (char):\n";
	cout << "\n������ L(int):\n";
	for(int i = 0; i < L.Skcount(); i++)
        cout << L[i] << " ";
	
	for(int i = 0; i < 2; i++)
		L.extract();

	cout << "\n\n������ L(char):\n";
 	for(int i = 0; i < L.Skcount(); i++)
        cout << L[i] << " ";
	
	cout << "\n��������� �1 Queue<int> � Stack<int>:\n";
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
    
    cout << "\n\n������� 3 �������� � 2 �������:\n";
    
    arr[1]->extract();
    arr[1]->extract();
    arr[1]->extract();
    for ( int i = 0; i < 3; i++ )
        arr[i]->print();
    
    Stack<char> V;
	V.insert('A');
	V.insert('b');
	V.insert('u');
	V.insert('�');
	V.insert('�');
	
	cout << "\n\n������ L(char):\n";
 	for(int i = 0; i < L.Skcount(); i++)
        cout << L[i] << " ";
        
	cout << "\n\n������ V(char):\n";
 	for(int i = 0; i < V.Skcount(); i++)
        cout << V[i] << " ";
    
    cout << "\n\n��������� �2 Stack<char>:\n";
    Container<char> *arr2 [2];
    arr2[0] = new Stack<char>(L); 
    arr2[1] = new Stack<char>(V); 
	
    for ( int i = 0; i < 2; i++ )
        arr2[i]->print();
	
	cout << "\n\n��������� 4 �������� 2 �����:\n";  
	
	arr2[1]->insert('f');
    arr2[1]->insert('�');
    arr2[1]->insert('�');
    arr2[1]->insert('�');
    
    for ( int i = 0; i < 2; i++ )
        arr2[i]->print();
     
	cout << "\n\n������� 2 �������� � 2 �����:\n";  
   	arr2[1]->extract();
   	arr2[1]->extract();
   
   	for ( int i = 0; i < 2; i++ )
        arr2[i]->print();   
	
	return 0;
}
