import subprocess
import threading
import time
import os
import platformSys

# Criei esse arquivo para guardar os parâmetros do comando 'ps'
# como o comando 'ps aux' ou 'ps -U username'

system = platformSys
windows = system == 'Windows'
linux = system == 'Linux'
darwin = system == 'Darwin'

operacao = system

print()


        