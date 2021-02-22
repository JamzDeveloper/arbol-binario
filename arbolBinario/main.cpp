/* ARBOLES BINARIOS (lista enlazada bifurcada*/

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
FILE *fd; //file descriptor

struct encabezado
{
	int NRS;
	int RZ;
	int URE;
} e;
struct person
{
	int NR;
	char nombre[20];
	char celular[10];
	int PI;
	int PD;
	int ARE;

} r, s, reg_max_izq, auxAnt, auxMax, auxBusc, aux, auxAntBusc, auxSigbusc;

int lr = sizeof(struct person);
int le = sizeof(struct encabezado);
int pos = 0;

void insertar()
{
	char rpta, lado;
	int sgte;
	//utiliza comodin para actualizar o agregar
	if ((fd = fopen("personas.txt", "r+t")) != NULL)
	{

		fread(&e, le, 1, fd);
		cout << "NRS:" << e.NRS << "\t"
			 << "Raiz:" << e.RZ << "\tURE: " << e.URE << endl;

		do
		{
			fflush(stdin);
			r.NR = ++e.NRS;
			cout << "nombre" << endl;
			gets(r.nombre);
			fflush(stdin);
			cout << "celular" << endl;
			gets(r.celular);
			r.PI = -1;
			r.PD = -1;
			//ure
			r.ARE = 0;
			pos = (r.NR - 1) * lr + le;
			fseek(fd, pos, 0);
			fwrite(&r, lr, 1, fd);
			if (e.RZ == -1)
			{
				e.RZ = r.NR;
			}
			else
			{
				//algoritmo buscar al registro que apunta al nuevo
				sgte = e.RZ;
				while (sgte != -1)
				{
					pos = (sgte - 1) * lr + le;
					fseek(fd, pos, 0);
					fread(&s, lr, 1, fd);
					if (strcmp(r.nombre, s.nombre) > 0)
					{
						lado = 'd';
						sgte = s.PD;
						continue;
					}
					if (strcmp(r.nombre, s.nombre) < 0)
					{
						lado = 'i';
						sgte = s.PI;
						continue;
					}
				}
				//fin de algoritmo buscar
				if (lado == 'd')
				{
					s.PD = r.NR;
				}
				if (lado == 'i')
				{
					s.PI = r.NR;
				}
				fseek(fd, pos, 0);
				fwrite(&s, lr, 1, fd);
			}
			cout << "Desea guardar otro registro?" << endl;
			cin >> rpta;
		} while (rpta == 's' || rpta == 'S');
		fseek(fd, 0, 0);
		fwrite(&e, le, 1, fd);
		fclose(fd);
	}
	else
		cout << "no se pudo abrir el archivo" << endl;
}

void reInsertar(int nR, char nombre[20],char celular[20]){
	//CUANDO SE CAMBIAN LA CLAVE DE ALGUN NODO SE TIENE QUE VOLVER A INSERTAR
	L
char  lado;
	int sgte;
	if ((fd = fopen("personas.txt", "r+t")) != NULL)
	{

		fread(&e, le, 1, fd);
		cout << "NRS:" << e.NRS << "\t"
			 << "Raiz:" << e.RZ << "\tURE: " << e.URE << endl;

	
		
		//asignamos ubicacion de eliminado
			r.NR = nR;
			strcpy(r.nombre,nombre);

			fflush(stdin);
			
			strcpy(r.celular,celular);
			
			r.PI = -1;
			r.PD = -1;
			//ure
			r.ARE = 0;
			pos = (r.NR - 1) * lr + le;
			fseek(fd, pos, 0);
			fwrite(&r, lr, 1, fd);
			if (e.RZ == -1)
			{
				e.RZ = r.NR;
			}
			else
			{
				//algoritmo buscar al registro que apunta al nuevo
				sgte = e.RZ;
				while (sgte != -1)
				{
					pos = (sgte - 1) * lr + le;
					fseek(fd, pos, 0);
					fread(&s, lr, 1, fd);
					if (strcmp(r.nombre, s.nombre) > 0)
					{
						lado = 'd';
						sgte = s.PD;
						continue;
					}
					if (strcmp(r.nombre, s.nombre) < 0)
					{
						lado = 'i';
						sgte = s.PI;
						continue;
					}
				}
				//fin de algoritmo buscar
				if (lado == 'd')
				{
					s.PD = r.NR;
				}
				if (lado == 'i')
				{
					s.PI = r.NR;
				}
				fseek(fd, pos, 0);
				fwrite(&s, lr, 1, fd);
			}
			
		
		fseek(fd, 0, 0);
		fwrite(&e, le, 1, fd);
		fclose(fd);
	}
	else
		cout << "no se pudo abrir el archivo" << endl;
}

