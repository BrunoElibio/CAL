#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>

#define N 100

using namespace std;
void Naive(vector<int> v, int inicio, int fim);

int main(){

  vector<int> vetor;
  int inicio, fim;
  clock_t timer;

  for(int i =0;i<N;i++){
    vetor.push_back(rand()%N);
  }

  cin >> inicio >> fim;
  timer = clock();
  Naive(vetor, inicio, fim);
  timer = clock()-timer;
  cout << ((double) timer) / (CLOCKS_PER_SEC/1000) << endl;

  return 0;
}


void Naive(vector<int> v, int inicio, int fim){
  int soma = 0;

  for(int i = inicio;i<=fim;i++){
      soma += v[i];
  }
}
