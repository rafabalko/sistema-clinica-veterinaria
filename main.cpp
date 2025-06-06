#include <iostream>

using namespace std;

struct Cidades {
    int codigo;
    char nome[100];
    char uf[2];
};

struct Racas {
    int codigo;
    char descricao[100];
};

struct Animais {
    int codigo;
    char nome[100];
    int codigo_raca;
    int idade;
    int peso;
    int codigo_tutor;
};

struct Tutores {
    int codigo;
    char nome[100];
    char cpf[12];
    char endereco[100];
    int codigo_cidade;
};

struct Veterinarios {
    int codigo;
    char nome[100];
    char endereco[100];
    int codigo_cidade;
};

struct Consultas {
    int codigo;
    int codigo_animal;
    int codigo_veterinario;
    char data_consulta[15];
    float valor;
};

void LerCidades(struct Cidades cidades[], int &contC) {
    for (int i = 0; i < contC; i++) {
        cout << "\nINFORME A CIDADE " << (i + 1);
        cout << "\nCodigo da Cidade:";
        cin >> cidades[i].codigo;
        cin.ignore();
        cout << "Nome da Cidade:";
        cin.getline(cidades[i].nome, 100);
        cout << "Estado:";
        cin.getline(cidades[i].uf, 3);
        cout << endl;
    }
}

void LerRacas(struct Racas racas[], int &contR) {
    for (int i = 0; i < contR; i++) {
        cout << "\nINFORME A RACA " << (i + 1);
        cout << "\nCodigo da Raca:";
        cin >> racas[i].codigo;
        cin.ignore();
        cout << "Descricao da Raca:";
        cin.getline(racas[i].descricao, 100);
        cout << endl;
    }
}

void LerTutores(struct Tutores tutores[], int &contT) {
    for (int i = 0; i < contT; i++) {
        cout << "\nINFORME O TUTOR " << (i + 1);
        cout << "\nCodigo do Tutor:";
        cin >> tutores[i].codigo;
        cin.ignore();
        cout << "Nome do Tutor:";
        cin.getline(tutores[i].nome, 100);
        cout << "CPF do Tutor:";
        cin >> tutores[i].cpf;
        cin.ignore();
        cout << "Endereco do Tutor:";
        cin.getline(tutores[i].endereco, 100);
        cout << "Codigo da Cidade:";
        cin >> tutores[i].codigo_cidade;
    }
}

void LerAnimais(struct Animais animais[], int &contA) {
    for (int i = 0; i < contA; i++) {
        cout << "\nINFORME O ANIMAL " << (i + 1);
        cout << "\nCodigo do Animal:";
        cin >> animais[i].codigo;
        cin.ignore();
        cout << "Nome do Animal:";
        cin.getline(animais[i].nome, 100);
        cout << "Codigo da Raca:";
        cin >> animais[i].codigo_raca;
        cout << "Idade do Animal:";
        cin >> animais[i].idade;
        cout << "Peso do Animal:";
        cin >> animais[i].peso;
        cout << "Codigo do Tutor:";
        cin >> animais[i].codigo_tutor;
    }
}

void LerVet(struct Veterinarios vet[], int &contV) {
    for (int i = 0; i < contV; i++) {
        cout << "\nINFORME O VETERINARIO " << (i + 1);
        cout << "\nCodigo do Veterinario: ";
        cin >> vet[i].codigo;
        cin.ignore();
        cout << "Nome do Veterinario: ";
        cin.getline(vet[i].nome, 100);
        cout << "Codigo da Cidade:";
        cin >> vet[i].codigo_cidade;
    }
}

void LerConsultas(struct Consultas consultas[], int &contCons) {
    for (int i = 0; i < contCons; i++) {
        cout << "\nINFORME A CONSULTA " << (i + 1);
        cout << "\nCodigo do Consulta:";
        cin >> consultas[i].codigo;
        cout << "Codigo do Animal:";
        cin >> consultas[i].codigo_animal;
        cout << "Codigo do Veterinario:";
        cin >> consultas[i].codigo_veterinario;
        cin.ignore();
        cout << "Data da Consulta:";
        cin.getline(consultas[i].data_consulta, 11);
        cout << "Valor da Consulta:";
        cin >> consultas[i].valor;
    }
}

