#include <iostream>
#include <string>
#include "paciente.cpp"
#include "medico.cpp"


using namespace std;


class Consulta{
    private:
        Paciente paciente;
        Medico medico;
        string data;
        string hora;

    public:

        Paciente getPaciente(){
            return paciente;
        }

        void setPaciente(Paciente varPaciente){
            paciente = varPaciente;
        }

        Medico getMedico(){
            return medico;
        }

        void setMedico(Medico varMedico){
            medico = varMedico;
        }

        string toString(){
            return paciente.getNome() + " " + medico.getNome();
        }

        void setHora(string valHora){
            hora = valHora;
        }

        string getHora(){
            return hora;

        }

        void setData(string valData){
            data = valData;
        }

        string getData(){
            return data;
        }      
};