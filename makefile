grafica1.png grafica2.png:datos.txt datos2.txt
	python grafica.py
	rm datos.txt
	rm datos2.txt
datos.txt:
	c++ Range_Kutta.cpp -o x
	./x primera > datos.txt
	rm x
datos2.txt:
	c++ Range_Kutta.cpp -o x
	./x segunda > datos2.txt
	rm x
clean:
	rm *.png
