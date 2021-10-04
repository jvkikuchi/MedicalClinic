#include <iostream>
#include "agenda.cpp"

using namespace std;

Agenda agenda;
Paciente paciente;
Medico medico;

void menu();
void adicionarPaciente();
void editarPaciente();
string informar(string variavel);

int main() {
    int input = -1;
    while (input) {
        menu();
        cin >> input;
        switch (input) {
            case 1: adicionarPaciente(); break;
            case 2: agenda.listarPacientes(); break;
            case 3: agenda.buscarPaciente(informar("Buscar por")); break;
            case 4: agenda.editarPaciente(informar("CPF")); break;
            case 5: agenda.removerPaciente(informar("CPF")); break;
            case 6: agenda.gravarArquivo(); break;
        }
    }
}

void menu() {
    string output = "";
    output = "\nMENU:\n";
    output += "(1) Adicionar paciente/medico\n";
    output += "(2) Exibir pacientes\n";
    output += "(3) Buscar paciente\n";
    output += "(4) Editar paciente\n";    
    output += "(5) Remover paciente\n";
    output += "(6) Salvar pacientes\n";
    output += "(0) Sair\n";
    output += "ESCOLHA: ";
    cout << output;
}

void adicionarPaciente() {
    paciente.setNome(informar("Nome"));
    paciente.setIdade(stoi(informar("Idade")));
    paciente.setSexo(informar("Sexo"));
    paciente.setCpf(informar("CPF"));
    agenda.armazenarPaciente(paciente);
}

string informar(string variavel) {
    string elem;
    cout << variavel + ": ";
    cin >> elem;
    return elem;
}
