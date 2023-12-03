import os
import json

try:
    # Colocar módulos criados aqui dentro da try 
    import base
    from commands import *
except ImportError:
    # Se falhar, imprimir mensagem e criar um módulo base simulado
    print("Erro: Módulo não encontrado. Criando um móluo base simulado.")
    class BaseSimulado:
        @staticmethod
        def clear_screen():
            pass

        @staticmethod
        def list_dir():
            pass

        @staticmethod
        def change_directory():
            pass

        @staticmethod
        def make_directory():
            pass

        @staticmethod
        def remove():
            pass

        @staticmethod
        def print_working_directory():
            pass

        @staticmethod
        def ps():
            pass

        @staticmethod
        def show_help():
            pass

        @staticmethod
        def say_hello():
            pass

    base = BaseSimulado()

json_fileName = "mapping.json"

try:
    with open(json_fileName, 'r') as json_file:
        read_command_mapping = json.load(json_file)

        if isinstance(read_command_mapping, dict):
            print("Leitura bem-sucedida: ")
            print(read_command_mapping)
        else:
            print("Falha na leitura do JSON.")
except FileNotFoundError:
    print(f"Arquivo {json_fileName} não encontrado. Certifique-se de executar o script que cria o mapeamento primeiro.")
except json.JSONDecodeERROR:
    print(f"Falha ao decodificar o JSON no arquivo {json_fileName}. Certifique-se de que o conteúdo seja um JSON válido.")


def excuteCommand(command):
    return base.executeCommand(command)

def whoami():
    return os.getlogin() if os.name == 'nt' else os.getenv('USER')

def get_user_input():
    def PathPwd():
        try:
            path = os.getwcd()
            return path
        except Exception as Error:
            print("Erro ao tentar mostrar o caminho : " + str(Error))
            return None
        
    name = whoami()
    pwd_path = PathPwd()
    
    if pwd_path is not None:
        directories = pwd_path.split(os.path.sep)
        last_dir = directories[-1]
        second_dir = directories[-2] if len(directories) >= 2 else ''
    else:
        last_dir = ''
        second_dir = ''

    print("┌──(ShellZero㉿{})-[{}]".format(os.path.join(name), os.path.join(second_dir, last_dir), str(last_dir)) if pwd_path is not None else '')
    return input("└─$  ")

command_mapping = {
    "clear"
}

def main():
    while True:
        user_input = get_user_input()
        if user_input.lower() == "exit":
            break
        elif user_input.lower().startswith("rm "):
            _, target = user_input.split(" ", 1)
            base.remove(target=target)
        elif user_input.lower() == "cd ..":
            try:
                os.chdir("..")
            except Exception as Error:
                erroEncontrado = "Erro ao retornar ao diretório anterior: " + str(Error)
                return erroEncontrado
            
        elif " " in user_input:
            command, argument = user_input.split(" ", 1)
            if command.lower() in command_mapping:
                command_function = command_mapping[user_input.lower()]
                command_function()
            else:
                executeCommand(user_input)


if __name__ == '__main__':
    main()
