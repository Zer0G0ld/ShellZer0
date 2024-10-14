import subprocess
import threading
import time
import os
from platformSys import get_operating_system

# Criei esse arquivo para guardar os parâmetros do comando 'ps'
# como o comando 'ps aux' ou 'ps -U username'

def ps_help():
    system = get_operating_system
    
    if system == 'Windows':
        os.system()