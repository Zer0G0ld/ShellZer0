<div align="center">
  <img src="src/$ SHELL ZERO.png" alt="Shell Zero">
  <p>Zer0 or Zer0G0ld - Autor</p>
</div>

# About
<p>A Shell of my own for my amusement!</p>
<p>...</p>
<p>Shell Zero is a shell that I'm developing in python and my goal is to someday compare it to Bash, fish or Oh My Zsh</p>

<details>
<summary>Table of Contents</summary>

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Basic Installation](#basic-installation)
- [Using Shell Zero](#using-shell-zero)

</details>

## Getting Started
### Prerequisites
- A Unix-like operating system: macOS, Linux. On Windows: WSL2 is preferred, but cygwin or msys also mostly work.
- `curl` or `wget` should be installed
- `git` should be installed (recommended v2.4.11 or higher)

### Basic Installation

| Method    | Command                                                                                           |
| :-------- | :------------------------------------------------------------------------------------------------ |
| **curl**  | `curl -L -o ShellZero.zip https://github.com/Zer0G0ld/ShellZero/archive/refs/heads/main.zip` |
| **wget**  | `wget https://github.com/Zer0G0ld/ShellZero/archive/refs/heads/main.zip -O ShellZero.zip`   |
| **git** | `git clone https://github.com/Zer0G0ld/ShellZero.git` |

### Unzip

| Method    | Command to unzip                                                                                 |
| :-------- | :------------------------------------------------------------------------------------------------ |
| **curl**  | `unzip ShellZero.zip` |
| **wget**  | `unzip ShellZero.zip`   |
| **git** | `cd ShellZero` |


### Using Shell Zero
```
chmod +x start.sh
./start.sh
help
```

When the `help` command is typed, you will recieve the avaliable commands at the moment.

```
Shell Zero é um projeto de linha de comando baseado em em sistemas unix e podendo ser utilizado para windows também
          
          Comandos:

            clear     -     Limpa o terminal
            ls        -     Lista diretórios
            cd        -     Se move entre os diretórios
            mkdir     -     Cria diretórios
            rm        -     Remove diretórios
            pwd       -     Mostra o caminho atual
            hello     -     Imprime uma mensagem de Zer0 ;)
```

Setting...

## License

Shell Zero is released under the [Apache License 2.0](https://github.com/Zer0G0ld/ShellZero/blob/main/LICENSE) 
