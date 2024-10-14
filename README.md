<div align="center">
  <img src="V1.0/src/$ SHELL ZERO.png" alt="Shell Zero">
  <p>Zer0 ou Zer0G0ld - Autor</p>
</div>

# Sobre
<p>Uma shell própria para minha diversão!</p>
<p>Shell Zero é uma shell personalizada que estou desenvolvendo em C e Assembly, inspirada em shells populares como Bash, Fish e Oh My Zsh. Meu objetivo é criar algo poderoso, mas simples, que um dia possa competir com essas shells.</p>

<details>
<summary>Índice</summary>

- [Introdução](#introdução)
  - [Pré-requisitos](#pré-requisitos)
  - [Instalação Básica](#instalação-básica)
- [Usando a Shell Zero](#usando-a-shell-zero)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Licença](#licença)

</details>

## Estrutura do Projeto:

```bash
ShellZer0/
├── src/                # Código-fonte em C e Assembly
│   ├── main.c          # Loop principal da shell
│   ├── parser.c        # Funções de interpretação de comandos
│   ├── exec.c          # Funções de execução de programas e comandos internos
│   ├── utils.c         # Funções utilitárias (ex: manipulação de strings)
│   ├── asm/            # Código em Assembly, se necessário
│   │   └── syscall.asm  # Funções de chamadas de sistema (opcional)
├── include/            # Arquivos de cabeçalho
│   ├── shell.h         # Declarações de funções e estruturas principais da shell
│   ├── parser.h        # Declarações de funções relacionadas ao parser de comandos
│   └── exec.h          # Declarações de funções de execução
├── build/              # Diretório para binários compilados
├── tests/              # Testes unitários e de integração
│   ├── test_parser.c   # Testes para o parser de comandos
│   └── test_exec.c     # Testes para as funções de execução
├── docs/               # Documentação do projeto
│   └── README.md       # Descrição do projeto e instruções de uso
├── Makefile            # Script de automação da compilação
└── .github/            # Diretório para workflows do GitHub Actions (CI/CD)
    └── workflows/
        └── build.yml   # Configuração para compilar o projeto automaticamente
```

## Introdução

### Pré-requisitos

- Um sistema operacional baseado em Unix (macOS, Linux). No Windows, o WSL2 é preferível, mas o Cygwin ou Msys também devem funcionar.
- `curl` ou `wget` instalados.
- `git` instalado (recomendado v2.4.11 ou superior).

### Instalação Básica

| Método    | Comando                                                                                           |
| :-------- | :------------------------------------------------------------------------------------------------ |
| **curl**  | `curl -L -o ShellZero.zip https://github.com/Zer0G0ld/ShellZero/archive/refs/heads/main.zip` |
| **wget**  | `wget https://github.com/Zer0G0ld/ShellZero/archive/refs/heads/main.zip -O ShellZero.zip`   |
| **git**   | `git clone https://github.com/Zer0G0ld/ShellZero.git` |

### Extração

| Método    | Comando para descompactar                                                                         |
| :-------- | :------------------------------------------------------------------------------------------------ |
| **curl**  | `unzip ShellZero.zip` |
| **wget**  | `unzip ShellZero.zip`   |
| **git**   | `cd ShellZero` |

### Usando a Shell Zero

```bash
chmod +x start.sh
./start.sh
help
```

Ao digitar o comando `help`, a Shell Zero mostrará a lista de comandos disponíveis:

```bash
Shell Zero é um projeto de linha de comando baseado em sistemas Unix, mas pode ser utilizado também no Windows.

          Comandos Disponíveis:

            clear     - Limpa o terminal
            ls        - Lista diretórios
            cd        - Muda de diretório
            mkdir     - Cria diretórios
            rm        - Remove diretórios
            pwd       - Mostra o caminho atual
            hello     - Exibe uma mensagem personalizada de Zer0 ;)
```

## Licença

Shell Zero é liberado sob a [Apache License 2.0](https://github.com/Zer0G0ld/ShellZero/blob/main/LICENSE).
