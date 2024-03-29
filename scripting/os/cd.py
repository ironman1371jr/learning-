import os

print(os.getcwd())    # print the current working directory

os.chdir("D:\codes\scripting") # change to a new directory, if it exists 

def file_exists(filename):
    if os.path.exists(filename):
        print("file exists")
    else:
        print("does not exist")

file_exists("D:\codes\scripting")

def listall(directory):
    if  os.path.isdir(directory):
        filenames = os.listdir(directory)
        for file in filenames:
            print(file)
        print(os.listdir(directory))
    else:
        print("not a valid directory")

listall("D:\codes\scripting\os")# print the current working directory
