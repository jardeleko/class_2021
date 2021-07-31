//método da iteração

clc
clear 

function y = f(x)
	y = x^3-5*x+1

endfunction 

function y = fi(x)
	y = (x^3+1)/5
endfunction

a = input("Entre com a aproximação inicial");
mprintf("f(%f)=%f\n", a, f(a));
a = fi(a);

while(abs(f(a)) > .000001)
	mprintf("f(%f)=%f\n", a, f(a));
	a = fi(a);
end
mprintf("Solução da equação é %f", a);