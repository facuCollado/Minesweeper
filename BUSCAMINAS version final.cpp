#include<iostream>
#include<stdlib.h>
#include<conio.h>//funcion getch
#include<time.h>//num aleatorio matriz



using namespace std;
void muestra_primero(int matriz_chars[][10],int y,int x,char sim,char sim2);//MOSTRAR AL PLAYER SIN MODIFICAR NADA
void carga_contenido(int matriz_valores[][10],char sim2);
void muestra_jugada(int matriz_chars[][10],int matriz_valores[][10],int parx,int pary);
void bombas_alrededor(int matriz_valores[][10], int parx, int pary);
void perder(int matriz_valores[][10], int parx, int pary);
void ganar(int matriz_chars[][10],char sim,char sim2);
main(){
	system ("COLOR F4");
	int opcion,columna=0,cuadro[5][5],matrizjug[10][10],matriz_valores[10][10];
	int matriz_chars[10][10], caracter=219, caracter2=196;
	char sim=caracter;
	char sim2=caracter2;
	int parx=0,pary=0;
	int bombas25=25, bombascuadro=0;
	
	//************************************CONTADORES************************************
	int q,w,e;
	
	srand(time(NULL));
	
	
	cout<<"*******************************************************************************"<<endl;
	cout<<endl;
	cout<<"\t""\t""BIENVENIDO AL JUEGO DEL BUSCAMINAS"<<endl;
	cout<<"\t""\t""ELIJA LA OPCION QUE DESEA REALIZAR"<<endl;
	cout<<"\t""\t""RECOMENDAMOS QUE PRIMERO LEA LAS REGLAS ANTES DE JUGAR"<<endl<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<endl;
	srand(time(NULL));
	do{
	cout<<endl;
	cout<<"***************************************************"<<endl;
	cout<<"1. REGLAS"<<endl;
	cout<<"2. Jugar en un tablero de 10x10         25 BOMBAS"<<endl;
	cout<<"3. SALIR"<<endl;	
	cout<<"***************************************************"<<endl;																					
	do {
				
  				opcion=getch();
    			
    			
 			 } while (opcion<'1' or opcion>'3');
			  putchar(opcion);
 			 opcion=opcion-48;	//CONVERSION DE ASCII A INT
	
		switch(opcion){
			case 1:
				cout<<endl;
				cout<<endl;
	cout<<"\t""\t""USTED TENDRA UN TABLERO PARECIDO AL QUE ESTA EN PANTALLA"<<endl;	
	cout<<"\t""\t""\t""EN DONDE TENDRA QUE COLOCAR DOS COORDENADAS"<<endl;

	
			
		for(q=0; q<5; q++){
		cout<<"  "<<"|C"<<q<<"|"<<"";
		}
	
		cout<<endl;
		
		for(w=0; w<5; w++){
		cout<<"|F"<<columna<<"|"<<" ";
			for(e=0; e<5; e++){
				
			cuadro[w][e]=0;//fila x columna i
			cout<<cuadro[w][e]<<"     ";
			
		}
		columna++;
		cout<<endl;
		cout<<"-------------------------------"<<endl;
	}
	cout<<endl<<endl;
		cout<<"-El juego consiste en despejar todas las casillas de una pantalla que no oculten una mina."<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"-Algunas casillas tienen un numero, este numero indica las minas que suman todas las casillas circundantes."<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"-Asi, si una casilla tiene el numero 3, significa que de las ocho casillas que     hay alrededor"<<endl;
		cout<<"(si no es en una esquina o borde) hay 3 con minas y 5 sin minas. "<<endl; 
		cout<<endl;
		cout<<endl;
		cout<<"-Si se descubre una casilla sin numero indica que ninguna de las casillas       vecinas tiene mina y estas se descubren automáticamente."<<endl;
		cout<<endl;
		cout<<endl;	 
	break;
	
	
	case 2:
	
			muestra_primero(matriz_chars,0,0,sim,sim2);//VOID MOSTRAR AL JUGADOR 		//	0,0 INDICA EL TAMAÑO DEL ARRAY.
			carga_contenido(matriz_valores,sim2); //carga bombas y no bombas
			 bombas_alrededor(matriz_valores, parx, pary);		//analiza las bombas 							
		do{
			
			cout<<"FILA: ";
			do {
				
  				parx=getch();
    			
    			
 			 } while (parx<'0' or parx>'9');
 			 putchar(parx);
 			 parx=parx-48;	//CONVERSION DE ASCII A INT
			cout<<endl;
			
			cout<<"COLUMNA: ";
			do {
				
  				pary=getch();
    			
    			
 			 } while (pary<'0' or pary>'9');
 			 putchar(pary);
 			 pary=pary-48;
			  
			  			
			muestra_jugada(matriz_chars,matriz_valores,parx,pary); //lo que va viendo el jugadro a medida que juega
			ganar(matriz_chars, sim, sim2);
			perder(matriz_valores,parx,pary);
		}while(matriz_valores[parx][pary]!= -1 or bombas25==bombascuadro);
		cout<<"HAS PERDIDO"<<endl;
}//switch
	}while(opcion != 3);

}//main
	
