import pyttsx3

enginee =  pyttsx3.init()

name = input("say smthg: ")

enginee.say(f"Hello, {name}")
engine.runAndwait()