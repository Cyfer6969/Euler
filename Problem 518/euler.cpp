#include <vector>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

int isMultiple(unsigned long long ull, vector <unsigned long long> base){
	vector<unsigned long long>::iterator it;

	if(base.size() == 0){
		return false;
	}

	for(it = base.begin(); it != base.end(); it++){

		if ( !( ull%(*it) ) )
			return true;
	}
	return false;


}

void printVector(vector<unsigned long long> v){
	vector<unsigned long long>::iterator it;

	for(it = v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}


void listPrimes(unsigned long long ull, vector <unsigned long long> &output){
	bool prime;
	vector<unsigned long long> numberList(ull, 0);

	for (unsigned long long i = 1; i <= ull; i++){
		numberList.at(i-1) = i;
	}


	for (unsigned long long j = 2; j*j <= ull; j++){
		for (unsigned long long i = 2*j; i <= ull; i = i+j){
			if (numberList.at(i-1) = 0){
				numberList.at(i-1) = 0;
			}
		}
	}

	// printVector(numberList);

	vector<unsigned long long>::iterator it;

	for(it = numberList.begin(); it != numberList.end(); it++){
		if( (*it) != 0 ){
			output.push_back(*it);
		}
	}

}

bool isGeometricSequence(unsigned long long a, unsigned long long b, unsigned long long c){
	if(b/a == c/b && c%b == 0 && b%a == 0 && c%a ==0){
		return true;
	}
	else 
		return false;
}


unsigned long long sumGeometricSequence (vector<unsigned long long> v, std::vector<unsigned long long> &output){

	vector<unsigned long long>::iterator it;
	unsigned long long sum = 0;

	for (it = v.begin()+1; it != v.end()-1; it++){
		if (isGeometricSequence(*(it-1)+1, *it+1, *(it+1)+1)){
			sum += *it + *(it-1) + *(it+1);
			output.push_back(*(it-1));
			output.push_back(*it);
			output.push_back(*(it+1));
		}
	}
	return sum;
}


int main() {

	cout << "numeros q deseja testar " ;
	int b;
	cin >> b;
	string teste;
	vector<unsigned long long> primeVector;
	vector<unsigned long long> teste1;

	// for (int i = 0; i < b; ++i){
	// 	unsigned long long a;
	// 	cout << "numero: ";
	// 	cin >> a;
	// 	if(isPrime(a)){
	// 		cout << "is Prime" << endl;
	// 	}
	// 	else
	// 		cout << "Not Prime" << endl;
	// }


//	listPrimes(b, primeVector);

//	printVector(primeVector);
//	
// //	
	clock_t begin = clock();
	listPrimes(b, primeVector);
	clock_t end = clock();

		cout << "time : " << (double) (end-begin)/ CLOCKS_PER_SEC << endl;
		cout << "sum : " << sumGeometricSequence(primeVector, teste1) << endl << endl;

// 	//printVector(primeVector);
	printVector(teste1);
// 	
	if(isGeometricSequence(3, 6, 12)){
		cout << "aeaeaeae" << endl;
	}

	cout << "  " << endl;
	cin >> teste;




}