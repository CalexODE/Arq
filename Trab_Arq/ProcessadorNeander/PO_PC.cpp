#include "PC.h"

#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
	ULA *ula = new ULA();
    REGS *regs =  new REGS();
    MEM *mem = new MEM();
    PC *pc = new PC(*ula, *regs, *mem);


    //Dados
    ifstream dados("dados.txt");

    string line;
    int c = 0;

    if (!dados){
        cout<<"Erro ao abrir arquivo"<<endl;
        return -1;
    }
    while(getline(dados, line))
    {

        if (!line.empty())
        {
            size_t found = line.find(" ");
            string end;
            string dado;
            int i;
            
            for(i = 0; i < (int)found; i++){
                end.push_back(line[i]);
            }

            for(int j = i+1; j < (int)line.size(); j++){
                dado.push_back(line[j]);
            }

            cout <<end << " "<< dado << endl;
            mem->set(atoi(end.c_str()), atoi(dado.c_str()));
            cout<<mem->get(atoi(end.c_str()))<<endl;
        }
    }
    dados.close();


    //Funcoes
    ifstream func("func.txt");

    if (!func) {
        cout<<"Erro ao abrir arquivo"<<endl;
        return -1;
    }
    while(getline(func, line))
    {

        if (!line.empty())
        {
            mem->set(c++, atoi(line.c_str()));
            cout<<line<<endl;
        }
    }
    func.close();
    
    /*


    int* matriz = new int[size * size];
    for (int i = 0; i < size*size; ++i) {
        if (!(file >> matriz[i])) {Falhou em ler um dos valores}
    }

    Faça algo com sua matriz aqui.

    delete[] matriz;
    */



    for(int clock=0; clock < 100; clock++)
    {
    	pc->FTE();
    	pc->updateState();
        cout<< ".";
    	if (pc->getLastState() == true)
    	{
    		break;
    	}
    }
    cout<<endl;
    return 0;
}