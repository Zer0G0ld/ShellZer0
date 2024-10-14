<div align="center">
  <img src="/img/$ SHELL ZERO.png" alt="Shell Zero">
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

## Lógica do Projeto:

### 1. **Configuração Inicial e Preparação do Ambiente**
   - **Objetivo:** Configurar o ambiente de desenvolvimento para garantir que tudo funcione corretamente.
   - **Ações:**
     1. Configure o ambiente no Termux ou no Debian/WSL.
     2. Crie o `Makefile` inicial para compilar os arquivos C e Assembly.
     3. Crie a estrutura inicial de arquivos vazios (`main.c`, `parser.c`, `exec.c`, etc.).
     4. Defina o layout básico do `README.md` com as instruções de configuração.

### 2. **Desenvolvimento do Loop Principal do Shell**
   - **Objetivo:** Criar o esqueleto do shell, implementando o loop principal que irá ler e processar comandos.
   - **Ações:**
     1. No `main.c`, implemente o loop que:
        - Exibe um prompt para o usuário (`ShellZer0>`).
        - Lê a entrada do usuário (usando `fgets` ou similar).
        - Verifica se o comando é válido e passa para o parser.
     2. Crie funções de suporte no `utils.c` para manipulação de strings (ex: remover espaços, quebrar a linha em argumentos).

### 3. **Parser de Comandos**
   - **Objetivo:** Criar o parser que interpreta a entrada do usuário e divide o comando e seus argumentos.
   - **Ações:**
     1. No `parser.c`, implemente uma função que divide o comando em tokens (ex: `ls -l` → `["ls", "-l"]`).
     2. No `parser.h`, defina a interface da função do parser.
     3. Adicione testes no arquivo `test_parser.c` para verificar se o parser funciona corretamente.

### 4. **Execução de Comandos Internos**
   - **Objetivo:** Implementar funções para executar comandos internos da shell, como `cd`, `clear`, e `exit`.
   - **Ações:**
     1. No `exec.c`, implemente uma função que recebe o comando e decide se ele é um comando interno ou externo.
     2. Implemente comandos como `cd`, `clear`, e `exit`.
     3. No `exec.h`, defina as funções de execução de comandos.
     4. Teste esses comandos com casos de teste no arquivo `test_exec.c`.

### 5. **Execução de Comandos Externos**
   - **Objetivo:** Executar comandos do sistema, como `ls`, `mkdir`, e `rm`, chamando funções do sistema.
   - **Ações:**
     1. No `exec.c`, use funções como `fork()` e `execvp()` para executar comandos externos.
     2. Implemente o comportamento de espera (`waitpid()`) para o shell aguardar a conclusão do comando.

### 6. **Funções Utilitárias**
   - **Objetivo:** Adicionar funcionalidades como manipulação de diretórios e strings.
   - **Ações:**
     1. No `utils.c`, implemente funções como `getcwd()` para exibir o diretório atual.
     2. Implemente uma função para manipulação de paths.

### 7. **Chamadas de Sistema (Opcional)**
   - **Objetivo:** Integrar funcionalidades em Assembly para chamadas de sistema, se necessário.
   - **Ações:**
     1. No `asm/syscall.asm`, adicione chamadas de sistema básicas, como `read`, `write` e `open` (opcional).
     2. Teste as integrações entre C e Assembly.

### 8. **Testes e Integração Contínua**
   - **Objetivo:** Garantir que o código funcione corretamente em diferentes situações e ambientes.
   - **Ações:**
     1. Escreva testes unitários para o parser, execução de comandos e funções utilitárias nos arquivos de testes (`test_parser.c`, `test_exec.c`).
     2. Configure o GitHub Actions (arquivo `build.yml`) para automatizar os testes e builds.

### 9. **Documentação e Melhorias**
   - **Objetivo:** Finalizar a documentação e preparar o shell para uso.
   - **Ações:**
     1. No `README.md`, atualize as instruções com exemplos de uso e a lista completa de comandos suportados.
     2. Adicione explicações detalhadas na pasta `docs/` sobre a arquitetura do ShellZer0.

### 10. **Migração para Debian/WSL e Expansão**
   - **Objetivo:** Ampliar o desenvolvimento do ShellZer0 com funcionalidades avançadas.
   - **Ações:**
     1. Migre o projeto para o Debian ou WSL para trabalhar com chamadas de sistema mais complexas e funcionalidades avançadas (ex: autocompletar, histórico de comandos).
     2. Expanda os testes para garantir a compatibilidade com diferentes ambientes.

### 11. **Integração com o Zer0S**
   - **Objetivo:** Preparar o ShellZer0 para ser integrado ao sistema operacional Zer0S.
   - **Ações:**
     1. Trabalhe na comunicação entre o shell e o kernel, preparando a interface.
     2. Ajuste o código do shell para que ele se integre perfeitamente ao ambiente do Zer0S quando o kernel estiver completo.

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
