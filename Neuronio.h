#pragma once

#include <iostream>
#define QTD_DE_ENTRADAS 7 //N�mero de entradas do neuronio
#define RU_ALUNO 2732171.0 //Limiar que divide os valores classificados
#define TAXA_APRENDIZAGEM 0.00001  //Velocidade da aprendizagem dos neur�nios

using namespace std;

class Neuronio
{
public:
    
    double entradas[QTD_DE_ENTRADAS]; //Entrada de dados
    double pesos[QTD_DE_ENTRADAS]; //Pesos que ser�o calibrados no treinamento
    double deltas[QTD_DE_ENTRADAS]; //Deltas para os calculos
    double saida;
    double classificacao; //Classifica��o que ser� dada pelo treinamento
    double classificacaoIdeal; //Classifica��o precisa criada para auxiliar no treinamento assistido
    double bias; //BIAS neh!
    double erroLocal;


    void imprime(); //Imprime os valores atuais do neur�nio
    void classificaIdeal(); //Une as entradas e gera a classifica��o corretamente sem necessitar do processamento dos neuronios. Serve apenas para treinamento assistido
    void classifica(); //Fun��o ativadora que classifica o calculo da sa�da intermediaria em +1 ou -1
    void calculaSaida(); //Realiza o calculo para gerar a sa�da intermediaria
    void setEntradas(double e[]); //Seta as entradas do Neur�nio
    void setPesos(double p[]); //Seta os pesos do neur�nio
    void calculaErroLocal(); //Calcula o erro local
    void calculaDeltas(); //Calcula os Deltas
    Neuronio();
    ~Neuronio();
};