bool ValidarCpf(char cpf[]) {
    int dig[11];
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return false;
        }
        dig[i] = cpf[i] - '0';
    }

    bool TodosIguais = true;
    for (int i = 1; i < 11; i++) {
        if (dig[i] != dig[0]) {
            TodosIguais = false;
        }
    }
    if (TodosIguais) {
        return false;
    }

    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += dig[i] * (10 - i);
    }
    int d1 = (soma * 10) % 11;
    if (d1 == 10) {
        d1 = 0;
    }
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += dig[i] * (11 - i);
    }
    int d2 = (soma * 10) % 11;
    if (d2 == 10) d2 = 0;
    return (d1 == dig[9] && d2 == dig[10]);
}

void IncluirTutores(struct Tutores tutores[], int &contT, Cidades cidades[], int contC) {
    if (contT >= 100) {
        cout << "Limite de tutores atingidos!" << endl;
        return;
    }
        Tutores novo{};
        cout << "\nINCLUIR NOVO TUTOR:";
        cout << "\nCodigo do Tutor:";
        cin >> novo.codigo;
        cin.ignore();
        cout << "Nome do tutor:";
        cin.getline(novo.nome, 100);
        do {
            cout << "CPF do Tutor:";
            cin >> novo.cpf;
            if (!ValidarCpf(novo.cpf)) {
                cout << "CPF invalido! Tente novamente..." << endl;
            }
        } while (!ValidarCpf(novo.cpf));
        cout << "Endereco do tutor:";
        cin.ignore();
        cin.getline(novo.endereco, 100);

        bool CidadeExiste = false;
        int CodCidade;
        do {
            cout << "Codigo da Cidade: ";
            cin >> CodCidade;
            cin.ignore();
            for (int i = 0; i < contC; i++) {
                if (cidades[i].codigo == CodCidade) {
                    CidadeExiste = true;
                    cout << "Cidade encontrada: " << cidades[i].nome << "/" << cidades[i].uf << endl;
                    novo.codigo_cidade = CodCidade;
                }
            }
            if (!CidadeExiste) {
                cout << "Codigo de cidade nao encontrado. Tente novamente." << endl;
            }
        } while (!CidadeExiste);

        tutores[contT] = novo;
        contT++;
}

void IncluirAnimais(struct Animais animais[], int &contA, Racas racas[], int contR, Tutores tutores[], int contT,
Cidades cidades[], int contC) {
    if (contA >= 100) {
        cout << "Limite de animais atingido!" << endl;
        return;
    }
        Animais novo{};
        cout << "\nINCLUIR NOVO ANIMAL:" << endl;
        cout << "\nCodigo do Animal: ";
        cin >> novo.codigo;
        cin.ignore();
        cout << "Nome do Animal: ";
        cin.getline(novo.nome, 100);

        bool RacaEncontrada = false;
        do {
            cout << "Codigo da Raca: ";
            cin >> novo.codigo_raca;
            cin.ignore();
            for (int i = 0; i < contR; i++) {
                if (racas[i].codigo == novo.codigo_raca) {
                    cout << "Descricao da Raca: " << racas[i].descricao << endl;
                    RacaEncontrada = true;
                }
            }
            if (!RacaEncontrada) {
                cout << "Codigo da Raca nao encontrado. Tente novamente." << endl;
            }
        } while (!RacaEncontrada);

        cout << "Idade do Animal:";
        cin >> novo.idade;
        cout << "Peso do Animal:";
        cin >> novo.peso;

        bool TutorEncontrado = false;
        do {
            cout << "Codigo do Tutor:";
            cin >> novo.codigo_tutor;
            cin.ignore();
            for (int i = 0; i < contT; i++) {
                if (tutores[i].codigo == novo.codigo_tutor) {
                    cout << "Nome do Tutor:" << tutores[i].nome << endl;

                    bool CidadeEncontrada = false;
                    for (int j = 0; j < contC; j++) {
                        if (cidades[j].codigo == tutores[i].codigo_cidade) {
                            cout << "Cidade do Tutor: " << cidades[j].nome << "/" << cidades[j].uf << endl;
                            CidadeEncontrada = true;
                        }
                    }
                    if (!CidadeEncontrada) {
                        cout << "Cidade do Tutor nao encontrada." << endl;
                    }
                    TutorEncontrado = true;
                }
            }
            if (!TutorEncontrado) {
                cout << "Codigo do Tutor nao encontrado. Tente novamente." << endl;
            }
        } while (!TutorEncontrado);

        animais[contA] = novo;
        contA++;
}

