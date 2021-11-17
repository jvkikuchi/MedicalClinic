#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "consulta.cpp"
#include "paciente.cpp"
#include "medico.cpp"
#include "../lib/utils.h"

using namespace std;

class Agenda {
    public:
        Agenda() {
            carregarPacientes();
            carregarMedicos();
            carregarConsultas();
        }

        void armazenarPaciente(Paciente paciente) {
            agendaPacientes.push_back(paciente);
        }

        void armazenarMedico(Medico medico) {
            agendaMedicos.push_back(medico);
        }

        void armazenarConsulta(Consulta consulta) {
            agendaConsultas.push_back(consulta);
        }

        void buscarPaciente(string regex) {
            if (regex.length() < 3) {
                cout << "O termo de busca deve conter pelo menos 3 caracteres." << endl;
                return;
            }
            bool found = false;
            for(auto paciente : agendaPacientes) {
                if (toLowerCase(paciente.getNome()).find(toLowerCase(regex)) != string::npos) {
                    print(paciente);
                    found = true;
                }
            }
            if (!found) {
                cout << "Nenhum registro encontrado." << endl;
            }
        }

        void buscarMedico(string regex) {
            if (regex.length() < 3) {
                cout << "O termo de busca deve conter pelo menos 3 caracteres." << endl;
                return;
            }
            bool found = false;
            for(auto medico : agendaMedicos) {
                if (toLowerCase(medico.getNome()).find(toLowerCase(regex)) != string::npos) {
                    print(medico);
                    found = true;
                }
            }
            if (!found) {
                cout << "Nenhum registro encontrado." << endl;
            }
        }

        void buscarConsulta(string regex) {
            if (regex.length() < 3) {
                cout << "O termo de busca deve conter pelo menos 3 caracteres." << endl;
                return;
            }
            bool found = false;
            for(auto consulta : agendaConsultas) {
                if (consulta.getId().find(regex) != string::npos) {
                    print(consulta);
                    found = true;
                }
            }
            if (!found) {
                cout << "Nenhum registro encontrado." << endl;
            }
        }

        void editarPaciente(string regex) {
            bool found = false;
            for(auto &paciente : agendaPacientes) {
                if (toLowerCase(paciente.getCpf()).find(toLowerCase(regex)) != string::npos) {
                    print(paciente);
                    paciente.setNome(informar("\nNovo nome"));
                    paciente.setIdade(stoi(informar("Nova idade")));
                    paciente.setSexo(informar("Novo sexo"));
                    paciente.setCpf(informar("Novo cpf"));
                    found = true;
                }
            }
            if (!found) {
                cout << "Nenhum registro encontrado." << endl;
            }
        }

        void editarMedico(string regex) {
            bool found = false;
            for(auto &medico : agendaMedicos) {
                if (toLowerCase(medico.getCrm()).find(toLowerCase(regex)) != string::npos) {
                    print(medico);
                    medico.setNome(informar("\nNovo nome"));
                    medico.setCrm(informar("Novo CRM"));
                    medico.setEspecialidade(informar("Nova especialidade"));
                    found = true;
                }
            }
            if (!found) {
                cout << "Nenhum registro encontrado." << endl;
            }
        }

        void editarConsulta(string regex) {
            bool found = false;
            for(auto &consulta : agendaConsultas) {
                if (consulta.getId().find(regex) != string::npos) {
                    print(consulta);
                    consulta.setId(informar("\nNovo ID"));
                    consulta.setCpf(informar("Novo CPF do paciente"));
                    consulta.setCrm(informar("Novo CRM do medico"));
                    consulta.setData(informar("Nova data"));
                    consulta.setHorario(informar("Nova horario"));
                    found = true;
                }
            }
            if (!found) {
                cout << "Nenhum registro encontrado." << endl;
            }
        }

        void listarPacientes() {
            for (auto paciente : agendaPacientes) {
                print(paciente);
            }
        }

        void listarMedicos() {
            for (auto medico : agendaMedicos) {
                print(medico);
            }
        }

        void listarConsultas() {
            for (auto consulta : agendaConsultas) {
                print(consulta);
            }
        }

        void print(Paciente paciente) {
            string output = "\nNome: " + paciente.getNome();
            output += "\nIdade: " + to_string(paciente.getIdade());
            output += "\nSexo: " + paciente.getSexo();
            output += "\nCpf: " + paciente.getCpf();
            cout << output << endl;
        }