void muestra_primero(int matriz_chars[][10],int y,int x,char sim,char sim2)
{
	int cl,w,e;
	int fila=0;
		
		for(w=0; w<10; w++){
			for(e=0; e<10; e++){			//lleno la matriz con 10 pq nunca va tocar ese numero
			matriz_chars[w][e]=10;			//en las bombas
			}
		}//for w matriz_chars
		cout<<sim2<<sim2<<sim2<<sim2<<sim2;			//SIMBOLOS PARA PONER SIMETRICAMENTE EL CUADR
	for(cl=0; cl<10; cl++){
		cout<<sim2;
		cout<<"|C"<<cl<<"|";				//MUESTRA LA PANTALLA QUE VA VER EL JUGADOR CON LOS CHARS
		}
		cout<<endl;
		for(w=0; w<10; w++){
		cout<<"|F"<<fila<<"|"<<" ";
			for(e=0; e<10; e++){
				if(matriz_chars[w][e]==10){
					cout<<"  ";
					cout<<sim <<"  ";
				}		
		}
		fila++;
		cout<<endl;
		cout<<"-------------------------------------------------------"<<endl;
	}
}//void
void carga_contenido(int matriz_valores[][10],char sim2){
	int q,w,e, aux;
	int bomba=15;
	char bomb=bomba;
	int columna=0, contBombas=0;
		for(w=0; w<10; w++){
			for(e=0; e<10; e++){
				matriz_valores[w][e]=0;
	} //for e
	}// for w
	
	
		for(w=0; w<5; w++){
			for(e=0; e<10; e++){						//CARGA LOS VALORES DE LA MATRIZ
			aux=rand()%2 - 1;
				if(aux== (-1)){
					matriz_valores[w][e]=aux;
					contBombas++;
				}//if 
				if(contBombas==13){
					e=5; w=5;
				break;
				}	
			}
		}//for w
		for(w=5; w<10; w++){
			for(e=0; e<10; e++){
				aux=rand()%2 - 1;
				if(aux==(-1)){
					matriz_valores[w][e]=aux;
					matriz_valores[w][e];
					contBombas++;
				}//if 
				if(contBombas==25){
					e=10; w=10;
				break;
				}
			}
		}

	cout<<"BOMBAS "<<contBombas<<endl;
		
}//VOID

