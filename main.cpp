//fiz com base no código python

#include <iostream>
#include <vector> // facilita para trabalhar com vetor
#include <iomanip>  // Para controlar a formatação do número (como arredondamento)
#include <string>

using namespace std;

class Funcionario {
public: // permite visualizar em todo código!= private
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

    // Método para exibir o funcionário
    void exibir() {
        cout << "Nome: \033[33m" << nome << "\033[0m, "
             << "Departamento: \033[33m" << depto << "\033[0m, "
             << "Horas Trabalhadas: \033[33m" << horas << "\033[0m, "
             << "Salario: \033[33m" << fixed << setprecision(2) << salario << "\033[0m, "
             << "INSS: \033[33m " << fixed << setprecision(2) << INSS << "\033[0m" << endl;
    }
};

// Parâmetros do programa
const int parametro_tamanho_array = 2;
const double parametro_valor_departamento_1 = 22;
const double parametro_valor_departamento_2 = 12;

// Função para calcular o salário base (irá auxiliar para usar sempre que preciso)
//lista_funcionário será usado por referência para fazer alteração diretamente no vetor que está na main
void salario_base(vector<Funcionario> &lista_funcionarios) {
    for (int i = 0; i < parametro_tamanho_array; i++) {
        int comparador_depto = lista_funcionarios[i].depto;
        int horas = lista_funcionarios[i].horas;

        if (comparador_depto == 1) {
            if (horas > 40) {
                int horas_extras = horas - 40;
                lista_funcionarios[i].salario = (horas - horas_extras)*parametro_valor_departamento_1;
            } else {
                lista_funcionarios[i].salario = horas * parametro_valor_departamento_1;
            }
        } else if (comparador_depto == 2) {
            if (horas > 40) {
                int horas_extras = horas - 40;
                lista_funcionarios[i].salario = (horas - horas_extras)*parametro_valor_departamento_2;
            } else {
                lista_funcionarios[i].salario = horas * parametro_valor_departamento_2;
            }
        }
    }
}

int main() {
    string nome;
    int depto, horas;

    vector<Funcionario> funcionarios; //variável criada com vários tipos primitivos dentro de si

    cout << "Ola! - Painel do Gestor" << endl;
    cout << "Informe seu nome: ";
    cin >> nome;
    cout << "Seja bem vindo, " << nome << "! Essa e sua Tabela Salarial!" << endl;

    // Coletando os dados dos funcionários
    for (int i = 0; i < parametro_tamanho_array; i++) {
        cout << "\n---Cadastre seu funcionario - (" << i + 1 << ")!---" << endl;
        cout << "Digite o nome: ";
        cin >> nome;
        while (true) {
            cout << "Informe o departamento (1 ou 2): ";
            cin >> depto;
            if (depto == 1 || depto == 2) {
                break;
            } else {
                cout << "Opcao invalida! Departamento 1 ou 2" << endl;
            }
        }
        while (true) {
            cout << "Informe a quantidade de horas trabalhadas: ";
            cin >> horas;
            if (horas <= 0) {
                cout << "Hora invalida. Informe um numero maior que zero." << endl;
            } else {
                break;
            }
        }

        funcionarios.push_back(Funcionario(nome, depto, horas)); //colocando dentro do vetor
    }

    // Calculando
    salario_base(funcionarios);


    // Exibindo os resultados
    cout << "\n---Salario Bruto---" << endl;
    for (int i = 0; i < parametro_tamanho_array; i++) {
        funcionarios[i].exibir();
    }

    return 0;
}
