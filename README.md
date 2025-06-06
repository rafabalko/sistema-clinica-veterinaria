# 🐾 Sistema de Clínica Veterinária

Este projeto é um sistema de gerenciamento para uma clínica veterinária, 
desenvolvido em C++ como parte de um trabalho acadêmico. Ele permite o 
cadastro e consulta de cidades, raças, tutores, animais, veterinários e 
consultas realizadas.

---

## 🚀 Funcionalidades

- Cadastro e listagem de:
    - Cidades
    - Raças
    - Tutores
    - Animais
    - Veterinários
    - Consultas


- Consultas com:
    - Filtro por data
    - Filtro por veterinário
    - Intervalo de datas
    - Totalização de valores por período

---

## 🧠 Tecnologias e Ferramentas

- **Linguagem**: C++
- **Padrão**: C++20
- **IDE utilizada**: JetBrains CLion
- **Compilador recomendado**:
    - Windows: MinGW ou MSVC
    - Linux/macOS: GCC

---

### 1. Clonar o repositório


1. `git clone git@github.com:rafabalko/sistema-clinica-veterinaria.git`
2. `cd sistema-clinica-veterinaria`

### 2. Abrir no CLion

1. Abra o CLion.
2. Vá em `File > Open` e selecione a pasta do projeto clonado.
3. Aguarde o carregamento automático do CMake.

### 3. Compilar e rodar

- Para compilar: `Build > Build Project` ou pressione `Ctrl + F9`
- Para executar: `Run > Run 'main'` ou pressione `Shift + F10`


## 📁 Estrutura do Projeto

    ├── main.cpp             # Arquivo principal do sistema
    
    ├── .idea/               # Configurações da IDE (ignorado no Git)
    
    ├── README.md            # Este arquivo
    
    ├── CMakeLists.txt       # Configuração de build (gerado pelo CLion)

## ❗ Observações

* A pasta .idea/ está listada no .gitignore e não será versionada.

* O projeto utiliza apenas bibliotecas padrão do C++. 

* Não há dependências externas ou banco de dados — o sistema usa vetores de structs em memória.

## 👨‍💻 Autor

Rafael Augusto Balko de Souza

Projeto acadêmico para a disciplina de Algoritmo e Estrutura de Dados.
