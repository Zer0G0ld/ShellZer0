import subprocess
import threading
import time
import os
import platformSys

# Criei esse arquivo para guardar os parâmetros do comando 'ps'
# como o comando 'ps aux' ou 'ps -U username'

system = platformSys.get_operating_system
windows = system == 'Windows'
linux = system == 'Linux'
darwin = system == 'Darwin'

operacao = platformSys.informOperating
window = operacao ==

print()


        