void escribir()
{
	char rpta, lado;
	int sgte;
	if ((fd = fopen("personas.txt", "w+t")) != NULL)
	{
		e.NRS = 0;
		e.RZ = -1;
		e.URE = -1;
		do
		{
			fflush(stdin);
			r.NR = ++e.NRS;
			cout << "nombre" << endl;
			gets(r.nombre);
			cout << "celular" << endl;
			gets(r.celular);
			r.PI = -1;
			r.PD = -1;
			//ure
			r.ARE = 0;
			pos = (r.NR - 1) * lr + le;
			fseek(fd, pos, 0);
			fwrite(&r, lr, 1, fd);
			if (e.RZ == -1)
			{
				e.RZ = r.NR;
			}
			else
			{
				//algoritmo buscar al registro que apunta al nuevo
				sgte = e.RZ;
				while (sgte != -1)
				{
					pos = (sgte - 1) * lr + le;
					fseek(fd, pos, 0);
					fread(&s, lr, 1, fd);
					if (strcmp(r.nombre, s.nombre) > 0)
					{
						lado = 'd';
						sgte = s.PD;
						continue;
					}
					if (strcmp(r.nombre, s.nombre) < 0)
					{
						lado = 'i';
						sgte = s.PI;
						continue;
					}
				}
				//fin de algoritmo buscar
				if (lado == 'd')
				{
					s.PD = r.NR;
				}
				if (lado == 'i')
				{
					s.PI = r.NR;
				}
				fseek(fd, pos, 0);
				fwrite(&s, lr, 1, fd);
			}
			cout << "Desea guardar otro registro?" << endl;
			cin >> rpta;
		} while (rpta == 's' || rpta == 'S');
		fseek(fd, 0, 0);
		fwrite(&e, le, 1, fd);
		fclose(fd);
	}
	else
		cout << "no se pudo crear el archivo" << endl;
}

void leer()
{
	if ((fd = fopen("personas.txt", "rt")) != NULL)
	{
		fread(&e, le, 1, fd);
		cout << "NRS:" << e.NRS << "\t"
			 << "Raiz:" << e.RZ << "\tURE: " << e.URE << endl;
		while (fread(&s, lr, 1, fd))
		{
			cout << "NR: " << s.NR << "\t nombre: " << s.nombre << "\t celular:"
				 << "\t" << s.celular << " \t" << s.PI << " \t" << s.PD << "\t" << s.ARE << endl;
		}
		fclose(fd);
	}
	else
		cout << "no se pudo abrir el archivo" << endl;
}
void verActivos(){
	if ((fd = fopen("personas.txt", "rt")) != NULL)
	{
		fread(&e, le, 1, fd);
		cout << "NRS:" << e.NRS << "\t"
			 << "Raiz:" << e.RZ << "\tURE: " << e.URE << endl;
		while (fread(&s, lr, 1, fd))
		{	
			if(s.ARE==0){
				cout << "NR: " << s.NR << "\t nombre: " << s.nombre << "\t celular:"
				 << "\t" << s.celular << " \t" << s.PI << " \t" << s.PD << "\t" << s.ARE << endl;
		
			}
			
		}
		fclose(fd);
	}
	else
		cout << "no se pudo abrir el archivo" << endl;
}

