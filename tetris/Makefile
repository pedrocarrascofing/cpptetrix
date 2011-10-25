all:precleaner tetris_resp_lin tetris_resp tetris clean

LIB=lib
SRC=src
OBJ=obj
INCLUDE=include
BIN=bin

CXX=g++

#//////////////////////////////////////////tetris_resp_lin/////////////////////////////////////
tetris_resp_lin: bin/tetris_resp_lin

bin/tetris_resp_lin: $(OBJ)/main_resp_lin.o	$(LIB)/libTetris.a ../graficos/lib/libgraficos.a
	$(CXX) $(OBJ)/main_resp_lin.o $(OBJ)/vis_cola.o -o bin/tetris_resp_lin -L$(LIB) -lTetris -L../graficos/lib -lgraficos -lSDL -lSDL_gfx -lSDL_ttf -lfreetype

$(OBJ)/main_resp_lin.o: $(SRC)/main_resp_lin.cpp $(LIB)/libTetris.a ../graficos/include
	$(CXX) -g -c $(SRC)/main_resp_lin.cpp -o $(OBJ)/main_resp_lin.o -Iinclude -I../graficos/include

#//////////////////////////////////////////tetris_resp/////////////////////////////////////
tetris_resp: bin/tetris_resp

bin/tetris_resp: $(OBJ)/main_resp.o	$(LIB)/libTetris.a ../graficos/lib/libgraficos.a
	$(CXX) $(OBJ)/main_resp.o $(OBJ)/vis_cola.o -o bin/tetris_resp -Llib -lTetris -L../graficos/lib -lgraficos -lSDL -lSDL_gfx -lSDL_ttf -lfreetype

$(OBJ)/main_resp.o: $(SRC)/main_resp.cpp $(LIB)/libTetris.a ../graficos/include
	$(CXX) -g -c $(SRC)/main_resp.cpp -o $(OBJ)/main_resp.o -Iinclude -I../graficos/include


#//////////////////////////////////////////tetris/////////////////////////////////////
tetris: bin/tetris

bin/tetris: $(OBJ)/main_basico.o	$(LIB)/libTetris.a ../graficos/lib/libgraficos.a
	$(CXX) $(OBJ)/main_basico.o $(OBJ)/vis_cola.o -o bin/tetris -Llib -lTetris -L../graficos/lib -lgraficos -lSDL -lSDL_gfx -lSDL_ttf -lfreetype

$(OBJ)/main_basico.o: $(SRC)/main_basico.cpp $(LIB)/libTetris.a ../graficos/include
	$(CXX) -g -c $(SRC)/main_basico.cpp -o $(OBJ)/main_basico.o -Iinclude -I../graficos/include


#///////////////////////////////////////// libTetris.a /////////////////////////////
$(LIB)/libTetris.a: $(OBJ)/matriz.o $(OBJ)/pieza.o $(OBJ)/tablero.o $(OBJ)/cola_piezas.o $(OBJ)/imagen.o $(OBJ)/visualizador.o $(OBJ)/vis_texto.o $(OBJ)/vis_tablero.o $(OBJ)/vis_cola.o $(OBJ)/color.o
	ar rvs  $(LIB)/libTetris.a $(OBJ)/matriz.o $(OBJ)/pieza.o $(OBJ)/tablero.o $(OBJ)/cola_piezas.o $(OBJ)/imagen.o $(OBJ)/visualizador.o $(OBJ)/vis_texto.o $(OBJ)/vis_tablero.o $(OBJ)/vis_cola.o $(OBJ)/color.o


#///////////////////////////////////////// $(OBJ) /////////////////////////////
$(OBJ)/matriz.o: $(SRC)/matriz.cpp $(INCLUDE)/matriz.h
	$(CXX) -g -c $(SRC)/matriz.cpp -o $(OBJ)/matriz.o -Iinclude

$(OBJ)/pieza.o: $(SRC)/pieza.cpp $(INCLUDE)/pieza.h $(OBJ)/matriz.o
	$(CXX) -g -c $(SRC)/pieza.cpp -o $(OBJ)/pieza.o -Iinclude

$(OBJ)/tablero.o: $(SRC)/tablero.cpp $(INCLUDE)/tablero.h 
	$(CXX) -g -c $(SRC)/tablero.cpp -o $(OBJ)/tablero.o -Iinclude

$(OBJ)/cola_piezas.o: $(SRC)/cola_piezas.cpp $(INCLUDE)/cola_piezas.h
	$(CXX) -g -c $(SRC)/cola_piezas.cpp -o $(OBJ)/cola_piezas.o -Iinclude

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INCLUDE)/imagen.h ../graficos/$(OBJ)/graficos.o
	$(CXX) -g -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -Iinclude -I../graficos/include

$(OBJ)/visualizador.o: $(SRC)/visualizador.cpp $(INCLUDE)/visualizador.h $(LIB)/libTetris.a
	$(CXX) -g -c $(SRC)/visualizador.cpp -o $(OBJ)/visualizador.o -Iinclude -I../graficos/include 

$(OBJ)/vis_texto.o: $(SRC)/vis_texto.cpp $(INCLUDE)/vis_texto.h $(LIB)/libTetris.a ../graficos/include/graficos.h 
	$(CXX) -g -c $(SRC)/vis_texto.cpp -Iinclude -I../graficos/include -o $(OBJ)/vis_texto.o 

$(OBJ)/vis_tablero.o: $(SRC)/vis_tablero.cpp $(INCLUDE)/vis_tablero.h $(LIB)/libTetris.a ../graficos/include/graficos.h 
	$(CXX) -g -c $(SRC)/vis_tablero.cpp -Iinclude -I../graficos/include -o $(OBJ)/vis_tablero.o

$(OBJ)/vis_cola.o: $(SRC)/vis_cola.cpp $(INCLUDE)/vis_cola.h $(LIB)/libTetris.a ../graficos/include/graficos.h 
	$(CXX) -g -c $(SRC)/vis_cola.cpp -Iinclude -I../graficos/include -o $(OBJ)/vis_cola.o
$(OBJ)/color.o: $(SRC)/color.cpp $(INCLUDE)/color.h
	$(CXX) -g -c $(SRC)/color.cpp -Iinclude -o $(OBJ)/color.o

#/////////////////Limpieza//////////////////

precleaner:
	-rm $(LIB)/*
	-rm $(BIN)/*

clean:
	-rm $(OBJ)/*.o

