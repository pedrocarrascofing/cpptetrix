#include "cola_piezas.h"


Cola_p::Cola_p()
{
	cab=new lista_nodo;
	num_elem=0;
	cab->sig=0;
	cab->ant=0;
}
	
Cola_p::Cola_p(const Cola_p &c)
{
	cab=new lista_nodo;
	num_elem=0;
	cab->sig=0;
	cab->ant=0;
	lista_nodo* p_elem;
	p_elem=c.cab->sig;
	
	if(c.num_elem!=0)
	{
		cab->sig=new lista_nodo;
		cab->ant=cab->sig;
		cab->sig->sig=cab;
		cab->sig->ant=cab;
		cab->sig->elem=p_elem->elem;
		num_elem++;
	}
	
	while(num_elem<c.num_elem)
	{
		p_elem=p_elem->sig;
		lista_nodo* aux;
		aux=cab->ant;
		cab->ant=0;
		cab->ant=new lista_nodo;
		cab->ant->ant=aux;
		cab->ant->sig=cab;
		cab->ant->elem=p_elem->elem;
		aux->sig=cab->ant;
		num_elem++;
	}
		

}
		
Cola_p::~Cola_p()
{
	if(num_elem==0)
		delete cab;
	else
	{
		while(num_elem>0)
		{
			lista_nodo *aux;
			aux=cab->ant->ant;
			delete cab->ant;
			cab->ant=aux;
			num_elem--;
		}
		delete cab;
	}
}

//Operator =
Cola_p & Cola_p::operator=(const Cola_p &c)
{
if(this!= &c)
{
	lista_nodo* p_elem;
	p_elem=c.cab->sig;
		
	if(c.num_elem!=0)
	{
		while(num_elem>0)
		{
			lista_nodo *aux;
			aux=cab->ant->ant;
			delete cab->ant;
			cab->ant=aux;
			num_elem--;
		}
		cab->sig=new lista_nodo;
		cab->ant=cab->sig;
		cab->sig->sig=cab;
		cab->sig->ant=cab;
		cab->sig->elem=p_elem->elem;
		num_elem++;
	}
	
	while(num_elem<c.num_elem)
	{
		p_elem=p_elem->sig;
		lista_nodo* aux;
		aux=cab->ant;
		cab->ant=0;
		cab->ant=new lista_nodo;
		cab->ant->ant=aux;
		cab->ant->sig=cab;
		cab->ant->elem=p_elem->elem;
		aux->sig=cab->ant;
		num_elem++;
	}
}

	return *this;
}	

void Cola_p::clear()
{
	if(num_elem!=0)
	{
		while(num_elem>0)
		{
			lista_nodo *aux;
			aux=cab->ant->ant;
			delete cab->ant;
			cab->ant=aux;
			num_elem--;
		}
		cab->ant=0;
		cab->sig=0;
	}
}

Pieza& Cola_p::front()const
{
	return cab->sig->elem;
}

void Cola_p::push(const Pieza &p)
{
	if(num_elem==0)
	{	
		lista_nodo *aux;
		cab->sig=new lista_nodo;
		aux=cab->sig;
		aux->ant=cab;
		aux->sig=cab;
		cab->ant=aux;
		aux->elem=p;
		num_elem=1;
	}		

	else
	{
		lista_nodo *aux;
		aux=cab->ant;
		cab->ant=0;
		cab->ant=new lista_nodo;
		aux->sig=cab->ant;
		cab->ant->ant=aux;
		cab->ant->sig=cab;
		cab->ant->elem=p;
		num_elem++;

	}
}

void Cola_p::pop()
{
	lista_nodo *aux;
	aux=cab->sig;
	cab->sig=aux->sig;
	delete aux;
	aux=cab->sig;
	aux->ant=cab;
	num_elem--;
}

Pieza Cola_p::GetPieza(int n)const
{
	lista_nodo *aux=cab->sig;
	int cont=0;
	while(cont <n)
	{
		aux=aux->sig;
		cont++;
	}
	return aux->elem;
}
