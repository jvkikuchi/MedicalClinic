#include <iostream>
#include <string>

using namespace std;


class Paciente{
    private:
        string nome;
        int idade;
        string sexo;
        string cpf;


    public:

        Paciente(){
            init();
        }

        void init(){
            nome = "";
            sexo = "?";
            idade = 0;
            cpf = "00000000000";
        }

        void setNome(string nomePaciente){
            nome = nomePaciente;

        }

        string  getNome(){
            return nome;
        }

        void setIdade(int valIdade){
            idade = valIdade;
        }

        int getIdade(){
            return idade;
        }

        void setSexo(string valSexo){
            sexo = valSexo;
        }

        string getSexo(){
            return sexo;
        }

        void setCpf(string valCpf){
            cpf = valCpf;
        }

        string getCpf(){
            return cpf;
        }



};