int buscar(char nom[20])
{
	char band = 'F';
	int sgte; //
	if ((fd = fopen("personas.txt", "rt")) != NULL)
	{
		fread(&e, le, 1, fd);
		
		//algoritmo buscar al registro que apunta al nuevo
		sgte = e.RZ;
		while (sgte != -1)
		{
			pos = (sgte - 1) * lr + le;
			fseek(fd, pos, 0);
			fread(&s, lr, 1, fd);
			if (strcmp(nom, s.nombre) > 0)
			{
				sgte = s.PD;
				continue;
			}
			if (strcmp(nom, s.nombre) < 0)
			{
				sgte = s.PI;
				continue;
			}
			
			band = 'V';
			fclose(fd);
			return pos;
			break;
		}
		//fin de algoritmo buscar
		if (band == 'F')
		{
			cout << "nombre no existe" << endl;
		}
	}
	else
		cout << "no se pudo abrir el archivo" << endl;
	fclose(fd);
	return -1;
}

int anteriorBuscqueda(char nom[20], int nR)
{

	char band = 'F';
	int sgte; //nom[20],
	if ((fd = fopen("personas.txt", "rt")) != NULL)
	{
		fread(&e, le, 1, fd);
		//	cout<<"nombre:"; fflush(stdin); gets(nom);
		//algoritmo buscar al registro que apunta al nuevo
		sgte = e.RZ;
		while (sgte != -1)
		{
			pos = (sgte - 1) * lr + le;
			fseek(fd, pos, 0);
			fread(&s, lr, 1, fd);

			//SI APUNTA POR LA DERECHA O POR LA IZQUIEDA AL SIGUINETE (NR)
			if (s.PD == nR || s.PI == nR)
			{/*
				cout << "nr" << nR;
				cout << "busc " << endl
					 << "NR: " << s.NR
					 << "\nnombre" << s.nombre
					 << "\t PI: " << s.PI
					 << "\t PD: " << s.PD << endl;*/
				return pos;
			}

			if (strcmp(nom, s.nombre) > 0)
			{
				sgte = s.PD;
				continue;
			}
			if (strcmp(nom, s.nombre) < 0)
			{
				sgte = s.PI;
				continue;
			}
			//cout<<" "<<s.celular<<endl;
			band = 'V';
			fclose(fd);
			return -1;
			break;
		}
		//fin de algoritmo buscar
		if (band == 'F')
		{
			cout << "nombre no existe" << endl;
		}
	}
	else
		cout << "no se pudo abrir el archivo" << endl;
	fclose(fd);
	return -1;
}
void mostrarBusqueda()
{
	cout << "llego a buscar " << endl;

	pos = 0;
	char nom[20];
	int aux = 0;
	cout << "nombre:";
	fflush(stdin);
	gets(nom);
	if ((fd = fopen("personas.txt", "rt")) != NULL)
	{
		aux = buscar(nom);
		if (aux != -1)
		{
			fseek(fd, aux, 0);
			fread(&s, lr, 1, fd);
			cout << "mostrado buscado" << endl
				 << "nombre: " << s.nombre << endl
				 << "Celular: "<< s.celular << endl;
		}
	}
	fclose(fd);
}

