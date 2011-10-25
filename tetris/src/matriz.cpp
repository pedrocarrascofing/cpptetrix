#include "matriz.h"

	// Constructores
	Matriz::Matriz ()
	{
		mat=0;
		fil=col=0;
		mat=0;
	}
	Matriz::Matriz(int f, int c)
	{
		fil=f;
		col=c;
		mat=new int*[fil];
		for(int i=0; i<fil; i++)
			mat[i]=new int[col];
	}
	
	Matriz::Matriz(const Matriz &M)
	{
		fil=M.fil;
		col=M.col;		
		mat=new int*[fil];
		for(int i=0; i<fil; i++)
		{
			mat[i]=new int[col];
			for(int j=0; j<col; j++)
				mat[i][j]=M.mat[i][j];
		}
	}

	Matriz::~Matriz ()
	{
		for(int i=0; i<fil; i++)
			delete []mat[i];
		delete []mat;
	}
		
	int Matriz::FilasMatriz ()const
	{
		return fil;
	}

	int Matriz::ColumnasMatriz ()const
	{
		return col;
	}
	
	void Matriz::SetMatriz(int fil, int col, int v)
	{
		mat[fil][col]=v;
	}

	int Matriz::GetMatriz (int fil, int col)const
	{
		return mat[fil][col];
	}
	
	Matriz Matriz::Traspuesta()const
	{
		Matriz aux(col, fil);
		for(int i=0; i<col; i++)
			for(int j=0; j<fil; j++)
				aux.mat[i][j]=mat[j][i];
		return aux;
	}

	Matriz Matriz::TrasFil()const
	{
		int cont1=0, cont2=fil-1;
		Matriz M(fil, col);
		
		while(cont1<=cont2)
		{	
			for(int i=0; i<col; i++)
			{
				M.mat[cont1][i]=mat[cont2][i];
				M.mat[cont2][i]=mat[cont1][i];
			}
			cont1++;
			cont2--;
		}

		return M;
	}
		
	Matriz Matriz::TrasCol()const
	{
		int cont1=0, cont2=col-1;
		Matriz M(fil, col);
		while(cont1<=cont2)
		{	
			for(int i=0; i<fil; i++)
			{
				M.mat[i][cont1]=mat[i][cont2];
				M.mat[i][cont2]=mat[i][cont1];
			}
			cont1++;
			cont2--;
		}
		return M;
	}	

	Matriz &Matriz::operator=(const Matriz &M)
	{
		if(this != &M)
		{
			for(int i=0; i<fil; i++)
				delete []mat[i];
			delete []mat;
			
			fil=M.fil;
			col=M.col;
			mat=new int*[fil];
			for(int i=0; i<fil; i++)
			{
				mat[i]=new int[col];
				for(int j=0; j<col; j++)
					mat[i][j]=M.mat[i][j];
			}
		}
		return *this;
	}
