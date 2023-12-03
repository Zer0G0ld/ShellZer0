import subprocess

def run_ls(args):
    return subprocess.run(["ls"] + args, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True).stdout

def run_mkdir(args):
    return subprocess.run(["mkdir"] + args, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True).stdout

# Mapeamento de comandos para funções
command_functions = {
    "ls": run_ls,
    "mkdir": run_mkdir,
    # Adicione mais comandos conforme necessário
}

def run_command(command):
    try:
        # Divide o comando em partes
        parts = command.split()

        # Obtém o comando e os argumentos
        cmd, args = parts[0], parts[1:]

        # Executa a função associada ao comando, se existir
        if cmd in command_functions:
            result = command_functions[cmd](args)
        else:
            # Se não houver uma função associada, use subprocess
            result = subprocess.run(command.split(), stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True).stdout

        return result
    except Exception as e:
        return str(e)

# Resto do código permanece o mesmo...

