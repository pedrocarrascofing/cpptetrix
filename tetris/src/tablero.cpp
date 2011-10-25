#include "tablero.h"

Tablero::Tablero() :tab(), pz()
{
	x=0;
	y=0;
}

Tablero::Tablero(const Tablero &t)
{
	tab=t.tab;
	pz=t.pz;
	x=t.x;
	y=t.y;
}

Tablero::Tablero(const Matriz &m)
{
	x=m.ColumnasMatriz()/2;
	y=0;
	tab=m;
}

Tablero::Tablero(const Matriz &m, const Pieza &p)
{
	tab=m;
	pz=p;
	x=m.ColumnasMatriz()/2;
	y=0;
}

Tablero::Tablero(const Matriz &m, const Pieza &p, int a, int b)
{
	tab=m;
	pz=p;
	x=a;
	y=b;
}

Tablero &Tablero::operator=(const Tablero &t)
{
	if(this!=&t)
	{
		tab=t.tab;
		pz=t.pz;
		x=t.x;
		y=t.y;
	}
	return *this;
}
		
		
int Tablero::Ancho()const
{
	return tab.ColumnasMatriz();
}

int Tablero::Alto()const
{
	return tab.FilasMatriz();
}

int Tablero::PosXPieza()const
{
	return x;
}
	
int Tablero::PosYPieza()const
{
	return y;
}
	
bool Tablero::CompGiroRight()const
{
	Pieza temp(pz);
	temp.GiroDer();
	int fil_p, col_p;
	fil_p=temp.Alto();
	col_p=temp.Ancho();
	if( (col_p+x) > tab.ColumnasMatriz() )
		return false;
	if( (fil_p+y) > tab.FilasMatriz() )
		return false;

	for(int i=0; i<fil_p; i++)
		for(int j=0; j<col_p; j++)
			if(0!=tab.GetMatriz(y+i, x+j) )
				return false;
	return true;
}

bool Tablero::CompGiroLeft()const
{
	Pieza temp(pz);
	temp.GiroIz();
	int fil_p, col_p;
	fil_p=temp.Alto();
	col_p=temp.Ancho();	
	if( (col_p+x) > tab.ColumnasMatriz() )
		return false;
	if( (fil_p+y) > tab.FilasMatriz() )
		return false;
	for(int i=0; i<fil_p; i++)
		for(int j=0; j<col_p; j++)
			if(0!=tab.GetMatriz(y+i, x+j) )
				return false;
	return true;
}

bool Tablero::CompMovRight()const
{
	if(x==(tab.ColumnasMatriz()-1))
		return false;
	int al=pz.Alto(), an=pz.Ancho();
	if(x+an>(tab.ColumnasMatriz()-1))
		return false;
	for(int i=0; i<al; i++)
		for(int j=0; j<an; j++)
			if( tab.GetMatriz(y+i, x+j+1 ) != 0 && pz.GetPieza(i, j)!=0 )
			return false;
	return true;
}
	
bool Tablero::CompMovLeft()const
{
	if(x==0)
		return false;
	int al=pz.Alto(), an=pz.Ancho();

	for(int i=0; i<al; i++)
		for(int j=0; j<an; j++)
			if( tab.GetMatriz(y+i, x+j-1 ) != 0 && pz.GetPieza(i, j)!=0 )
				return false;	
	return true;
}

bool Tablero::CompMovDown()const
{
	int al=pz.Alto(), an=pz.Ancho();
	if(y+al==tab.FilasMatriz())
		return false;
	for(int i=0; i<al; i++)
		for(int j=0; j<an; j++)
			if( tab.GetMatriz(y+i+1, j+x) != 0 && pz.GetPieza(i, j)!=0 )
			return false;
	return true;
}

bool Tablero::CompMovUp()const
{
	int al=pz.Alto(), an=pz.Ancho();
	if(y==0)
		return false;
	for(int i=0; i<al; i++)
		for(int j=0; j<an; j++)
			if( tab.GetMatriz(y+i, j+x) != 0 && pz.GetPieza(i, j)!=0 )
				return false;
	return true;
}
	

bool Tablero::LineaCompleta(int n)const
{
	int col=tab.ColumnasMatriz();
	for(int i=0; i<col; i++)
		if(tab.GetMatriz(n, i) == 0)
			return false;
	return true;
}

bool Tablero::FinJuego() const
{
	int col=tab.ColumnasMatriz();
	for(int i=0; i<col; i++)
		if(tab.GetMatriz(0, i) !=0)
			return true;
	return false;
}

