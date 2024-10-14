import platform

def informOperating():
    system = platform
    machine = platform.machine()
    architecture = platform.architecture()
    processor = platform.processor()
    network = platform.node()
    
    if system == "Windows":
        print("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
        print(f"Sistema operacional: Windows \nTipo de maquina: {machine} \nTipo de arquitetura: {architecture} \nTipo de processador: {processor} \nNome do sistema da internet: {network}")
        print(
            "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
    elif system == "Linux":
        print("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
        print(f"Sistema operacional: Linux \nTipo de maquina: {machine} \nTipo de arquitetura: {architecture} \nTipo de processador: {processor} \nNome do sistema da internet: {network}")
        print("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
    elif system == "Darwin":
        print("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
        print(f"Sistema operacional: macOS \nTipo de maquina: {machine} \nTipo de arquitetura: {architecture} \nTipo de processador: {processor} \nNome do sistema da internet: {network}")
        print("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
    else:
        print("Sistema operacional não reconhecido.")


def get_operating_system():
    return platform.system()