        void print(Medico medico) {
            string output = "\nNome: " + medico.getNome();
            output += "\nCRM: " + medico.getCrm();
            output += "\nEspecialidade: " + medico.getEspecialidade();
            cout << output << endl;
        }

        void print(Consulta consulta) {
            string output = "\nID: " + consulta.getId();
            output += "\nCPF do paciente: " + consulta.getCpf();
            output += "\nCRM do medico: " + consulta.getCrm();
            output += "\nData: " + consulta.getData();
            output += "\nHorario: " + consulta.getHorario();
            cout << output << endl;
        }

        void removerPaciente(string cpf) {
            bool found = false;
            // o (it) é um apontador para o endereco do paciente no vector<Paciente>
            // pois o erase funciona somente com enderecos, e nao com objetos,
            // ou seja, ele acessa o endereco de memoria no vector, no caso do ++it, ele informa pro
            // it passar pro proximo endereco dentro do vector
            for (vector<Paciente>::iterator it = agendaPacientes.begin(); it != agendaPacientes.end(); ++it) {
                if (!found && it->getCpf() == cpf) {
                    agendaPacientes.erase(it);
                    found = true;
                }
            }
            if (!found) {
                cout << "Nenhum registro encontrado." << endl;
            }
        }

        void removerMedico(string crm) {
            bool found = false;
            for (vector<Medico>::iterator it = agendaMedicos.begin(); it != agendaMedicos.end(); ++it) {
                if (!found && it->getCrm() == crm) {
                    agendaMedicos.erase(it);
                    found = true;
                }
            }
            if (!found) {
                cout << "Nenhum registro encontrado." << endl;
            }
        }

        void removerConsulta(string id) {
            bool found = false;
            for (vector<Consulta>::iterator it = agendaConsultas.begin(); it != agendaConsultas.end(); ++it) {
                if (!found && it->getId() == id) {
                    agendaConsultas.erase(it);
                    found = true;
                }
            }
            if (!found) {
                cout << "Nenhum registro encontrado." << endl;
            }
        }
       
        void salvarPacientes() {
            ofstream arquivo("resources/pacientes.xml");
            arquivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
            arquivo << "<agenda>\n";
            for (auto paciente : agendaPacientes) {
                arquivo << tabs(1) + "<paciente>\n";
                arquivo << tabs(2) + "<nome>" + paciente.getNome() + "</nome>\n";
                arquivo << tabs(2) + "<idade>" + to_string(paciente.getIdade()) + "</idade>\n";
                arquivo << tabs(2) + "<sexo>" + paciente.getSexo() + "</sexo>\n";
                arquivo << tabs(2) + "<cpf>" + paciente.getCpf() + "</cpf>\n";
                arquivo << tabs(1) + "</paciente>\n";
            }
            arquivo << "</agenda>\n";
            arquivo.close();
        }

        void salvarMedicos() {
            ofstream arquivo("resources/medicos.xml");
            arquivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
            arquivo << "<agenda>\n";
            for (auto medico : agendaMedicos) {
                arquivo << tabs(1) + "<medico>\n";
                arquivo << tabs(2) + "<nome>" + medico.getNome() + "</nome>\n";
                arquivo << tabs(2) + "<crm>" + medico.getCrm() + "</crm>\n";
                arquivo << tabs(2) + "<especialidade>" + medico.getEspecialidade() + "</especialidade>\n";
                arquivo << tabs(1) + "</medico>\n";
            }
            arquivo << "</agenda>\n";
            arquivo.close();
        }

        void salvarConsultas() {
            ofstream arquivo("resources/consultas.xml");
            arquivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
            arquivo << "<agenda>\n";
            for (auto consulta : agendaConsultas) {
                arquivo << tabs(1) + "<consulta>\n";
                arquivo << tabs(2) + "<id>" + consulta.getId() + "</id>\n";
                arquivo << tabs(2) + "<cpf>" + consulta.getCpf() + "</cpf>\n";
                arquivo << tabs(2) + "<crm>" + consulta.getCrm() + "</crm>\n";
                arquivo << tabs(2) + "<data>" + consulta.getData() + "</data>\n";
                arquivo << tabs(2) + "<horario>" + consulta.getHorario() + "</horario>\n";
                arquivo << tabs(1) + "</consulta>\n";
            }
            arquivo << "</agenda>\n";
            arquivo.close();
        }

        string informar(string variavel) {
            string elem;
            cout << variavel + ": ";
            cin >> elem;
            return elem;
        }

