//Arquivo Main.cpp
#include "Neuronio.h"
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <windows.h>


#define QTD_NEURONIOS 1000
#define QTD_EPOCAS 200000

//Atualiza os novos pesos de acordo com a formula
void calculaNovosPesos(Neuronio neu[]);
//Calcula quantos acertos o neuronio conseguiu usando o treinamento assistido e imprime a qtd de erros e acertos
void calculaAcertos(Neuronio neu[]);

// QTD_DE_ENTRADAS 2. Ajustar aqui a QTD de entradas
double pesos[QTD_DE_ENTRADAS] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };
double entradas[QTD_DE_ENTRADAS] = { 5.0, 9.0, 9.0, 9.0, 9.0, 9.0, 9.0 };
double entradaAlta[QTD_DE_ENTRADAS] = { 2.0, 7.0, 3.0, 2.0, 1.0, 7.0, 1.0 };
double entradaBaixa[QTD_DE_ENTRADAS] = { 2.0, 7.0, 3.0, 2.0, 1.0, 7.0, 0.0 };
Neuronio n[QTD_NEURONIOS];




int main() {
    srand(time(NULL));//Gera semente aleatória

    //Seta a precisão do double
    std::cout << fixed << setprecision(5);

    //inicializa alguns neurônios para testes
    for (int i = 0; i < QTD_NEURONIOS; i++)
        n[i] = Neuronio();

    //preenche as entradas com numeros aleatórios
    for (int i = 0; i < QTD_NEURONIOS; i++) {
        //cout << "Entrada " << i << ": "; //imprime Entradas para verificação
        for (int x = 0; x < QTD_DE_ENTRADAS; x++) {
            entradas[x] = rand() % 9 + 1;
            //cout << entradas[x]; //imprime Entradas para verificação
        }

        //cout << endl; //imprime Entradas para verificação
        n[i].setEntradas(entradas); //Injeta o array de entradas geradas no array de entradas do neuronio
    }
    n[0].setEntradas(entradaBaixa); //Injeta o array de 1 numero abaixo do RU
    n[1].setEntradas(entradaAlta); //Injeta o array de 1 numero acima do RU
  
    //treinamento dos neuronios
    for (int x = 0; x < QTD_EPOCAS; x++)
    {

        for (int i = 0; i < QTD_NEURONIOS; i++) {
            //insere pesos padrões
            n[i].setPesos(pesos);
            //n[i].setEntradas(entradas);
            n[i].calculaSaida(); //calcula saida
            n[i].classificaIdeal(); //calcula a classificação ideal
            n[i].classifica(); //Calcula a classificação usando as fórmulas matemáticas
            n[i].calculaErroLocal(); //Calcula o Erro local
            n[i].calculaDeltas(); //Calcula os Dentas para poder atualizar os pesos
            //n[i].imprime(); //Imprime todo o conjunto de neuronios
        }
        //Atualiza os pesos
        calculaNovosPesos(n);
        n[0].imprime(); //imprime apenas a amostra do conjunto de neuronios para verificar as modificação nos pesos
        n[1].imprime(); //imprime apenas a amostra do conjunto de neuronios para verificar as modificação nos pesos
        n[2].imprime(); //imprime apenas a amostra do conjunto de neuronios para verificar as modificação nos pesos
        n[3].imprime(); //imprime apenas a amostra do conjunto de neuronios para verificar as modificação nos pesos
        cout << "Epoca " << x << ": " << endl;
        calculaAcertos(n); //Calcula quantos acertos obteve

    }
    return 0;
}

//Atualiza os novos pesos de acordo com a formula
void calculaNovosPesos(Neuronio neu[]) {
    for (int n = 0; n < QTD_NEURONIOS; n++)
        for (int i = 0; i < QTD_DE_ENTRADAS; i++)
        {
            pesos[i] = pesos[i] + neu[n].deltas[i];
        }
}

//Calcula quantos acertos o neuronio conseguiu usando o treinamento assistido e imprime a qtd de erros e acertos
void calculaAcertos(Neuronio neu[]) {
    double erros = 0, acertos = 0;

    for (int n = 0; n < QTD_NEURONIOS; n++)
    {
        if (neu[n].classificacao == neu[n].classificacaoIdeal)
            acertos += 1;
        else
            erros += 1;
    }

    cout << "Erros: " << erros << endl << "Acertos: " << acertos << endl << endl;

    if (erros == 0)
        exit(1);
}