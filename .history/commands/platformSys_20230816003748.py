import platform

def informOperating():
    system = platform.system()
    machine = platform.machine()
    architecture = platform.architecture()
    processor = platform.processor()
    network = platform.node()
    
    if system == "Windows":
        print("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
        print(f"Sistem---------------------------------------")
    else:
        print("Sistema operacional não reconhecido.")

def get_operating_system():
    return platform.system()