bool Tablero::GirarDer()
{
	if(CompGiroRight())
	{
		pz.GiroDer();
		return true;
	}
	return false;
}
	
bool Tablero::GirarIz()
{
	if(CompGiroLeft())
	{
		pz.GiroIz();
		return true;	
	}
	return false;
}

bool Tablero::MovRight()
{
	if(CompMovRight())
	{
		x+=1;
		return true;
	}
	return false;
}
			
bool Tablero::MovLeft()
{
	if(CompMovLeft())
	{
		x-=1;
		return true;
	}
	return false;
}

bool Tablero::MovDown()
{
	if(CompMovDown())
	{
		y+=1;
		return true;
	}
	return false;
}

bool Tablero::MovUp()
{
	if(CompMovUp())
	{
		y-=1;
		return true;
	}
	return false;
}	

void Tablero::SuprLinea(int n)
{
	int an=tab.ColumnasMatriz(), al=tab.FilasMatriz(), aux;
	if(n < al && n>=0)
	{
	bool fil_sup_vacia=true, fin=false;
	for(int j=0; j<an && fil_sup_vacia; j++)
		if( tab.GetMatriz(n-1, j)!=0 )
			fil_sup_vacia=false;
	if(fil_sup_vacia)
		for(int j=0; j<an; j++)
			tab.SetMatriz(n, j, 0);
	else
		for(int i=n; i>=0 && !fin; i--)
		{
			fin=true;
			for(int j=0; j<an; j++)		
			{	
				aux=tab.GetMatriz(i-1, j); 
				if(aux!=0)
					fin=false;
				tab.SetMatriz(i, j, aux);
			}
		}
	}
}

void Tablero::InicializaTablero()
{
	int fil=tab.FilasMatriz();
	int col=tab.ColumnasMatriz();
	for(int i=0; i<fil; i++)
		for(int j=0; j<col; j++)
			tab.SetMatriz(i, j, 0);
}
	
int Tablero::Barrido()
{
	int fil=tab.FilasMatriz(), cont=0;
	for(int i=fil-1; i>=0; i--)
		if(LineaCompleta(i) )
		{
			SuprLinea(i);
			i++;
			cont++;
		}
	return cont;
}

void Tablero::Apilar()
{
	int fil_p=pz.Alto(), col_p=pz.Ancho(), aux;
	for(int i=0; i<fil_p; i++)
		for(int j=0; j<col_p; j++)
		{
			aux=pz.GetPieza(i, j);
			if(aux!=0)
				tab.SetMatriz(i+y, j+x, aux);
		}
}


void Tablero::ResetPieza(const Pieza &p)
{
	pz=p;
	x=tab.ColumnasMatriz()/2;
	y=0;
}

int Tablero::GetTabElem(int posx, int posy)const
{
	return tab.GetMatriz(posx, posy);
}

void Tablero::ResetTablero()
{
	int fil=tab.FilasMatriz(), col=tab.ColumnasMatriz();
	for(int i=0; i<fil; i++)
		for(int j=0; j<col; j++)
			tab.SetMatriz(i, j, 0 );
}

void Tablero::SetPieza(const Pieza &p1)
{
	pz=p1;
}

Pieza Tablero::GetPieza()const
{
	return pz;
}

int Tablero::GetPiezaElem(int posx, int posy)const
{
	return pz.GetPieza(posx, posy);
}

int Tablero::AnchoPieza()const
{
	return pz.Ancho();
}

int Tablero::AltoPieza()const
{
	return pz.Alto();
}

void Tablero::SetPosPieza(int x, int y)
{
	this->x=x;
	this->y=y;
}

void Tablero::LineaAleatoria(int max)
{
	int col=tab.ColumnasMatriz(), fil=tab.FilasMatriz();
	time_t t, v;
	srandom(v);
	srandom(random()%100);
	int n;
	bool fin=false;

	for(int i=0; i<col && !fin; i++)
		if( tab.GetMatriz(1, i) != 0 )
			fin=true;
	if(!fin)
	{
		for(int i=0; i<fil-1; i++)
			for(int j=0; j<col; j++)
				tab.SetMatriz(i, j, tab.GetMatriz(i+1, j) );

		for(int i=0; i<col; i++)
			tab.SetMatriz(fil-1, i, random()%2);
		if(n>0)
		for(int i=0; i<col; i++)
			if(tab.GetMatriz(fil-1, i)!=0)
				tab.SetMatriz(fil-1, i, random()%max);
;
	}
	
}
