from Tkinter import *
import os
import time
import random
root = Tk()
matriz=[]
x=10
y=10
snake=0
score=0
snakex=[10]
snakey=[10]
comx=random.randrange(20)
comy=random.randrange(20)
borrax=[]
borray=[]
ultimo=""
miliseg=100
def come(cabeza):
    global comx
    global comy
    global snake
    global ultimo
    if matriz[x][y]=="$":
        snake+=1
        comx=random.randrange(20)
        comy=random.randrange(20)
        while matriz[comx][comy]=="O" or matriz[comx][comy]=="*":
            comx=random.randrange(20)
            comy=random.randrange(20)
    elif matriz[x][y]=="O" or matriz[x][y]=="*":
        ultimo="stop"
def tamanio(snake):
    global ultimo
    if ultimo=="left" or ultimo=="right" or ultimo=="up" or ultimo=="down":
        while len(snakey)>snake+2 or len(snakex)>snake+2:
            del snakex[0]
            del snakey[0]
def recuperando(snakex,snakey):
    global borrax
    global borray
    borrax=snakex[0]
    borray=snakey[0]
    matriz[borrax][borray]=" "
def fin(cabeza):
    global ultimo
    global snakex
    global snakey
    global snake
    global score
    if ultimo=="stop":
        del snakex[0]
        del snakey[0]
        snake=0
        score=1
def posicion(cabeza):
    global matriz
    global x
    global y
    global snakex
    global snakey
    global ultimo
    matriz[x][y]="O"
    if cabeza=="left":                        
        if x>-1:
            x-=1
            if x==-1:
                x=len(matriz)-1        	
                
    elif cabeza=="right":
        if x<len(matriz):
            x+=1
            if x==len(matriz):
                x=0
    elif cabeza=="up":
        if y>-1:
            y-=1
            if y==-1:
                y=len(matriz)-1
    elif cabeza=="down":
        if y<len(matriz[0]):
            y+=1
            if y==len(matriz[0]):
                y=0
    matriz[comx][comy]="$"
    snakex.append(x)
    snakey.append(y)

    tamanio(snake)    
    recuperando(snakex,snakey)
    
    
    come(cabeza)
    matriz[x][y]="O"
    fin(cabeza)        
def leftKey(event):
    global ultimo
    if ultimo!="right":
        posicion("left")
        ultimo="left"

def rightKey(event):
    global ultimo
    if ultimo!="left":
        posicion("right")      
        ultimo="right"

def upKey(event):
    global ultimo
    if ultimo!="down":
        posicion("up")
        ultimo="up"

def downKey(event):
    global ultimo
    if ultimo!="up":
        posicion("down")
        ultimo="down"

def printMat():
    global matriz
    global score
    for j in range(len(matriz[0])):
        c=""
        for i in range(len(matriz)):
            c+= str(matriz[i][j])
        print c
    print ""
    if score ==1:
        print "GAME OVER"
    score=snake*100
    print "SCORE: ",score


def task():
    clear = lambda: os.system('cls')
    clear()
    global ultimo
    global miliseg
    posicion(ultimo)
    printMat()
    root.after(miliseg, task)


for i in range(20):
    c=[]
    for j in range(20):
        c.append(" ")
    matriz.append(c)
matriz[10][10]="O"

        
    
frame = Frame(root, width=30, height=30)
root.bind('<Left>', leftKey)
root.bind('<Right>', rightKey)
root.bind('<Up>', upKey)
root.bind('<Down>', downKey)
frame.pack()

root.after(miliseg, task)
root.mainloop()

asgfaigfsgfnsdfsdf