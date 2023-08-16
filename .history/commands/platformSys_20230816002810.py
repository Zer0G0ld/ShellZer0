import platform

def get_operating_system():
    machine = platform.machine()
    architecture = platform.architecture()
    processor = platform.processor()
    network = platform.node()
    return platform.system()