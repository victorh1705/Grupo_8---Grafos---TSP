# Grupo_8---Grafos---TSP
Trabalho de Grafos da UFJF 2017.1 que estuda e fornece heurísticas para o problema do caixeiro viajante (TSP - Travel Salesman Problem)


## Getting Started & installation

As configurações do Netbeans para C++ podem ser encontradas nesse [link](https://netbeans.org/community/releases/80/cpp-setup-instructions.html)

### CodeBlocks e Netbeans
Ao Utilizarmos o Code Blocks podemos fazer das seguinte maneiras:

1  - Cria o projeto e depois **fazer o clone dentro do projeto.** (Recomendado)<br>

* Criar o projeto do tipo **Console Application**;
* Cria uma pasta **Source** dentro do Projeto e clonar o arquivo para ele;
* Adicionar os arquivos no projeto.
* Copiar uma pasta de **instâncias** para a pasta do projeto

Disposição das pastas:
```
Projeto/
├── instancias/
│   ├── grafo.txt
│   ├── *.txt
├── Source/
│   ├── main.cpp
│   ├── *.cpp
│   ├── *.h
```

2 - Fazer o clone e depois **cria um projeto dentro da pasta de repositório.**

* Clonar o projeto em uma pasta *(ex.: Source)*;
* Criar um projeto do tipo **Console Application** dentro da pasta Source (pasta do repositório);
* Adicionar os arquivos no projeto;
* Adicionar a pasta do projeto no arquivo `.gitignore`.
* Copiar uma pasta de **instâncias** para a pasta do projeto

Disposição das pastas:
```
Source/
├── main.cpp/
├── *.cpp/
├── *.h/
├── Cpp_Application/
│   ├── Cpp_Application.cbp
│   ├── ... (outros arquivos do projeto)
│   ├── instancias/
│   │   ├── grafo.txt
│   │   ├── *.txt
```

### Netbeans

3 - Clonar o repositório utilizando o **Git** do Netbeans e depois cria um projeto

* No Netbeans ir no barra superior e selecionar:
```
Equipe > Git > Clonar 
```
* Finalize a clonagem. Depois irá aparecer uma janela chamada **Clonagem concluída** então selecionar **Criar Projeto**;
* Selecione **C/C++** e **Aplicação C/C++** e finalize a criação do projeto.
