import random as rd
import time 

def _mean(lista):
	mean = sum(lista)/float(len(lista))
	return mean

def median(lista):
	ol = sorted(lista)
	t = len(ol)

	if t % 2 == 0:
		median = (ol[int(t/2)]+ol[int(t/2)-1])/2
	elif t % 2 == 1:
		median = ol[int(t/2)+0.5]

	return median

def percent_(oc, total):
	percent = (oc*100)/total
	aux = round(percent, 2)
	return aux

def mode(lista):
	glossary = {}
	for x in lista:
		if(x not in glossary):
			glossary[x] = 1
		else:
			glossary[x] +=1

	count = max(glossary.values())

	for i in glossary:
		if(glossary[i] == count): return i

def simulacion():
	i = 0
	clientes = [] 		 
	TC = []				 #TEMPO DE CHEGADA
	TE = []				 #TEMPO DE ESPERA
	T_IN = []			 #TEMPO DE INICIO DO ATENDIMENTO
	TSER = []			 #TEMPO DE SERVIÇO cx1
	TOCIO = []  		 #TEMPO OCIOSO
	T_OUT = []		     #TEMPO DE SAIDA

					 #auxiliares para tratar valores de tempo fisico
	tc = []
	te = []
	t_in = []  		 
	tser = []  		 
	tocio = []
	t_out = []

	NUM_CLIENTES = int(input("Entre com o número de clientes para o evento: "))

	while(i < NUM_CLIENTES):
		if(i==0):	#condição para o primeiro cliente
			clientes.append(i) 
			TC.append(i) 		
			TE.append(i)		
			T_IN.append(i)		
			TSER.append(rd.uniform(3, 12))
			TOCIO.append(i)			 
			T_OUT.append(TC[i]+TE[i]+TSER[i])
		if(i>=1):	#clientes que chegaram depois
			clientes.append(i) 				    					
			TC.append(TC[i-1]+rd.uniform(4, 10)) 							
			TE.append(max(T_OUT[i-1], TC[i])-TC[i])					
			if(TC[i]>T_OUT[i-1]):									
				T_IN.append(TC[i])									
			else: 																	
				T_IN.append(T_OUT[i-1])								
			TSER.append(rd.uniform(3, 12))								
			TOCIO.append(max(T_OUT[i-1], TC[i])-T_OUT[i-1])			  
			T_OUT.append(TC[i]+TE[i]+TSER[i])						
		i+=1
	

	for x in range(NUM_CLIENTES):
		tc.append(round(TC[x], 2))
		te.append(round(TE[x], 2))
		t_in.append(round(T_IN[x], 2))  		 
		tser.append(round(TSER[x], 2))  		 
		tocio.append(round(TOCIO[x], 2))
		t_out.append(round(T_OUT[x], 2))
	
	print('\n')
	for x in range(NUM_CLIENTES):
		# time.sleep(rd.randrange(1, 4, 1))
		print("\t| ID: "+str(clientes[x])+
			  "\t| tp_C: "+str(tc[x])+
			  "\t| Fila: "+str(te[x])+
			  "\t| In(atd): "+str(t_in[x])+
			  "\t| Serv: "+str(tser[x])+
			  "\t| Oc(caixa): "+str(tocio[x])+
			  "\t| Out: "+str(t_out[x]))
		print('\n')

	format_es = [] 										#gera formato .1f para espera na fila
	for x in range(NUM_CLIENTES):
		format_es.append(round(TE[x], 1))  
	
	count = 0
	count_max = 0
	compare = mode(format_es)							#gera modal pra tempo de espera na fila
	med_comp = _mean(TE)								#gera o tempo médio de espera na fila

	for x in range(NUM_CLIENTES):			
		if(compare == format_es[x]):					
			count+=1   									#soma o total de clientes que tiveram o mesmo tempo de fila
		if(format_es[x] > med_comp):
			count_max+=1    							#verifica os clientes com tempo de fila acima da media

	format_serv = []								   #gera forma .1f pro tempo de serviço 
	for x in range(NUM_CLIENTES):						
		format_serv.append(round(TSER[x], 1))	
	if(NUM_CLIENTES %2 == 0):
		med_queue = median(format_es)	
		med_service = median(format_serv)
	
	atl = 0										
	for x in range(NUM_CLIENTES):					   #recolhendo o maior tempo de serviço entre os eventos
		if(TSER[x] > atl):
			atl = TSER[x]							   #atribuindo o maior tempo 
		else:
			atl = atl
	tmp = 0
	for x in range(NUM_CLIENTES):					   #somando o total de atividade do caixa
		if(TOCIO[x] == 0.0 or TOCIO[x] == 0):
			tmp +=1

	perct = percent_(sum(TOCIO), T_OUT[NUM_CLIENTES-1]) #gera a porcentagem de ociosidade
	service = 100-perct									#gera a porcentagem de tempo trabalhado 
	
	print("\n\n")
	print("\n*****************_OCIOSIDADE DO CAIXA_*****************")
	print("Ociosidade total do caixa:", sum(TOCIO))
	print("Porcentagem da ociosidade do caixa:", perct,"%")
	print("O caixa estava livre durante:", NUM_CLIENTES-tmp,"vezes")
	print("Taxa de ocupação",service,"%")

	print("\n*****************_DADOS DA FILA_*****************")
	print("Soma total da fila de espera:", sum(TE))
	print("Média da espera:", _mean(TE))	
	if(NUM_CLIENTES %2 == 0):
		print("Mediana da espera na fila:", med_queue)
	
	print("A moda(Índice de maior ocorrência) na fila de espera:", mode(format_es), "do vetor",format_es)
	print("Totalizando", count, "clientes com o tempo", compare)
	print("E", count_max, "esperaram acima da média", _mean(TE))

	print("\n*****************_DADOS DO SERVIÇOS_*****************")
	print("Media do tempo de serviço:", _mean(TSER))
	print("A moda(Índice de maior ocorrência) durante os serviços:", mode(format_serv), "do vetor",format_serv)
	if(NUM_CLIENTES %2 == 0):		
		print("Mediana tempo serviço:",med_service)
	print("Atendimento mais demorado entre os serviços:", atl)

	print("\n*****************_TEMPOS TOTALIZADOS_*****************")
	print("Tempo total do evento:", T_OUT[NUM_CLIENTES-1])
	print("Tempo total serviço:", sum(TSER))
	print("Tempo total da fila de espera:", sum(TE))

	print("\n\n")

inicio = time.time()
simulacion()
fim = time.time()
print('tempo total da simulação:', fim-inicio)