int max_izq(char nom[20])
{
	char band = 'F';
	int sgte, max_izq; //nom[20],
	if ((fd = fopen("personas.txt", "rt")) != NULL)
	{
		fread(&e, le, 1, fd);
		//cout<<"nombre:"; fflush(stdin); gets(nom);
		//algoritmo buscar al registro que apunta al nuevo
		sgte = e.RZ;
		while (sgte != -1)
		{
			pos = (sgte - 1) * lr + le;
			fseek(fd, pos, 0);
			fread(&s, lr, 1, fd);
			if (strcmp(nom, s.nombre) > 0)
			{
				sgte = s.PD;
				continue;
			}
			if (strcmp(nom, s.nombre) < 0)
			{
				sgte = s.PI;
				continue;
			}
			band = 'V';
			//se encontr� la clave, ahora buscamos su max_izquierdo
			if (s.PI != -1)
			{
				//existe un maximo izquierdo
				max_izq = s.PI;
				while (max_izq != -1)
				{
					pos = (max_izq - 1) * lr + le;
					fseek(fd, pos, 0);
					fread(&reg_max_izq, lr, 1, fd);
					max_izq = reg_max_izq.PD;
				}

				cout << "M�ximo izquierdo:" << reg_max_izq.nombre << endl; ///////nombre de max_izq
				cout << "pos: " << pos;
				fclose(fd);
				return pos;
			}
			else
				cout << "no tiene maximo izquierdo" << endl;
			//fin de busqueda de maximo izquierdo
			break;
		}
		//fin de algoritmo buscar
		if (band == 'F')
		{
			cout << "nombre no existe" << endl;
		}
	}
	else
		cout << "no se pudo abrir el archivo" << endl;
	fclose(fd);
	return -1;
}
void mostrasMax_izq()
{

	pos = 0;
	int aux = 0;
	char nom[20];
	cout << "nombre:";
	fflush(stdin);
	gets(nom);
	if ((fd = fopen("personas.txt", "rt")) != NULL)
	{
		aux = max_izq(nom);
		if (aux != -1)
		{
			fseek(fd, aux, 0);
			fread(&reg_max_izq, lr, 1, fd);
			cout << "aux " << aux << endl;
			cout << "mostrado max_izq" << endl
				 << "nombre: " << reg_max_izq.nombre << endl;
		}
	}
	fclose(fd);
}
int anteriorMaxixq(int max, char nom[20])
{
	char band = 'F';
	int sgte, max_izq; //nom[20],
	if ((fd = fopen("personas.txt", "rt")) != NULL)
	{
		fread(&e, le, 1, fd);
		//cout<<"nombre:"; fflush(stdin); gets(nom);
		//algoritmo buscar al registro que apunta al nuevo
		sgte = e.RZ;
		while (sgte != -1)
		{
			pos = (sgte - 1) * lr + le;
			fseek(fd, pos, 0);
			fread(&s, lr, 1, fd);
			if (strcmp(nom, s.nombre) > 0)
			{
				sgte = s.PD;
				continue;
			}
			if (strcmp(nom, s.nombre) < 0)
			{
				sgte = s.PI;
				continue;
			}
			band = 'V';
			//se encontr� la clave, ahora buscamos su max_izquierdo
			if (s.PI != -1)
			{
				//existe un maximo izquierdo
				max_izq = s.PI;
				while (max_izq != -1)
				{

					pos = (max_izq - 1) * lr + le;
					fseek(fd, pos, 0);
					fread(&reg_max_izq, lr, 1, fd);
					max_izq = reg_max_izq.PD;
					///SI DERECHA O IZQUIERDA APUNTA AL MAXIMO QUE BUSCAMOS(MAX)
					if (reg_max_izq.PI == max || reg_max_izq.PD == max)
					{
						cout << "encontro a anterior " << endl;
						return pos;
					} /////
				}
			}
			else
				cout << "no tiene maximo izquierdo" << endl;
			//fin de busqueda de maximo izquierdo
			break;
		}
		//fin de algoritmo buscar
		if (band == 'F')
		{
			cout << "nombre no existe" << endl;
		}
	}
	else
		cout << "no se pudo abrir el archivo" << endl;
	fclose(fd);
	return -1;
}