    private:
    vector<Paciente> agendaPacientes;
    vector<Medico> agendaMedicos;
    vector<Consulta> agendaConsultas;
    Paciente paciente;
    Medico medico;
    Consulta consulta;
    void carregarPacientes() {
        ifstream arquivo("resources/pacientes.xml");
        string line;
        bool openRegister = false;
        while(getline(arquivo,line)) {
            // tira espaços do inicio e do final
            trim(line);
            if (line.find("<paciente>") != string::npos) {
                openRegister = true;
            }
            // o controle de inserção dos dados ẽ feito atraves do openRegister, quando openRegister = true
            // é pq o registro esta aberto para leitura

            // string::npos é uma mensagem de erro. no caso do line.find() nao for igual a mensagem de erro,
            // o codigo vai substituir no xml

            else if (line.find("<nome>") != string::npos && openRegister) {
                //o replace all substitui uma string por outra, nesse caso as tags sao trocadas por ""
                line = replaceAll(line,"<nome>","");
                line = replaceAll(line,"</nome>","");
                paciente.setNome(line);
            }
            else if (line.find("<idade>") != string::npos && openRegister) {
                line = replaceAll(line,"<idade>","");
                line = replaceAll(line,"</idade>","");
                //stoin = string to int
                paciente.setIdade(stoi(line));
            }
            else if (line.find("<sexo>") != string::npos && openRegister) {
                line = replaceAll(line,"<sexo>","");
                line = replaceAll(line,"</sexo>","");
                paciente.setSexo(line);
            }

            else if (line.find("<cpf>") != string::npos && openRegister) {
                line = replaceAll(line,"<cpf>","");
                line = replaceAll(line,"</cpf>","");
                paciente.setCpf(line);
            }
            
            else if (line.find("</paciente>") != string::npos) {
                agendaPacientes.push_back(paciente);
                openRegister = false;
            }
        }
        arquivo.close();
    }

    void carregarMedicos() {
        ifstream arquivo("resources/medicos.xml");
        string line;
        bool openRegister = false;
        while(getline(arquivo,line)) {
            trim(line);
            if (line.find("<medico>") != string::npos) {
                openRegister = true;
            }
            else if (line.find("<nome>") != string::npos && openRegister) {
                line = replaceAll(line,"<nome>","");
                line = replaceAll(line,"</nome>","");
                medico.setNome(line);
            }
            else if (line.find("<crm>") != string::npos && openRegister) {
                line = replaceAll(line,"<crm>","");
                line = replaceAll(line,"</crm>","");
                medico.setCrm(line);
            }
            else if (line.find("<especialidade>") != string::npos && openRegister) {
                line = replaceAll(line,"<especialidade>","");
                line = replaceAll(line,"</especialidade>","");
                medico.setEspecialidade(line);
            }
            else if (line.find("</medico>") != string::npos) {
                agendaMedicos.push_back(medico);
                openRegister = false;
            }
        }
        arquivo.close();
    }

    void carregarConsultas() {
        ifstream arquivo("resources/consultas.xml");
        string line;
        bool openRegister = false;
        while(getline(arquivo,line)) {
            trim(line);
            if (line.find("<consulta>") != string::npos) {
                openRegister = true;
            }
            else if (line.find("<id>") != string::npos && openRegister) {
                line = replaceAll(line,"<id>","");
                line = replaceAll(line,"</id>","");
                consulta.setId(line);
            }
            else if (line.find("<cpf>") != string::npos && openRegister) {
                line = replaceAll(line,"<cpf>","");
                line = replaceAll(line,"</cpf>","");
                consulta.setCpf(line);
            }
            else if (line.find("<crm>") != string::npos && openRegister) {
                line = replaceAll(line,"<crm>","");
                line = replaceAll(line,"</crm>","");
                consulta.setCrm(line);
            }
            else if (line.find("<data>") != string::npos && openRegister) {
                line = replaceAll(line,"<data>","");
                line = replaceAll(line,"</data>","");
                consulta.setData(line);
            }
            else if (line.find("<horario>") != string::npos && openRegister) {
                line = replaceAll(line,"<horario>","");
                line = replaceAll(line,"</horario>","");
                consulta.setHorario(line);
            }
            else if (line.find("</consulta>") != string::npos) {
                agendaConsultas.push_back(consulta);
                openRegister = false;
            }
        }
        arquivo.close();
    }

    string tabs(int n) {
        int tabSize = 4; 
        string tabs = "";
        for (int i = 0; i < n * tabSize; i++) {
            tabs += " ";
        }
        return tabs;
    }

};