void IncluirConsulta(struct Consultas consultas[], int &contCons, Animais animais[], int contA,Racas racas[],
int contR, Tutores tutores[], int contT, Veterinarios vet[], int contV, Cidades cidades[], int contC) {
    if (contCons >= 100) {
        cout << "Limite de consultas atingido!" << endl;
        return;
    }

    Consultas nova{};
    nova.codigo = contCons + 1;
    cout << "\nCONSULTA NUMERO " << nova.codigo << endl;

    bool AnimalEncontrado = false;
    do {
        cout << "Informe o codigo do animal: ";
        cin >> nova.codigo_animal;
        cin.ignore();

        for (int i = 0; i < contA; i++) {
            if (animais[i].codigo == nova.codigo_animal) {
                AnimalEncontrado = true;
                cout << "Nome do Animal: " << animais[i].nome << endl;

                for (int j = 0; j < contR; j++) {
                    if (racas[j].codigo == animais[i].codigo_raca) {
                        cout << "Raca: " << racas[j].descricao << endl;
                    }
                }
                for (int k = 0; k < contT; k++) {
                    if (tutores[k].codigo == animais[i].codigo_tutor) {
                        cout << "Nome do Tutor: " << tutores[k].nome << endl;
                    }
                }
            }
        }
        if (!AnimalEncontrado) {
            cout << "Codigo do animal nao encontrado. Tente novamente." << endl;
        }
    } while (!AnimalEncontrado);

    bool VetEncontrado = false;
    do {
        cout << "Informe o codigo do veterinario: ";
        cin >> nova.codigo_veterinario;
        cin.ignore();

        for (int i = 0; i < contV; i++) {
            if (vet[i].codigo == nova.codigo_veterinario) {
                VetEncontrado = true;
                cout << "Nome do Veterinario: " << vet[i].nome << endl;

                for (int j = 0; j < contC; j++) {
                    if (vet[i].codigo_cidade == cidades[j].codigo) {
                        cout << "Cidade: " << cidades[j].nome << "/" << cidades[j].uf << endl;
                    }
                }
            }
        }
        if (!VetEncontrado) {
            cout << "Codigo do veterinario nao encontrado. Tente novamente." << endl;
        }
    } while (!VetEncontrado);

    cout << "Informe a data da consulta: ";
    cin.getline(nova.data_consulta, 15);

    cout << "Informe o valor da consulta: ";
    cin >> nova.valor;

    consultas[contCons] = nova;
    contCons++;
    cout << "\nConsulta cadastrada com sucesso!!\n";
}

int ConversaoData(const char data[]) {
    int dia, mes, ano;
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
    return ano * 10000 + mes * 100 + dia;
}