void agregarListaEliminado(int nR) //falta el -1
{
	cout << "llego a agregar listaEliminado " << endl;
	int sigte = 0;
	if ((fd = fopen("personas.txt", "r+t")) != NULL)
	{
		fseek(fd, 0, 0);
		fread(&e, le, 1, fd);
		if (e.URE == -1)
		{
			e.URE = nR;
			fseek(fd, 0, 0);
			fwrite(&e, le, 1, fd);

			pos = 0;
			pos = (nR - 1) * lr + le;
			fseek(fd, pos, 0);
			fread(&s, lr, 1, fd);
			s.ARE = -1;

			fseek(fd, pos, 0);
			fwrite(&s, lr, 1, fd);
			fclose(fd);
			return;
		}
		else
		{
			sigte = e.URE;
			while (true) 
			{
				pos = (sigte - 1) * lr + le;
				fseek(fd, pos, 0);
				fread(&s, lr, 1, fd);

				if (s.ARE == -1)
				{
					pos = (sigte - 1) * lr + le;
					fseek(fd, pos, 0);
					fread(&s, lr, 1, fd);
					cout << "nombre1: " << s.nombre << s.ARE << endl;
					if (s.ARE == -1)
						s.ARE = nR;
					fseek(fd, pos, 0);
					fwrite(&s, lr, 1, fd);

					pos = 0;
					pos = (nR - 1) * lr + le;
					fseek(fd, pos, 0);
					fread(&aux, lr, 1, fd);
					aux.ARE = -1;
					cout << "nombre" << aux.nombre << "\t ARE" << aux.ARE << endl;
					fseek(fd, pos, 0);
					fwrite(&aux, lr, 1, fd);

					fclose(fd);

					return;
				}
				sigte = s.ARE;
			}
		
			fclose(fd);

			return;
		}
	}
}



