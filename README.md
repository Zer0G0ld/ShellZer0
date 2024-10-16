<div align="center">
  <img src="/img/$ SHELL ZERO.png" alt="Shell Zero">
  <p>Zer0 ou Zer0G0ld - Autor</p>
</div>

# Shell Zero

## Sobre

Shell Zero é uma shell personalizada, desenvolvida para ser simples, mas funcional, combinando características de outras shells como Bash, Zsh e Fish. Ela foi escrita em C e Assembly e tem como objetivo proporcionar uma experiência flexível e divertida para usuários que desejam interagir com o sistema de forma poderosa e leve.

Com comandos internos, suporte a atalhos de teclado (Ctrl+C, Ctrl+D, etc.) e funcionalidades básicas de navegação e execução de programas, o projeto é ideal para aprendizado e experimentação em ambientes Unix-like.

Usado no Sistema [Zer0S](https://github.com/Zer0G0ld/Zer0S).

As bases que passei a usar para criar e melhorar este Shell são:

1. **Interface de comandos eficiente:** Foco em capturar e interpretar comandos com boas funcionalidades como histórico, autocomplete e suporte a scripts.
2. **Execução de comandos:** Fazer o shell executar programas externos como ls, cd, pwd, etc.
3. **Automação e personalização:** Como permitir que os usuários criem scripts e aliases para suas tarefas.
4. **Extensibilidade:** Opção de personalizar o shell (com arquivos de configuração .zer0rc, por exemplo) e melhorar a interface.

---
 
## Índice

- [Sobre](#sobre)
- [Pré-requisitos](#pré-requisitos)
- [Instalação](#instalação)
- [Usando a Shell Zero](#usando-a-shell-zero)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Contribuindo](#contribuindo)
- [Licença](#licença)

---

## Pré-requisitos

Antes de instalar e usar o Shell Zero, você precisará dos seguintes itens:

- Um sistema operacional baseado em Unix (Linux, macOS, ou WSL2 no Windows).
- **GCC** (GCC ou outro compilador C instalado).
- **Make** (para compilar e construir o projeto).
- **Readline** (biblioteca para manipulação de entrada de usuário com suporte a histórico e atalhos).
- **Git** (opcional, para clonar o repositório).

## Instalação

### Clonando o Repositório

Para obter a versão mais recente do Shell Zero, clone o repositório Git:

```bash
git clone https://github.com/Zer0G0ld/ShellZero.git
cd ShellZero
```

### Instalando as Dependências

Certifique-se de ter o **Readline** instalado. No Termux ou sistemas Linux, você pode instalar com:

```bash
apt update
apt install libreadline-dev
```

Em outras distribuições:

```bash
sudo apt-get install libreadline-dev   # Debian/Ubuntu
sudo pacman -S readline                # Arch
brew install readline                  # macOS
```

### Compilando o Projeto

Use o `make` para compilar o Shell Zero:

```bash
make
```

Isso irá gerar o binário `ShellZer0` no diretório principal do projeto.

## Usando a Shell Zero

Depois de compilar o projeto, execute a shell:

```bash
./ShellZer0
```

Agora você pode usar os comandos disponíveis, navegar pelos diretórios e executar programas. A shell suporta o uso de atalhos como `Ctrl+C` para interromper comandos e `Ctrl+D` para sair.

### Comandos Suportados

A Shell Zero já implementa os seguintes comandos:

- `cd` - Muda o diretório atual.
- `ls` - Lista arquivos e diretórios.
- `pwd` - Exibe o caminho completo do diretório atual.
- `mkdir` - Cria um novo diretório.
- `rm` - Remove arquivos ou diretórios.
- `clear` - Limpa o terminal.
- `exit` - Sai da shell.

Além disso, atalhos de teclado como `Ctrl+C` (interrupção de processos) e `Tab` (autocompletar) são suportados.

### Exemplo de Uso

```bash
Zer0@~/ShellZero$ ls
LICENSE  Makefile  README.md  build  src  tests
Zer0@~/ShellZero$ cd src
Zer0@~/src$ pwd
/data/data/com.termux/files/home/ShellZero/src
Zer0@~/src$ exit
```

---

## Estrutura do Projeto

```bash
ShellZer0/
├── src/                # Código-fonte em C e Assembly
│   ├── main.c          # Loop principal da shell
│   ├── parser.c        # Funções de interpretação de comandos
│   ├── exec.c          # Funções de execução de comandos
│   ├── utils.c         # Funções utilitárias
│   └── asm/            # Código em Assembly, se houver
├── include/            # Arquivos de cabeçalho
│   ├── shell.h         # Declarações gerais da shell
│   ├── parser.h        # Declarações relacionadas ao parser
│   └── exec.h          # Declarações relacionadas à execução
├── build/              # Diretório de saída de compilação
├── tests/              # Testes unitários e de integração
├── docs/               # Documentação
├── Makefile            # Script para compilar o projeto
└── .github/            # Configurações para CI/CD
```

## Contribuindo

Se quiser contribuir com o desenvolvimento da Shell Zero, siga estes passos:

1. Faça um fork do projeto.
2. Crie uma nova branch (`git checkout -b feature/sua-feature`).
3. Envie suas modificações (`git commit -am 'Adiciona nova funcionalidade'`).
4. Envie para o seu fork (`git push origin feature/sua-feature`).
5. Abra um pull request no repositório original.

---

## Licença

Este projeto é licenciado sob a [Licença Apache 2.0](LICENSE).

----

### Proximas Melhorias 
#### Melhorias que podem ser implementadas:
1. Criação automática do .zer0rc: Se o arquivo não existir, o ShellZer0 pode perguntar ao usuário se ele gostaria de criá-lo.
2. Maior integração com o ambiente do sistema: Como lidar com variáveis de ambiente e redirecionamento de I/O para simular um terminal mais completo.

