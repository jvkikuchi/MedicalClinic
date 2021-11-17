#include <iostream>
#include "agenda.cpp"

using namespace std;

int main( ) {
    Agenda agenda;
    Consulta consulta;
    Paciente paciente;
    Medico medico;
    string id = "202110041000";
    string data = "04/10/2021";
    string hora = "10:00 AM";
    agenda.listarPacientes();
    paciente.setNome("Antonio Bernandes Cavalcante");
    paciente.setIdade(25);
    paciente.setSexo("M");
    paciente.setCpf("12345678900");
    medico.setNome("Pedro Queiroz Rosario dos Santos");
    medico.setCrm("12345678900");
    medico.setEspecialidade("Ortopedia");
    consulta.marcarConsulta(id, paciente.getCpf(), medico.getCrm(), data, hora);
    cout << "\n" << consulta.toString() << endl;
    return 0;
}