void MostrarConsPorData(Consultas consultas[], int contCons, Animais animais[], int contA, Veterinarios vet[],
int contV) {

    char DataI[15], DataF[15];
    cout << "\nInforme a data inicial: ";
    cin.ignore();
    cin.getline(DataI, 15);
    cout << "Informe a data final: ";
    cin.getline(DataF, 15);

    int DataInicial = ConversaoData(DataI);
    int DataFinal = ConversaoData(DataF);

    int ini = 0;
    int fim = contCons - 1;
    int posicao = -1;

    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        int dataMeio = ConversaoData(consultas[meio].data_consulta);

        if (dataMeio >= DataInicial && dataMeio <= DataFinal) {
            posicao = meio;
            break;
        }
        if (dataMeio < DataInicial) {
            ini = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    float total = 0;
    bool encontrou = false;

    cout << "\nConsultas realizadas entre os dias " << DataI << " a " << DataF << ":\n";
    if (posicao != -1) {
        int i = posicao;
        while (i >= 0 && ConversaoData(consultas[i].data_consulta) >= DataInicial) {
            i--;
        }
        i++;
        while (i < contCons && ConversaoData(consultas[i].data_consulta) <= DataFinal) {
            const char* nomeAnimal = "Inexistente!";
            for (int j = 0; j < contA; j++) {
                if (animais[j].codigo == consultas[i].codigo_animal) {
                    nomeAnimal = animais[j].nome;
                }
            }
            const char* nomeVet = "Inexistente!";
            for (int j = 0; j < contV; j++) {
                if (vet[j].codigo == consultas[i].codigo_veterinario) {
                    nomeVet = vet[j].nome;
                }
            }
            cout << "\nAnimal: " << nomeAnimal;
            cout << "\nVeterinario: " << nomeVet;
            cout << "\nData: " << consultas[i].data_consulta;
            cout << "\nValor: R$ " << consultas[i].valor << "\n";

            total = total + consultas[i].valor;
            encontrou = true;
            i++;
        }
    }
    if (!encontrou) {
        cout << "\nNenhuma consulta encontrada.\n";
    }
    else {
        cout << "\nValor total das consultas: R$ " << total << "\n";
    }
}
void MostrarConsPorVetEData(Consultas consultas[], int contCons, Animais animais[], int contA, Veterinarios vet[],
int contV) {

    int codigoVet;
    cout << "\nInforme o codigo do veterinario: ";
    cin >> codigoVet;
    cin.ignore();

    char DataI[15], DataF[15];
    cout << "Informe a data inicial: ";
    cin.getline(DataI, 15);
    cout << "Informe a data final: ";
    cin.getline(DataF, 15);

    int DataInicial = ConversaoData(DataI);
    int DataFinal = ConversaoData(DataF);

    int ini = 0;
    int fim = contCons - 1;
    int posicao = -1;

    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        int dataMeio = ConversaoData(consultas[meio].data_consulta);

        if (dataMeio >= DataInicial && dataMeio <= DataFinal) {
            posicao = meio;
            break;
        }
        if (dataMeio < DataInicial) {
            ini = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }
    const char* nomeVet = "Inexistente!";
    for (int i = 0; i < contV; i++) {
        if (vet[i].codigo == codigoVet) {
            nomeVet = vet[i].nome;
        }
    }

    float total = 0;
    bool encontrou = false;

    cout << "\nConsultas do(a) veterinario(a) " << nomeVet << " entre os dias " << DataI << " a " << DataF << ":\n";
    if (posicao != -1) {
        int i = posicao;
        while (i >= 0 && ConversaoData(consultas[i].data_consulta) >= DataInicial) {
            i--;
        }
        i++;
        while (i < contCons && ConversaoData(consultas[i].data_consulta) <= DataFinal) {
            if (consultas[i].codigo_veterinario == codigoVet) {
                const char* nomeAnimal = "Inexistente!";
                for (int j = 0; j < contA; j++) {
                    if (animais[j].codigo == consultas[i].codigo_animal) {
                        nomeAnimal = animais[j].nome;
                    }
                }
                cout << "\nAnimal: " << nomeAnimal;
                cout << "\nVeterinario: " << nomeVet;
                cout << "\nData: " << consultas[i].data_consulta;
                cout << "\nValor: R$ " << consultas[i].valor << "\n";

                total = total + consultas[i].valor;
                encontrou = true;
            }
            i++;
        }
    }
    if (!encontrou) {
        cout << "\nNenhuma consulta encontrada para o(a) veterinario(a)!!.\n";
    }
    else {
        cout << "\nValor total das consultas do(a) veterinario(a) " << nomeVet << ": R$ " << total << "\n";
    }
}

int main() {
    Cidades cidades[100];
    Racas racas[100];
    Tutores tutores[100];
    Veterinarios vet[100];
    Animais animais[100];
    Consultas consultas[100];

    int contCidades = 2;
    int contRacas = 2;
    int contTutores = 1;
    int contVet = 2;
    int contAnimais = 1;
    int contConsultas = 1;

    LerCidades(cidades, contCidades);
    LerRacas(racas, contRacas);
    LerTutores(tutores, contTutores);
    LerAnimais(animais, contAnimais);
    LerVet(vet, contVet);
    LerConsultas(consultas, contConsultas);

    int opcao;
    do {
        cout << "\n---------- MENU ----------\n";
        cout << "1 - Incluir Tutor\n";
        cout << "2 - Incluir Animal\n";
        cout << "3 - Incluir Consulta\n";
        cout << "4 - Consultas por Data\n";
        cout << "5 - Consultas por Data e Veterinario\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: \n";
        cin >> opcao;


        switch (opcao) {
            case 1:
                IncluirTutores(tutores, contTutores, cidades, contCidades);
                break;
            case 2:
                IncluirAnimais(animais, contAnimais, racas, contRacas, tutores,
                               contTutores, cidades, contCidades);
                break;
            case 3:
                IncluirConsulta(consultas, contConsultas, animais, contAnimais, racas,
                                contRacas, tutores, contTutores, vet, contVet, cidades, contCidades);
                break;
            case 4:
                MostrarConsPorData(consultas, contConsultas, animais, contAnimais, vet, contVet);
                break;
            case 5:
                MostrarConsPorVetEData(consultas, contConsultas, animais, contAnimais, vet, contVet);
                break;
            case 0:
                cout << "Programa encerrado!\n";
                break;
            default:
                cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);
}