int eliminar(char nom[20],int band)
{

	int posBuscar;
	int posMax;
	int posAnteriorMax;
	int posAnteriorBusq;
	
	posBuscar = buscar(nom);
	if (posBuscar != -1)
	{
		

		posMax = max_izq(nom);

		if (posMax != -1)
		{
			

			if ((fd = fopen("personas.txt", "r+t")) != NULL)
			{

				fseek(fd, posMax, 0);
				fread(&reg_max_izq, lr, 1, fd);
				posAnteriorMax = anteriorMaxixq(reg_max_izq.NR, nom); //cerrar archivo

				if (posAnteriorMax != -1)
				{

					
					fseek(fd, posAnteriorMax, 0);
					fread(&auxAnt, lr, 1, fd); //
					/*cout << "anterior: " << endl;
					cout << "Nombre: " << auxAnt.nombre << endl
						 << "PD: " << auxAnt.PD << endl
						 << "PI: " << auxAnt.PI << endl;*/
					//leemos max izq
					fseek(fd, posMax, 0);
					fread(&auxMax, lr, 1, fd);
						/*
					cout << "Max: " << endl;
					cout << "Nombre: " << auxMax.nombre << endl
						 << "PD: " << auxMax.PD << endl
						 << "PI: " << auxMax.PI << endl;*/

					auxAnt.PD = auxMax.PI; //apuntamos anteriorMax a puntero derecho de maxIz
					/*
					cout << "anterior: " << endl;
					cout << "Nombre: " << auxAnt.nombre << endl
						 << "PD: " << auxAnt.PD << endl
						 << "PI: " << auxAnt.PI << endl;*/

					if ((fd = fopen("personas.txt", "r+t")) != NULL)
					{

						fseek(fd, posAnteriorMax, 0);
						fwrite(&auxAnt, lr, 1, fd);

						//leemos el  registro buscar
						fseek(fd, posBuscar, 0);
						fread(&auxBusc, lr, 1, fd);
						//leemos el reguistro maximo izq
						fseek(fd, posMax, 0);
						fread(&auxMax, lr, 1, fd);
						/*
								aux.NR = 	 auxBusc.NR;
								aux.nombre = auxBusc.nombre;
								aux.celular = auxBusc.celular;
								aux.PD = 	  auxBusc.PD;
								aux.PI = 	 auxBusc.PI;
								aux.ARE = 	 auxBusc.ARE;*/
						strcpy(aux.nombre, auxBusc.nombre);
						//aux.nombre = auxBusc.nombre;
						strcpy(aux.celular, auxBusc.celular);
						//aux.celular = auxBusc.celular;

						//pasamos de max a  busc
						strcpy(auxBusc.nombre, auxMax.nombre);
						//auxBusc.nombre = auxMax.nombre;
						strcpy(auxBusc.celular, auxMax.celular);
						//auxBusc.celular= auxMax.celular;

						///pasamos de aux a max
						strcpy(auxMax.nombre, aux.nombre);
						//auxMax.nombre = aux.nombre;
						strcpy(auxMax.celular, aux.celular);
						//auxMax.celular = aux.celular;
						//auxMax.ARE=-1; ///crear metodo para insertar

						//guardamos max
						fseek(fd, posMax, 0);
						fwrite(&auxMax, lr, 1, fd);
						fseek(fd, posBuscar, 0);
						fwrite(&auxBusc, lr, 1, fd);

						fclose(fd);
						if(band != 0){
								agregarListaEliminado(auxMax.NR);
						}
						
						return auxMax.NR;
					}
				}
			}

			if ((fd = fopen("personas.txt", "r+t")) != NULL)
			{
				//cout << "llego a nuevo metodo" << endl;

				//leemos el eliminado busc

				fseek(fd, posBuscar, 0);
				fread(&auxBusc, lr, 1, fd);
				//leemos max
				fseek(fd, posMax, 0);
				fread(&auxMax, lr, 1, fd);
				/*
				cout << "auxMax: " << endl
					 << "nombre: " << auxMax.nombre << endl;*/

				auxBusc.PI = auxMax.PI; //eliminamos

				strcpy(aux.nombre, auxBusc.nombre);

				//aux.nombre = auxBusc.nombre;
				strcpy(aux.celular, auxBusc.celular);
				//aux.celular = auxBusc.celular;

				//pasamos de max a  busc
				strcpy(auxBusc.nombre, auxMax.nombre);
				//auxBusc.nombre = auxMax.nombre;
				strcpy(auxBusc.celular, auxMax.celular);
				//auxBusc.celular= auxMax.celular;

				///pasamos de aux a max
				strcpy(auxMax.nombre, aux.nombre);
				//auxMax.nombre = aux.nombre;
				strcpy(auxMax.celular, aux.celular);

				fseek(fd, posMax, 0);
				fwrite(&auxMax, lr, 1, fd);
				fseek(fd, posBuscar, 0);
				fwrite(&auxBusc, lr, 1, fd);
				fclose(fd);
				if(band != 0){
					agregarListaEliminado(auxMax.NR);
				}
				
				return auxMax.NR;
			}
		}

		pos = 0;
		//cout << "llego a eliminar por la derecha" << endl;
		if ((fd = fopen("personas.txt", "r+t")) != NULL)
		{
			fseek(fd, posBuscar, 0);
			fread(&auxBusc, lr, 1, fd);
			fclose(fd);
			posAnteriorBusq = anteriorBuscqueda(nom, auxBusc.NR);

			if (posAnteriorBusq != -1)
			{

				if ((fd = fopen("personas.txt", "r+t")) != NULL)
				{

					//cout << "eliminacion por lado Derecho con anterior.." << endl;
					//leemos anterior de buscar
					fseek(fd, posAnteriorBusq, 0);
					fread(&auxAntBusc, lr, 1, fd);
					//leemos busca
					fseek(fd, posBuscar, 0);
					fread(&auxBusc, lr, 1, fd);/*
					cout << "anterior " << endl
						 << "NR: " << auxAntBusc.NR
						 << "\nnombre" << auxAntBusc.nombre
						 << "\t PI: " << auxAntBusc.PI
						 << "\t PD: " << auxAntBusc.PD << endl;
					cout << "busc " << endl
						 << "NR: " << auxBusc.NR
						 << "\nnombre" << auxBusc.nombre
						 << "\t PI: " << auxBusc.PI
						 << "\t PD: " << auxBusc.PD << endl;*/

					if (auxAntBusc.PD == auxBusc.NR)
					{
						auxAntBusc.PD = auxBusc.PD; // eliminamos
					}
					else
					{
						if (auxAntBusc.PI == auxBusc.NR)
						{
							auxAntBusc.PI = auxBusc.PD;
						}
					}

					//falta insertar a ARE
					fseek(fd, posAnteriorBusq, 0);
					fwrite(&auxAntBusc, lr, 1, fd);
					fclose(fd);
					if(band != 0){
							agregarListaEliminado(auxBusc.NR);
					}
					
					return auxBusc.NR;
				}
			}
			else
			{

				if ((fd = fopen("personas.txt", "r+t")) != NULL)
				{
					//cout << "elimana a derecha tomando en cuenta la raiz" << endl;

					//leemos encabezado
					fseek(fd, 0, 0);
					fread(&e, le, 1, fd);
					//leemos buscar
					fseek(fd, posBuscar, 0);
					fread(&auxBusc, lr, 1, fd);
					if (e.RZ == auxBusc.NR)
					{
						//cout << "eliminara a raiz por la derecha " << endl;

						e.RZ = auxBusc.PD; // eliminamos

						//falta agregar a la lista ARE
						fseek(fd, 0, 0);
						fwrite(&e, le, 1, fd);
						fclose(fd);
						if(band !=0){
							agregarListaEliminado(auxBusc.NR);
						}
						
						return auxBusc.NR;
					}
				}
			}
		}
	}
	return 0;
}

