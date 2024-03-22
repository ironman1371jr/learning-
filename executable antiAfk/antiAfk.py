import pyautogui as pag
import random
import time

while True:
    x = random.randint(1000,1500)
    y = random.randint(600,900)
    pag.moveTo(x,y,0.5) #0.5 is speed
    time.sleep(2.5)
    pag.moveTo(1300,700,0.3) #go to mid

