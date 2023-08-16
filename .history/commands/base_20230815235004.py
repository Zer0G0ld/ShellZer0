import subprocess
import threading
import time
import os
from commands.platformSys import get_operating_system

# Mensagens de erro
ERR_INVALID_COMMAND = "Comando inválido ou não suportado."
ERR_SYSTEM_NOT_SUPPORTED = "Sistema não suportado."

# Comandos
def executeCommand(command):
    try:
        result = subprocess.run(command, shell=True, text=True, capture_output=True)
        if result.returncode == 0:
            print(result.stdout)
        else:
            print(result.stderr)
    except Exception as error:
        print('Erro ao executar o comando: ', error)

def clear_secreen():
    try:
        #if os,name == 'posix':
        #    _ = os.system('clear')
        #elif os.name == 'nt':
        #    _ = os.system('cls')
        #else:
        #    print(ERR_SYSTEM_NOT_SUPPORTED)
        #clear = os.getcwd()
        clear = os.system('cls' if os.name == 'nt' else 'clear')
    except Exception as error:
        clear = "Erro ao tentar limpar o terminal: " + str(error)
    return clear

def list_dir():
    try:
        files = os.listdir('.')
        for file in files:
            print(file)
    except Exception as error:
        print('Erro ao listar diretórios: ', error)

def change_directory(user_input):
    try:
        new_dir = input("digite o novo diretório: ")
        os.chdir(new_dir)
    except Exception as error:
        print('Erro ao mudar de diretório: ', error)

def make_directory():
    try:
        new_dir_name = input("Digite o nome do novo diretório: ")
        os.makedirs(new_dir_name)
    except Exception as error:
        print('Erro ao criar diretório: ', error)
        
def remove(target=None):
    try:
        if target is None:
            target = input()
            #target = input("Digite o nome do diretório ou arquivo a ser removido: ")
            if os.path.isdir(target):
                if get_operating_system() == "Windows":
                    os.rmdir(target) # Use para remover diretórios no Windows
                else:
                    os.system(f"rm -r {target}") # Use para remover diretórios Linux
            elif os.path.isfile(target):
                os.remove(target)
            else:
                print("Alvo não encontrado.")
    except Exception as error:
        print('Erro ao remover: ', error)
            
def print_working_directory():
    def print_path():
        try:
            # Uma versão anterior eu fazia assim
            #if os.name == 'posix':
            #    _ = os.popen("pwd").read().strip()
            #elif os.name == 'nt':
            #    _ = os.popen("cd").read().strip()
            #else:
            #    print("Não consegui ver caminho.")
            path = os.getcwd()
        except Exception as error:
            path = 'Erro ao tentar mostrar o caminho: ' + str(error)
        return path
    pwd = print_path()
    print('''
          Path
          ----
          {}
          '''.format(pwd))
    #def touch():
#    try:
#        print()
#    except Exception

def touch():
    try:
        if os.name == 'posix':
            newFile = input("Nome do arquivo: ")
            os.system('touch {}'.format(newFile))
        elif os.name == 'nt':
            newFile = input("Nome do arquivo: ")
            os.system('type null > {}'.format(newFile))
    except Exception as error:
        print('Error ao tentar criar um arquivo: ' + str(error))

def top():
    try:
        def top_with_timeout(timeout):
            top_thread = threading.Thread(target=top)
            top_thread.start()
            top_thread.join(timeout)
            
            if top_thread.is_alive():
                print('A execução do top excedeu o tempo limite e será interrompida.')
                # Aqui você pode tentar encerrar a execução do processo top, mas tenha cuidado
                # pois interromper processos pode causar problemas.
                # Consulte a documentação do sistema operacional para fazer isso corretamente.
                # Exemplo (somente Linux): os.system('pkill top')
                
        if os.name == 'posix':
            os.system('top')
            print('A execução do top excedeu o tempo limite e será interrompida.')
        elif os.name == 'nt':
            os.system('qprocess')
            print('A execução do top excedeu o tempo limite e será interrompida.')
        else:
            print('Não foi possível listar o desempenho do sistema.')
            if os.system == 'nt':
                os
    except Exception as error:
        print('Erro ao tentar listar o desempenho do sistema:', error)

def ps():
    try:
        if os.name == 'posix':
            os.system('ps aux')
        elif os.name == 'nt':
            os.system('tasklist')
        else:
            print('Não foi possível listar os processos.')
    except Exception as error:
        print('Erro ao tentar listar os processos:', error)
    
    
def show_help():
    print('''Shell Zero é um projeto de linha de comando baseado em em sistemas unix e podendo ser utilizado para windows também
          
          Comandos:

            clear     -     Limpa o terminal
            ls        -     Lista diretórios
            cd        -     Se move entre os diretórios
            mkdir     -     Cria diretórios
            rm        -     Remove diretórios
            pwd       -     Mostra o caminho atual
            top       -     Lista processos
            ps        -     Lista os processos ativos do sistema
            exit      -     Sai da sessão atual
            hello     -     Imprime uma mensagem de Zer0 ;)
          
          ''')

def say_hello():
    print("Olá! Bem-vindo ao Shell Zero.")