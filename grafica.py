import numpy as np
import matplotlib.pyplot as plt

data=np.loadtxt("datos.txt")
y=np.exp(-data[:,0])
data[:,1]=(np.abs( data[:,1]-y ) )*100 / y
plt.scatter(data[:,0],data[:,1], label="diference")
plt.ylabel("porcentaje de error")
plt.xlabel("x")
plt.legend()
plt.savefig("grafica1.png")

plt.clf()

data=np.loadtxt("datos2.txt")
y=np.cos(data[:,0])
e=(np.abs( data[:,1]-y ) ) 
plt.scatter(data[:,0],e, label="diference")
plt.ylabel("porcentaje de error")
plt.xlabel("x")
plt.legend()
plt.savefig("grafica2.png")

plt.clf()

plt.scatter(data[:,2],data[:,1], label="y vs z")
plt.ylabel("y")
plt.xlabel("z")
plt.legend()
plt.savefig("grafica3.png")

plt.clf()

plt.scatter(data[:,0],data[:,1], label="y vs x")
plt.ylabel("y")
plt.xlabel("x")
plt.legend()
plt.savefig("grafica4.png")
