//método newton raphson

clc 
clear 

disp ("Entre com os valores de a, b, c, d, e para ax^4+bx^3+cx^2+dx+e=0");

c = input("valor de a:");
d = input("valor de b:");
e = input("valor de c:");
f = input("valor de d:");
g = input("valor de e:");

function y=fun (x)
	y=c*x.^4+d*x.^3+e*x.^2+f*x+g;
endfunction 

x = input("valor inicial da aproximação");
y = x;
i = 0;

while(abs(fun(x))> .000001);
	i=i+1;
	mprintf('%d:-\tf(%f)=%f\n', i, x, fun(x));
	x = x-(fun(x)/numderivative(fun, x));
end

if(y < x) then 
	p = [y:.1:x+1];
else 
	p = [x:.1:y+1];
end
mprintf("Solução da equação é %f", x);
plot(p, fun(p), p, p*0);