void muestra_jugada(int matriz_chars[][10],int matriz_valores[][10],int parx,int pary)
{
	int	caracter=219, caracter2=196;
	char sim=caracter;
	char sim2=caracter2;
	int cl,w,e;
	int fila=0;
	int bomba=15;
	char bomb=bomba;
	
		system("cls");
		
		cout<<sim2<<sim2<<sim2<<sim2<<sim2;  	 //SIMBOLOS PARA PONER SIMETRICAMENTE EL CUADRo
		
	for(cl=0; cl<10; cl++){
		cout<<sim2;
		cout<<"|C"<<cl<<"|";
		}
		cout<<endl;
		
		for(w=0; w<10; w++){
		cout<<"|F"<<fila<<"|"<<" ";
			for(e=0; e<10; e++){
				if(w==parx and e==pary){
					matriz_chars[w][e]=matriz_valores[w][e];	//le cambio el valor de 10, por el numero de 
				}												//el lugar seleccionado
				if(matriz_chars[w][e]==10)
				cout<<"  "<<sim<<"  ";	
				
				else if(matriz_chars[w][e]==-1)
				cout<<"  "<<bomb<<"  ";			
						
				else if(matriz_chars[w][e]!=10)
				cout<<"  "<<matriz_chars[w][e]<<"  ";	//aca muestro la casilla seleccionada y las ya seleccionadas anteriormente
			
				
		}//for e
		fila++;
		cout<<endl;
		cout<<"-------------------------------------------------------"<<endl;
	}//for w
	
}//void
 
 void bombas_alrededor(int matriz_valores[][10], int parx, int pary){
	int f,c,contbomba;
	int	caracter=219, caracter2=196;
	char sim=caracter;
	char sim2=caracter2;
	int bomba=15;
	char bomb=bomba;
	int cl, w ,e, fila=0;
		for(f=0;f<10;f++){
		for(c=0;c<10;c++){
contbomba=0;

		if(matriz_valores[f][c]!=(-1)){
		
			if(f==0 and c==0)	//IZQ ARRIBA (ESQUINA)
				{
					if(matriz_valores[f][c+1]==(-1)){
						contbomba++;
					}
							if(matriz_valores[f+1][c]==(-1)){
								contbomba++;
					}
									if(matriz_valores[f+1][c+1]==(-1)){
										contbomba++;
					}
													matriz_valores[f][c]=contbomba;
															contbomba=0;
			    	}
	
					else if(f==0 and c==9)	//DERECHA ARRIBA(ESQ)
				{
							if(matriz_valores[f][c-1]==(-1)){
								contbomba++;
					}
									if(matriz_valores[f+1][c]==(-1)){
										contbomba++;
					}
											if(matriz_valores[f+1][c-1]==(-1)){
												contbomba++;
					}
												matriz_valores[f][c]=contbomba;
												contbomba=0;
			    	}
			
				else if(f==9 and c==0)	//IZQUIERDA ABAJO
				{
					if(matriz_valores[f-1][c]==(-1)){
						contbomba++;
					}
							if(matriz_valores[f-1][c+1]==(-1)){
							contbomba++;
					}
								if(matriz_valores[f][c+1]==(-1)){
								contbomba++;
					}
									matriz_valores[f][c]=contbomba;
									contbomba=0;
				    }
			
			
			else if(f==9 and c==9)	//IZQUIERDA ABAJO(ESQUINA)
				{
					if(matriz_valores[f-1][c]==(-1)){
						contbomba++;
					}
						if(matriz_valores[f-1][c-1]==(-1)){
						contbomba++;
					}
							if(matriz_valores[f][c-1]==(-1)){
							contbomba++;
					}
								matriz_valores[f][c]=contbomba;
									contbomba=0;
			    	}
			
				else if(f==0 and c>0 and c<9)	//FILA ARRRIBA
				{
					if(matriz_valores[f][c-1]==(-1)){
					contbomba++;
					}
						if(matriz_valores[f+1][c-1]==(-1)){
						contbomba++;
					}
							if(matriz_valores[f+1][c]==(-1)){
							contbomba++;
					}
								if(matriz_valores[f+1][c+1]==(-1)){
								contbomba++;
					}
									if(matriz_valores[f][c+1]==(-1)){
									contbomba++;
					}										
									matriz_valores[f][c]=contbomba;
									contbomba=0;
				}
				
				else if(c==0 and f>0 and f<9)	//COLUMNA IZQUIERDA
				{
								if(matriz_valores[f-1][c]==(-1)){
								contbomba++;
					}
									if(matriz_valores[f-1][c+1]==(-1)){
									contbomba++;
					}
										if(matriz_valores[f][c+1]==(-1)){
										contbomba++;
					}
											if(matriz_valores[f+1][c]==(-1)){
											contbomba++;
					}
												if(matriz_valores[f+1][c+1]==(-1)){
												contbomba++;
					}										
													matriz_valores[f][c]=contbomba;
													contbomba=0;
			    	}
				
				else if(f==9 and c>0 and c<9)	//fila abajo
				{
					if(matriz_valores[f][c-1]==(-1)){
						contbomba++;
					}
						if(matriz_valores[f-1][c-1]==(-1)){
						contbomba++;
					}
							if(matriz_valores[f-1][c]==(-1)){
							contbomba++;
					}
								if(matriz_valores[f-1][c+1]==(-1)){
								contbomba++;
					}
									if(matriz_valores[f][c+1]==(-1)){
									contbomba++;
					}										
										matriz_valores[f][c]=contbomba;
										contbomba=0;
				    }
			
			else if(c==9 and f>0 and f<9)	//columna derecha final
				{
					if(matriz_valores[f-1][c]==(-1)){
						contbomba++;
					}
						if(matriz_valores[f-1][c-1]==(-1)){
						contbomba++;
					}
							if(matriz_valores[f][c-1]==(-1)){
								contbomba++;
					}
								if(matriz_valores[f+1][c-1]==(-1)){
									contbomba++;
					}
									if(matriz_valores[f+1][c]==(-1)){
										contbomba++;
					}										
												matriz_valores[f][c]=contbomba;
												contbomba=0;
			     	}//else if
			
	//******************************** BORDES NORMALES************************************				
			
	else	//EL RESTO
				{	
					if(matriz_valores[f-1][c-1]==(-1)){
						contbomba++;
					}
						if(matriz_valores[f-1][c]==(-1)){
							contbomba++;
					}
							if(matriz_valores[f-1][c+1]==(-1)){
								contbomba++;
					}
								if(matriz_valores[f][c-1]==(-1)){
									contbomba++;
					}
									if(matriz_valores[f][c+1]==(-1)){
										contbomba++;
					}
										if(matriz_valores[f+1][c-1]==(-1)){
											contbomba++;
					}	
												if(matriz_valores[f+1][c]==(-1)){
												contbomba++;
					}	
														if(matriz_valores[f+1][c+1]==(-1)){
															contbomba++;
					}															
																matriz_valores[f][c]=contbomba;
																contbomba=0;
				    }// else resto
		
	
}//if matriz_valores
}//fo c segundo
}//for f primero
	/*	if(matriz_valores[parx][pary]== -1){
		
			system("cls");
cout<<"*****     RESUELTO     *****"<<endl<<endl<<endl;

	cout<<sim2<<sim2<<sim2<<sim2<<sim2;			//SIMBOLOS PARA PONER SIMETRICAMENTE EL CUADR
	for(cl=0; cl<10; cl++){
		cout<<sim2;
		cout<<"|C"<<cl<<"|";				//MUESTRA LA PANTALLA QUE VA VER EL JUGADOR
		}
		cout<<endl;
		for(w=0; w<10; w++){
		cout<<"|F"<<fila<<"|"<<" ";
			for(e=0; e<10; e++){
				cout<<"  ";
				if(matriz_valores[w][e]== -1)
				cout<<bomb<<"  ";
				else{
					cout<<matriz_valores[w][e]<<"  ";
				}
					
		}
		fila++;
		cout<<endl;
		cout<<"-------------------------------------------------------"<<endl;
	}//for w
		}//if*/
	
}//void



