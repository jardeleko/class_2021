//método lagrange 
ex
 // n=2

 // x= 1
 // y= 1
 // x= 6
 // y= 36
 //value de x calculate y
 // a=5
clc 
clear 
n = input("Insira o número de termos na tabela");

for i=1:n
	disp("Entre com os valores de x e y");
	disp("X: ");
	x(i)=mscanf("%f");
	disp("Y: ");
	y(i)=mscanf("%f");
end
an = 0;
a = input("Insira o valor de x para calcular y");
for i=1:n
	c=1;
	for j=1:n
		if(i~=j)
			c = c*(a-x(j))/(x(i)-x(j))
		end
	end
	an=an+c*y(i)
end
mprintf("\n\nF(%f)=%f\n", a, an);
