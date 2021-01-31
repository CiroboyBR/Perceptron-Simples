#include "Neuronio.h"



Neuronio::Neuronio()
{   //inicializa BIAS
    this->bias = -1.0;

    //inicializa entradas e pesos
    for (int i = 0; i < QTD_DE_ENTRADAS; i++) {
        this->entradas[i] = 1.0;
        this->pesos[i] = 1.0;
        this->deltas[i] = 0.0;

    }
}


Neuronio::~Neuronio()
{
}

void Neuronio::imprime() {

    
        //Imprime Entradas
        cout << " E: ";
        for (int i = 0; i < QTD_DE_ENTRADAS; i++)
            cout << (int)this->entradas[i];
        //Imprime Pesos
        cout << " P:";
        for (int i = 0; i < QTD_DE_ENTRADAS; i++)
            cout << " " << this->pesos[i];


        cout << " C: " << (int)this->classificacao;
        cout << " CI: " << (int)this->classificacaoIdeal;
        cout << " S: " << this->saida;
        cout << " Erro: " << this->erroLocal;
        //Imprime Deltas
        cout << " D:";
        for (int i = 0; i < QTD_DE_ENTRADAS; i++)
            cout << " " << this->deltas[i];


        cout << endl;
    
}

//junta os números do vetor em um numero para encontrar a classificação ideal
//sem intermedio do neuronio, para fins de treinamento assistido
void Neuronio::classificaIdeal() {
    double valor = 0;

    //Pega as entradas e une elas em um double (transforma um array de double em um double)
    for(int i = 0; i < QTD_DE_ENTRADAS; i++)
        valor = valor * 10.0 + entradas[i];

    //Compara o numero com o RU para gerar a classificação correta. Serve apenas para a aprendizagem supervisionada.
    if (valor >= RU_ALUNO)
        this->classificacaoIdeal = 1;
    else
        this->classificacaoIdeal = -1;
}
//Seta as entradas recebendo um vetor como argumento
void Neuronio::setEntradas(double e[]) {
    for (int i = 0; i < QTD_DE_ENTRADAS; i++)
        this->entradas[i] = e[i];
}

//Seta os pedo recebendo um vetor como argumento
void Neuronio::setPesos(double p[]) {
    for (int i = 0; i < QTD_DE_ENTRADAS; i++)
        this->pesos[i] = p[i];
}

void Neuronio::calculaSaida() {
    this->saida = 0;

    for (int i = 0; i < QTD_DE_ENTRADAS; i++)
        this->saida = this->saida + (this->entradas[i] * this->pesos[i]);

    this->saida = this->saida + this->bias;
}

void Neuronio::classifica() {
    if (this->saida >= 0)
        this->classificacao = 1;
    else
        this->classificacao = -1;
}

void Neuronio::calculaErroLocal() {
    this->erroLocal = this->classificacaoIdeal - this->classificacao;
}



void Neuronio::calculaDeltas() {
    
    for (int i = 0; i < QTD_DE_ENTRADAS; i++) {
        this->deltas[i] = 0;
        this->deltas[i] =  this->entradas[i]  * this->erroLocal * TAXA_APRENDIZAGEM; //taxa_aprendizagem * erro_local_n * entrada_n
    }
    
}