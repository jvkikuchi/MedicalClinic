#include <iostream>
#include "agenda.cpp"

using namespace std;

Agenda agenda;
Paciente paciente;
Medico medico;
Consulta consulta;

void menuSuperior();
void menuPrincipal(int type);
void adicionar(int type);
void listar(int type);
void buscar(int type);
void editar(int type);
void remover(int type);
void salvar(int type);
string informar(string variavel);

int main() {
    int tipo = -1; // tipo de pessoa: (1) paciente (2) medico
    while (tipo) {
        menuSuperior();
        cin >> tipo;
        if (tipo == 1 || tipo == 2 || tipo == 3) {
            int action = -1;
            while (action) {
                menuPrincipal(tipo);
                cin >> action;
                switch (action) {
                    case 1: adicionar(tipo); break;
                    case 2: listar(tipo); break;
                    case 3: buscar(tipo); break;
                    case 4: editar(tipo); break;
                    case 5: remover(tipo); break;
                    case 6: salvar(tipo); break;
                    default: break;
                }
            }
        }
    }
}

void menuSuperior() {
    string output = "\nMENU:\n";
    output += "(1) Gerenciar pacientes\n";
    output += "(2) Gerenciar medicos\n";
    output += "(3) Gerenciar consultas\n";
    output += "(0) Sair\n";
    output += "ESCOLHA: ";
    cout << output;
}

void menuPrincipal(int type) {
    string entidade = "";
    switch (type) {
        case 1: entidade = "paciente"; break;
        case 2: entidade = "medico"; break;
        case 3: entidade = "consulta"; break;
    }
    string output = "";
    output = "\nMENU:";
    output += "\n(1) Adicionar " + entidade;
    output += "\n(2) Exibir " + entidade + "s";
    output += "\n(3) Buscar " + entidade;
    output += "\n(4) Editar " + entidade; 
    output += "\n(5) Remover " + entidade;
    output += "\n(6) Salvar " + entidade + "s";
    output += "\n(0) Retornar ao menu inicial";
    output += "\nESCOLHA: ";
    cout << output;
}

void adicionar(int type) {
    auto adicionarPaciente = []() {
        paciente.setNome(informar("Nome"));
        paciente.setIdade(stoi(informar("Idade")));
        paciente.setSexo(informar("Sexo"));
        paciente.setCpf(informar("CPF"));
        agenda.armazenarPaciente(paciente);
    };
    auto adicionarMedico = []() {
        medico.setNome(informar("Nome"));
        medico.setCrm(informar("CRM"));
        medico.setEspecialidade(informar("Especialidade"));
        agenda.armazenarMedico(medico);
    };
    auto adicionarConsulta = []() {
        consulta.setId(informar("ID"));
        consulta.setCpf(informar("CPF do paciente"));
        consulta.setCrm(informar("CRM do medico"));
        consulta.setData(informar("Data da consulta"));
        consulta.setHorario(informar("Horario da consulta"));
        agenda.armazenarConsulta(consulta);
    };
    switch (type) {
        case 1: adicionarPaciente(); break;
        case 2: adicionarMedico(); break;
        case 3: adicionarConsulta(); break;
    }
}

void listar(int type) {
    switch (type) {
        case 1: agenda.listarPacientes(); break;
        case 2: agenda.listarMedicos(); break;
        case 3: agenda.listarConsultas(); break;
    }
}

void buscar(int type) {
    switch (type) {
        case 1: agenda.buscarPaciente(informar("Buscar por nome")); break;
        case 2: agenda.buscarMedico(informar("Buscar por nome")); break;
        case 3: agenda.buscarConsulta(informar("Buscar por ID")); break;
    }
}

void editar(int type) {
    switch (type) {
        case 1: agenda.editarPaciente(informar("CPF")); break;
        case 2: agenda.editarMedico(informar("CRM")); break;
        case 3: agenda.editarConsulta(informar("ID")); break;
    }
}

void remover(int type) {
    switch (type) {
        case 1: agenda.removerPaciente(informar("CPF")); break;
        case 2: agenda.removerMedico(informar("CRM")); break;
        case 3: agenda.removerConsulta(informar("ID")); break;
    }
}

void salvar(int type) {
    switch (type) {
        case 1: agenda.salvarPacientes(); break;
        case 2: agenda.salvarMedicos(); break;
        case 3: agenda.salvarConsultas(); break;
    }
}

string informar(string variavel) {
    string elem;
    cout << variavel + ": ";
    cin >> elem;
    return elem;
}
