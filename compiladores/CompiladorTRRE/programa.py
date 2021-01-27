from PIL import Image
import sys
import numpy as np
entrada = "cdmx.jpg"
 
try:
	img0 = Image.open(entrada)
except:
	print("no se puedo cargar la imagen")
	sys.exit(1)
tam = (1000, 1000)
img = img0.copy()
img.thumbnail(tam)
img1 = img.copy()
i=0
while i < img1.size[0]:
	j = 0
	while j< img1.size[1]:
		r, g, b = img1.getpixel((i,j))
		gris = (r + g + b) / 3
		if gris < 140:
			img1.putpixel((i,j),(0,0,0))
		else:
			img1.putpixel((i,j),(255,255,255))
		j+=1
	i+=1
salida = ""
 
if len(salida)==0:
	img1.save("trre.jpg", "JPEG")
else:
	salida = salida + "/tree.jpg"
	img1.save(salida, "JPEG")