void mostrarEliminados(){

	int sgte;

	if ((fd = fopen("personas.txt", "r+t")) != NULL)
	{

		fread(&e, le, 1, fd);
		sgte = e.URE;
		while (sgte != -1)
		{
			pos = (sgte - 1) * lr + le;
			fseek(fd, pos, 0);
			fread(&s, lr, 1, fd);
			cout << "NR: " << s.NR << "\t nombre: " << s.nombre << "\t celular:"
				 << "\t" << s.celular << " \t" << s.PI << " \t" << s.PD << "\t" << s.ARE << endl;

			sgte = s.ARE;
			
		}
		fclose(fd);
	
	
	}









}

void modificarClave(){
	//LOGICA
	//BUCAMOS AL MODIFICAR
	//ELIMINAMOS EL REGISTRO
	//Y LO REINSERTAMOS PARA QUE SE ORDENE EN EL ARBOL

char nombre[20];
char celular[20];
int nR;
int pos2;

	fflush(stdin);
	cout << "nombre" << endl;
	gets(nombre);

	pos2 = buscar(nombre);
	if(pos2 != -1){
		
		

		nR = eliminar(nombre,0);
		if(nR != 0){

			if ((fd = fopen("personas.txt", "r+t")) != NULL)
			{
				
				
				pos = (nR - 1) * lr + le;
				fseek(fd, pos, 0);
				fread(&s, lr, 1, fd);
				/*
				cout << "nombre: "<< s.nombre << endl ;
				cout << "celular: "<<s.celular <<endl;
				cout << "NR: "<< s.NR << endl;
				cout << "PI: "<< s.PI << endl;
				cout <<	"PD: "<<s.PD << endl;*/


				fflush(stdin);
				cout<< "Cambios\nnombre" << endl;
				gets(nombre);
				fflush(stdin);
				cout << "celular" << endl;
				gets(celular);
				reInsertar(nR,nombre,celular);

			}

		

		}

	}

	
	

}
int main(int argc, char *argv[])
{
	int opcion;
	cout << "tamanio registro: " << lr << endl;
	cout << "tamanio encabezado: " << le << endl;
	do
	{
		cout << " 1.escribir\n 2.leer\n 3.buscar\n 4.max_izq\n 5.insertar\n 6.eliminar\n 7.mostrar Eliminados\n 8.modificar Clave\n 9.ver activos\n 15.salir" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			escribir();
			break;
		case 2:
			leer();
			break;
		case 3:
			mostrarBusqueda();
			break;
		case 4:
			mostrasMax_izq();
			break;
		case 5:
			insertar();
			break;
		case 6:
			char nom[20];
			cout << "nombre:";
			fflush(stdin);
			gets(nom);
			eliminar(nom,1);
			break;
		case 7: 
			mostrarEliminados();
			break;
		case 8:
			modificarClave();
			break;
		case 9: 
			verActivos();
			break;

		}
	} while (opcion != 15);
	return 0;
}
