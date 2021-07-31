//metodo da regressão 

clc
clear 
n = input("Insira o número de termos");

for i=1:n
	x(i)=input("Valor de x:");
	y(i)=input("Valor de y:");
end
x0=0
y0=0
x2=0
y2=0
xy=0
for i=1:n
	x0 = x0+x(i)
	y0 = y0+y(i)
	x2 = x2+x(i)^2
	y2 = y2+y(i)^2
	xy = xy+x(i)*y(i)
end
bxy=(n*xy-x0*y0)/(n*y2-y0^2);
byx=(n*xy-x0*y0)/(n*x2-x0^2);
mprintf("bxy=%f\nbyx%f\n", bxy, byx);