void perder(int matriz_valores[][10], int parx, int pary){
		int f,c,contbomba;
	int	caracter=219, caracter2=196;
	char sim=caracter;
	char sim2=caracter2;
	int bomba=15;
	char bomb=bomba;
	int cl, w ,e, fila=0;
	
	
	if(matriz_valores[parx][pary]== -1){
		system("cls");
cout<<"*****     RESUELTO     *****"<<endl<<endl<<endl;

	cout<<sim2<<sim2<<sim2<<sim2<<sim2;			//SIMBOLOS PARA PONER SIMETRICAMENTE EL CUADR
	for(cl=0; cl<10; cl++){
		cout<<sim2;
		cout<<"|C"<<cl<<"|";				//MUESTRA LA PANTALLA QUE VA VER EL JUGADOR CON EL RESULTADO
		}
		cout<<endl;
		for(w=0; w<10; w++){
		cout<<"|F"<<fila<<"|"<<" ";
			for(e=0; e<10; e++){
				cout<<"  ";
				if(matriz_valores[w][e]== -1)
				cout<<bomb<<"  ";
				else{
					cout<<matriz_valores[w][e]<<"  ";
				}
					
		}
		fila++;
		cout<<endl;
		cout<<"-------------------------------------------------------"<<endl;
	}//for w
	}//IF

}//void perder
void ganar(int matriz_chars[][10], char sim,char sim2){
 	int bombas25=25, bombascuadro;
 	int y, x;
 		bombascuadro=0;
	 for(x=0; x<10; x++){
	
 		for(y=0;y<10; y++){
 			if(matriz_chars[x][y]==10)
 			bombascuadro++;
		 }
	}
 	if(bombascuadro==bombas25){
 			 cout<<"HAS GANADO"<<endl;
	 exit(0);
	 }

}


























