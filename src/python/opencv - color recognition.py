import cv2
import time
import os
import serial
import numpy as np
#import urllib.request
#Definicion de rangos bajos y altos de colores
#x[0] = bajo, x[1] = alto
data = open("/home/mosty/data.txt", "r")
lastseen = data.read()
COM = "/dev/ttyUSB0"
BAUD = 115200
ser = serial.Serial(COM, BAUD)

if "1" in lastseen:
    #Rojo, esto se activa al principio de la ronda si encuentra rojo
    print("el ultimo color que vi fue rojo")
    ser.write(b"der\n")
if "2" in lastseen:
    print("el ultimo color que vi fue verde")
    #Verde, se activa si es verde
    ser.write(b"izq\n")
data.close()



red1 = [(0, 200, 100), (8, 255, 255)]
red2 = [(355, 83, 93), (360, 93, 93)]
green = [(55, 250, 20), (75, 255, 255)]
cap=cv2.VideoCapture(0)
ret,frame=cap.read()
height, width = frame.shape[:2]
print(f"resolucion: {width}x{height}")


#Procesar una nueva imagen
def newImg(framecount, height, width):
    time.sleep(0.025)
    data = 0
    #print("new loop")
    #Toma un frame dependiendo de imgnum debajo de la carpeta frames
    ret,frame=cap.read()
    middle1 = int(height/2-20)
    middle2 = int(height/2+20)
    frame = frame[middle1:middle2,:]
    frame = cv2.flip(frame, 2)
    #img = cv2.flip(frame, -1)


    #convierte la imagen de HSL a HSV
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    #Detecta si los colores de la imagen coinciden con los rangos definidos
    redMask1 = cv2.inRange(hsv, red1[0], red1[1])
    redMask2 = cv2.inRange(hsv, red2[0], red2[1])
    greenMask = cv2.inRange(hsv, green[0], green[1])
    #Mezcla redMask1 y redMask2
    redMask = cv2.bitwise_or(redMask1, redMask2)
    #No se que hace esto.
    #Compara la misma imagen entre si pero en la segunda se le alplica la mascara para que solo la zona con la mascara aparezca
    if redMask.max():
        print("rojo encontrado")
        ser.write(b"der\n")
        if framecount >= 40:
            data = 1
            framecount = 0
        
    if greenMask.max():
        print("verde encontrado")
        ser.write(b"izq\n")
        if framecount >= 40:
            data = 2
            framecount = 0
    #Crea una pestana con los frames siendo vistos
    cv2.imshow("cpapu", frame)
    framecount += 1
    return framecount, data
#Main
framecount = 0
while True:
    #Procesa el siguiente frame
    framecount += 1
    framecount, data = newImg(framecount, height, width)
    if data:
        dataw = open("/home/mosty/data.txt", "w")
        dataw.write(str(data))
        dataw.close()
        print(f"written {data}")
    #Al presionar q sale del loop y continua a cerrar las ventanas
    key = cv2.waitKey(5)
    if key == ord('q'):
#        ser.close()
        break 
    if key == ord('r'):
        dataw = open("/home/mosty/data.txt", "w")
        dataw.write("")
        dataw.close()
        break
        
#Cierra todas las ventanas
cap.release()
cv2.destroyAllWindows()
