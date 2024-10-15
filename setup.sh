#!/bin/bash

# Função para detectar o sistema operacional
detect_os() {
    UNAME=$(uname)
    if [[ "$UNAME" == "Linux" ]]; then
        if [[ -f "/data/data/com.termux/files/usr/bin/bash" ]]; then
            echo "Ambiente: Termux"
            return 1  # Retorna 1 para Termux
        else
            echo "Ambiente: Debian/WSL"
            return 0  # Retorna 0 para Debian/WSL
        fi
    else
        echo "Sistema não suportado. Somente Linux é compatível."
        exit 1
    fi
}

# Função para instalar dependências no Termux
install_termux_dependencies() {
    echo "Instalando dependências para Termux..."
    pkg update && pkg upgrade -y
    pkg install -y clang make readline
}

# Função para instalar dependências no Debian/WSL
install_debian_dependencies() {
    echo "Instalando dependências para Debian/WSL..."
    sudo apt update && sudo apt upgrade -y
    sudo apt install -y gcc make libreadline-dev
}

# Função principal
setup() {
    detect_os
    if [[ $? -eq 1 ]]; then
        # Se for Termux
        install_termux_dependencies
    elif [[ $? -eq 0 ]]; then
        # Se for Debian/WSL
        install_debian_dependencies
    fi

    echo "Dependências instaladas com sucesso!"
    echo "Agora você pode compilar o projeto com 'make'."
}

# Executa o setup
setup
