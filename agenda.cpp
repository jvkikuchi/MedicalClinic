#include <iostream>
#include <string>
#include "consulta.cpp"
#include <vector>
#include <fstream>
#include "utils.h"

using namespace std;

class Agenda{
    public:

        Agenda(){
            carregarPacientes();
        }

        void armazenarPaciente(Paciente paciente) {
            agenda.push_back(paciente);
        }

        void buscarPaciente(string regex) {
            if (regex.length() < 3) {
                cout << "O termo de busca deve conter pelo menos 3 caracteres." << endl;
                return;
            }
            bool found = false;
            for(auto paciente : agenda) {
                if (toLowerCase(paciente.getNome()).find(toLowerCase(regex)) != string::npos) {
                    print(paciente);
                    found = true;
                }
            }
            if (!found) {
                cout << "Nenhum registro encontrado." << endl;
            }
        }

        void editarPaciente(string regex) {
            bool found = false;
            for(auto &paciente : agenda) {
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

        void listarPacientes() {
            for (auto paciente : agenda) {
                print(paciente);
            }
        }

        void print(Paciente paciente) {
            string buffer = "\nNome: " + paciente.getNome();
            buffer += "\nIdade: " + to_string(paciente.getIdade());
            buffer += "\nSexo: " + paciente.getSexo();
            buffer += "\nCpf: " + paciente.getCpf();
            cout << buffer << endl;
        }

        void removerPaciente(string cpf) {
            bool found = false;
            // o (it) é um apontador para o endereco do paciente no vector<Paciente>
            // pois o erase funciona somente com enderecos, e nao com objetois
            // ou seja, ele acessa o endereco de memoria no vector, no caso do ++it, ele informa pro
            // it passar pro proximo endereco dentro do vector
            for (vector<Paciente>::iterator it = agenda.begin(); it != agenda.end(); ++it) {
                if (!found && it->getCpf() == cpf) {
                    agenda.erase(it);
                    found = true;
                }
            }
            if (!found) {
                cout << "Nenhum registro encontrado." << endl;
            }
        }
       
        void gravarArquivo() {
            saveFile();
        }

        string informar(string variavel) {
            string elem;
            cout << variavel + ": ";
            cin >> elem;
            return elem;
        }

    private:
    vector<Paciente> agenda;
    Paciente paciente;
    void carregarPacientes() {
        ifstream arquivo("pacientes.xml");
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
                agenda.push_back(paciente);
                openRegister = false;
            }
        }
        arquivo.close();
    }

    void saveFile() {
        ofstream arquivo("pacientes.xml");
        arquivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        arquivo << "<agenda>\n";
        for (auto paciente : agenda) {
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

    string tabs(int n) {
        int tabSize = 4; 
        string tabs = "";
        for (int i = 0; i < n * tabSize; i++) {
            tabs += " ";
        }
        return tabs;
    }

};