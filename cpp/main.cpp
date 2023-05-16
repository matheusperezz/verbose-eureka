#include <iostream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main(){

    pid_t pid;

    // criando um processo filho
    pid = fork();
    fork();
    fork();
    fork();

    // Verificando se houve erro na criaçao do processo
    // Processo Pai >>> Processo filho | Todos os processos serao executados em momentos diferentes
    if (pid < 0){
        cerr << "Erro ao criar o processo" << endl;
    }

    if (pid == 0){
        cout << "Processo filho " << pid << endl;
    }

    else {
        cout << "Processo Pai " << pid << endl;
    }

    return 0;
}