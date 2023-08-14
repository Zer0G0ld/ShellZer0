import os
from commands import base
from platformSys import get_operating_system

# Usando o pycharm para editar use o pyinstaller para criar um executavel para usar no terminal como no terminal
# Use o comando : pyinstaller --onefile app.py --distpath C:\Users\mathe\PycharmProjects\shellzero\exe

def executeCommand(command):
    return base.executeCommand(command)

def whoami():
    return os.getlogin() if os.name == 'nt' else os.getenv('USER')

def get_user_input():
    def PathPwd():
        try:
            path = os.getcwd()
        except Exception as error:
            path = 'Erro ao tentar mostrar o caminho: ' + str(error)
        return path
    
    name = whoami()
    pwd_path = PathPwd()
    directories = pwd_path.split(os.path.sep)
    last_dir = directories[-1]
    second_dir = directories[-2] if len(directories) >= 2 else ''

    print("┌──(ShellZero㉿{})-[{}]".format(os.path.join(name), os.path.join(second_dir, last_dir)))
    return input("└─$ ")

# Mapeando comandos para funções
command_mapping = {
    "clear": base.clear_secreen,
    "ls": base.list_dir,
    "cd": base.change_directory,
    "mkdir": base.make_directory,
    "rm": base.remove,
    "pwd": base.print_working_directory,
    "help": base.show_help,
    "hello": base.say_hello
}

# Função principal
def main():
    while True:
        user_input = get_user_input()
        if user_input.lower() == "exit":
            break
        elif user_input.lower().startswith("rm "):
            _, target = user_input.split(" ", 1)
            base.remove(target=target)
        elif user_input.lower() == "cd ..":
            #erroEncontrado = "Erro ao retornar ao diretório anterior."
            try:
                os.chdir("..")
            except Exception as error:
                erroEncontrado = "Erro ao retornar ao diretório anterior: " + str(error)
            print(erroEncontrado)
        elif " " in user_input:
            command, argument = user_input.split(" ", 1)
            if command.lower() in command_mapping:
                command_function = command_mapping[command.lower()]
                command_function(argument)
            else:
                executeCommand(user_input)
        elif user_input.lower() in command_mapping:
            command_function = command_mapping[user_input.lower()]
            command_function()
        else:
            executeCommand(user_input)

if __name__ == "__main__":
    main()