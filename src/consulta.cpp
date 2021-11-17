#include <string>

using namespace std;

class Consulta {

    private:
        string id;
        string cpf;
        string crm;
        string data;
        string horario;

    public:
        string getId() {
            return id;
        }

        void setId(string id) {
            this->id = id;
        }

        string getCpf() {
            return cpf;
        }

        void setCpf(string cpf) {
            this->cpf = cpf;
        }

        string getCrm() {
            return crm;
        }

        void setCrm(string crm) {
            this->crm = crm;
        }

        string getData() {
            return data;
        }

        void setData(string data) {
            this->data = data;
        }

        string getHorario() {
            return horario;
        }

        void setHorario(string horario) {
            this->horario = horario;
        }

        void marcarConsulta(string id, string cpf, string crm, string data, string horario) {
            this->id = id;
            this->cpf = cpf;
            this->crm = crm;
            this->data = data;
            this->horario = horario;
        }

        string toString() {
            string output = "";
            output += "\nNumero da Consulta: " + getId();
            output += "\nCPF do paciente: " + getCpf();
            output += "\nCRM do medico: " + getCrm();
            output += "\nData: " + getData();
            output += "\nHorario: " + getHorario();
            return output;
        }

};