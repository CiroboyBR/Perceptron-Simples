#pragma once

#include <iostream>
#define QTD_DE_ENTRADAS 7 //Número de entradas do neuronio
#define RU_ALUNO 2732171.0 //Limiar que divide os valores classificados
#define TAXA_APRENDIZAGEM 0.00001  //Velocidade da aprendizagem dos neurônios

using namespace std;

class Neuronio
{
public:
    
    double entradas[QTD_DE_ENTRADAS]; //Entrada de dados
    double pesos[QTD_DE_ENTRADAS]; //Pesos que serão calibrados no treinamento
    double deltas[QTD_DE_ENTRADAS]; //Deltas para os calculos
    double saida;
    double classificacao; //Classificação que será dada pelo treinamento
    double classificacaoIdeal; //Classificação precisa criada para auxiliar no treinamento assistido
    double bias; //BIAS neh!
    double erroLocal;


    void imprime(); //Imprime os valores atuais do neurônio
    void classificaIdeal(); //Une as entradas e gera a classificação corretamente sem necessitar do processamento dos neuronios. Serve apenas para treinamento assistido
    void classifica(); //Função ativadora que classifica o calculo da saída intermediaria em +1 ou -1
    void calculaSaida(); //Realiza o calculo para gerar a saída intermediaria
    void setEntradas(double e[]); //Seta as entradas do Neurônio
    void setPesos(double p[]); //Seta os pesos do neurônio
    void calculaErroLocal(); //Calcula o erro local
    void calculaDeltas(); //Calcula os Deltas
    Neuronio();
    ~Neuronio();
};

