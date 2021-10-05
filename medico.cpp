#include <string>

using namespace std;

class Medico {

    private:
        string nome;
        string crm;
        string especialidade;

    public:

        Medico() {
            init();
        }

        void init() {
            nome = "";
            crm = "";
            especialidade = "";
        }

        void setNome(string nomeMedico) {
            nome = nomeMedico;
        }

        string getNome() {
            return nome;
        }
        
        void setCrm(string valorCrm) {
            crm = valorCrm;
        }

        string getCrm() {
            return crm;
        }

        void setEspecialidade(string valorEspecialidade) {
            especialidade = valorEspecialidade;
        }

        string getEspecialidade() {
            return especialidade;
        }

};