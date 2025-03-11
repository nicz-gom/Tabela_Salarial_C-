//fiz com base no código python

#include <iostream>
#include <vector>
#include <iomanip>  // Para controlar a formatação do número (como arredondamento)
#include <string>

using namespace std;

class Funcionario {
public:
    string nome;
    int depto;
    int horas;
    double salario;
    double INSS;

    Funcionario(string nome, int depto, int horas) {
        this->nome = nome;
        this->depto = depto;
        this->horas = horas;
        this->salario = 0;
        this->INSS = 0;
    }


int main() {

    return 0;
}
