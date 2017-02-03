#include <iostream>
#include <string>
#include <vector>

using namespace std;
void imprime(int**,int,int);
void evaluar(string);
int** example;

int main() {
	int resp;
	string texto ;
	int cont2=0;
	cout << " ingrese el numero de ejercicio 1 o 2";
	cin >> resp;
	bool caracter = false;
	if (resp == 1) {
		cout << " ingrese lo que desea ver si esta balanceado o no : ";
		cin >> texto;
		
		
		for (int i=0;i<texto.size();i++){
                        if (texto[i] != '{' && texto[i] != '[' && texto[i] != '(' && texto[i] != '}' && texto[i] != ']' && texto[i] != ')'){
				caracter = false;	
			}
			else {
				caracter = true;
			}
                }
		if (caracter == true){	
			evaluar(texto);
		}
		else {
			cout << " caracter invalido" << endl;
		}

		
		
	}else if (resp ==2){
		int grado ;
		int poli;
		int numeval;
		
		vector <int **> v3D;
		cout << " ingrese el grado mas alto del polinomio: ";
		cin >> grado;
		cout << " ingrese el numero a evaluar: ";
		cin >> numeval;
		int **matrix;
		matrix = new int*[3]; 

		for (int i = 0; i < 3; ++i) {
 		 matrix[i] = new int[grado+1];
		
		}

		for (int i=0;i<grado+1;i++){
			cout << " ingrese el polinomio x^" <<i;
			cin >> poli;
			matrix [0][i] = poli;
			matrix [2][0] = matrix [0][0];	 
		}
		/*for (int i=0;i<3;i++){
			for (int j=0;j<grado+1;j++){
				if (i==0 ){
					cout << matrix[i][j] ;
					cout << " |";
				}
				else {
					cout << matrix[i][j] << " |";
				}
			}
			if (i==0){
				cout << " | " << numeval;
			}
			cout << endl;
		}*/
		
		v3D.push_back(matrix);
		for (int i=0;i<3;i++){
			for (int j=0;j<grado+1;j++){
				if(i==1 && cont2 >0){
					matrix[i][1] = numeval*matrix[2][cont2];
					cont2++;
				}
				else if (cont2 ==0){
					matrix[i][1] = numeval*matrix[2][0];
					cont2 = cont2 +1;
				}
			}
		}
			v3D.push_back(matrix);
				
		for( int i=0;i < v3D.size();i++){
			imprime(v3D.at(i), grado,numeval);
		}
	}	
	return 0;
	
}
void imprime(int** matrix, int grado,int numeval){
		for (int i=0;i<3;i++){
                        for (int j=0;j<grado+1;j++){
                                if (i==0 ){
                                        cout << matrix[i][j] ;
                                        cout << " |";
                                }
                                else {
                                        cout << matrix[i][j] << " |";
                                }
                        }
                        if (i==0){
                                cout << " | " << numeval;
                        }
                        cout << endl;
                }
}
void evaluar(string texto) {
	int corchete1 =0;
	int corchete2 =0;
	int parent1 =0;
	int parent2 =0;
	int llave1 =0;
	int llave2 =0;
	
	
	for (int i=0;i<texto.size();i++){
		if(texto[i] == ')'){
			parent2++;
		}
		else if (texto[i] == '('){
			parent1++;
		}
		else if (texto[i] == '['){
			corchete1++;
		}
		else if(texto[i] == ']'){
			corchete2++;
		}
		else if (texto[i] == '{'){
			llave1++;
		}
		else if(texto[i] == '}'){
			llave2++;
		}
	}
	if (parent1 == parent2 && corchete1 == corchete2 && llave1 == llave2){
		cout << " esta Baleanceado" << endl;
	}
	else {
		cout << "no esta Baleanceado" << endl;
	}
}
	 
