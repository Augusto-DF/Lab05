#include <iostream>
using std::cout;
using std::endl;

#include <numeric>
using std::accumulate;

#include <vector>
using std::vector;

template<typename Titerator>
int mediat(Titerator first, Titerator last){
	int soma = 0;
	int val = 0;
	float media;

	//Somatório dos valores do intervalo:
	soma = accumulate(first, last, soma);

	//Quantidade de elementos no intervalo:
	for (auto i(first); i != last; i++){
		val++;
	}

	//Média:
	media = soma/val;
	std::cout << "Média: " << (int)media << std::endl;

	return (int)media;
}

template<typename InputIterator>
InputIterator closest2mean(InputIterator first, InputIterator last){
	int media = mediat(first, last);
	int menort = media;
	int maior;
	auto prox = first;

	for (auto it(first); it != last; ++it){
		if((*it) > media){
			maior = (*it) - media; 
			if(maior < menort){
				menort = maior;
				prox = it;
			}
		}
		else if(media > (*it)){
			maior = media - (*it);
			if(maior < menort){
				menort = maior;
				prox = it;
			}
		}
		else if((*it) == media){
			return it;
		}
	}
	return prox;
}	

int main(){
	vector<int> v { 1, 2, 3, 30, 40, 50 };
	auto result = closest2mean(v.begin(), v.end());
	cout << (*result) << endl;
	return 0;
}