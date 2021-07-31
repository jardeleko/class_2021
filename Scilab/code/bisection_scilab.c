//metodo da biseção
clc 
clear 

disp ("Entre com os valores de a, b, c, d, e para ax^4+bx^3+cx^2+dx+e=0");

a = input("valor de a:");
b = input("valor de b:");
c = input("valor de c:");
d = input("valor de d:");
e = input("valor de e:");

function y=fun (x)
	y=a*x.^4+b*x.^3+c*x.^2+d*x+e;
endfunction 

	p = input("Entre com a primeira aproximação inicial");
	q = input("Entre com a segunda aproximação inicial");

while(fun(p)*fun(q)>0)
	disp("Entre com intervalo correto da aproximação");
	p = input("Insira o primeiro valor da aproximação");
	p = input("Insira o segundo valor da aproximação");
end

p1 = [p:.1:q];
x = (p+q)/2;
i = 0;
z = 0;

while(abs(fun(x)) > 0.0000001)
	x = (p+q)/2;
	if(fun(x)*fun(q)<0) then
		p = x;
	else 
		q = x;
	end
	i = i+1;
	mprintf('%d:−\tf(%f) = %f\n', i, x, fun(x));
end

mprintf("Solução da equação é %f", x);
plot(p1, fun(p1));


