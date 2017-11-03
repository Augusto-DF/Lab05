#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::back_inserter;

#include <vector>
using std::vector;

#include <algorithm>
using std::transform;

//Retorna quadrado de um valor.
int square(int val) {
return val * val;
}

int main(int argc, char* argv[]) {

	//Cria 2 vetores.
	vector<int> col;
	vector<int> col2;
	
	//Preenche o primeiro vetor ( col = { 1, 2, 3, 4, 5, 6, 7, 8, 9 } ).
	for (int i = 1; i <= 9; ++i) {
		col.push_back(i);
	}
	
	//1 - Preenche o segundo vetor com os quadrados dos valores do intervalo definido (no caso o intervalo referente ao primeiro vetor ).
	//2 - back_inserter Funciona como um iterador especial, que insere elementos copiados de um determinado intervalo no final de um outro container ( Contanto que os 2 tenham o mesmo tipo ). 
	//3 - transform Aplica uma função em cada elemento de um determinado intervalo, onde o resultado ( o retorno da função ) é atribuido ao destino do iterador recebido pelo 'trasnform'( no caso o col2 ).
	transform(col.begin(), col.end(), back_inserter(col2), square);
	
	//Imprime o vetor col2.
	for (vector<int>::iterator it = col2.begin(); it != col2.end(); ++it) {
		cout << (*it) << " ";
	}
	
	//Quebra de linha.
	cout << endl;
	
	return 0;
}

// Explicação: O programa preenche 1 vetor (col) com valores de 1 a 9 e, depois, faz a cópia dos quadrados desses valores em um segundo vetor (col2).