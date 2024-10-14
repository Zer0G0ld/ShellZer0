import platform

def informOperating():
    machine = platform.machine()
    architecture = platform.architecture()
    processor = platform.processor()
    network = platform.node()
    

def get_operating_system():
    return platform.system()