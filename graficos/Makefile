
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g -I../SDL_aulas/include -Iinclude -c
LDFLAGS = -Llib -L../SDL_aulas/lib -lgraficos -lSDL -lSDL_gfx -lSDL_ttf -lfreetype

# ************ Objetivos principales ************
all : holamundo test1 test2 test3 test_fuente_1 test_fuente_2 test_fuente_3 test_fuente_4 test_reloj test_activar test_dibujo test_bitmap test_bitmap_2

# ************ Ejecución de programas de prueba ************
test: test_fuentes

test_fuentes: test_fuente_1 test_fuente_2
	$(BIN)/test_fuente_1 data/fuentes
	$(BIN)/test_fuente_2 data/fuentes DejaVuSans
	$(BIN)/test_fuente_2 data/fuentes Disko

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(OBJ)/graficos.o : $(SRC)/graficos.cpp $(INC)/graficos.h
	$(CXX) $(CPPFLAGS) $(SRC)/graficos.cpp -o $(OBJ)/graficos.o

$(OBJ)/holamundo.o : $(SRC)/holamundo.cpp $(INC)/graficos.h
	$(CXX) $(CPPFLAGS) $(SRC)/holamundo.cpp -o $(OBJ)/holamundo.o

$(OBJ)/test1.o : $(SRC)/test1.cpp $(INC)/graficos.h
	$(CXX) $(CPPFLAGS) $(SRC)/test1.cpp -o $(OBJ)/test1.o

$(OBJ)/test2.o : $(SRC)/test2.cpp $(INC)/graficos.h
	$(CXX) $(CPPFLAGS) $(SRC)/test2.cpp -o $(OBJ)/test2.o

$(OBJ)/test3.o : $(SRC)/test3.cpp $(INC)/graficos.h
	$(CXX) $(CPPFLAGS) $(SRC)/test3.cpp -o $(OBJ)/test3.o

$(OBJ)/test_fuente_1.o : $(SRC)/test_fuente_1.cpp $(INC)/graficos.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_fuente_1.cpp -o $(OBJ)/test_fuente_1.o

$(OBJ)/test_fuente_2.o : $(SRC)/test_fuente_2.cpp $(INC)/graficos.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_fuente_2.cpp -o $(OBJ)/test_fuente_2.o

$(OBJ)/test_fuente_3.o : $(SRC)/test_fuente_3.cpp $(INC)/graficos.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_fuente_3.cpp -o $(OBJ)/test_fuente_3.o

$(OBJ)/test_fuente_4.o : $(SRC)/test_fuente_4.cpp $(INC)/graficos.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_fuente_4.cpp -o $(OBJ)/test_fuente_4.o

$(OBJ)/test_reloj.o : $(SRC)/test_reloj.cpp $(INC)/graficos.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_reloj.cpp -o $(OBJ)/test_reloj.o

$(OBJ)/test_activar.o : $(SRC)/test_activar.cpp $(INC)/graficos.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_activar.cpp -o $(OBJ)/test_activar.o

$(OBJ)/test_dibujo.o : $(SRC)/test_dibujo.cpp $(INC)/graficos.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_dibujo.cpp -o $(OBJ)/test_dibujo.o

$(OBJ)/test_bitmap.o : $(SRC)/test_bitmap.cpp $(INC)/graficos.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_bitmap.cpp -o $(OBJ)/test_bitmap.o

$(OBJ)/test_bitmap_2.o : $(SRC)/test_bitmap_2.cpp $(INC)/graficos.h
	$(CXX) $(CPPFLAGS) $(SRC)/test_bitmap_2.cpp -o $(OBJ)/test_bitmap_2.o

# ************ Bibliotecas ************
$(LIB)/libgraficos.a : $(OBJ)/graficos.o
	ar rsv $(LIB)/libgraficos.a $(OBJ)/graficos.o

# ************ Enlazado y creación de ejecutables ************
holamundo : $(BIN)/holamundo
$(BIN)/holamundo : $(OBJ)/holamundo.o $(LIB)/libgraficos.a
	$(CXX) -o $(BIN)/holamundo $(OBJ)/holamundo.o $(LDFLAGS)

test1 : $(BIN)/test1
$(BIN)/test1 : $(OBJ)/test1.o $(LIB)/libgraficos.a
	$(CXX) -o $(BIN)/test1 $(OBJ)/test1.o $(LDFLAGS)

test2 : $(BIN)/test2
$(BIN)/test2 : $(OBJ)/test2.o $(LIB)/libgraficos.a
	$(CXX) -o $(BIN)/test2 $(OBJ)/test2.o $(LDFLAGS)

test3 : $(BIN)/test3
$(BIN)/test3 : $(OBJ)/test3.o $(LIB)/libgraficos.a
	$(CXX) -o $(BIN)/test3 $(OBJ)/test3.o $(LDFLAGS)

test_fuente_1 : $(BIN)/test_fuente_1
$(BIN)/test_fuente_1 : $(OBJ)/test_fuente_1.o $(LIB)/libgraficos.a
	$(CXX) -o $(BIN)/test_fuente_1 $(OBJ)/test_fuente_1.o $(LDFLAGS)

test_fuente_2 : $(BIN)/test_fuente_2
$(BIN)/test_fuente_2 : $(OBJ)/test_fuente_2.o $(LIB)/libgraficos.a
	$(CXX) -o $(BIN)/test_fuente_2 $(OBJ)/test_fuente_2.o $(LDFLAGS)

test_fuente_3 : $(BIN)/test_fuente_3
$(BIN)/test_fuente_3 : $(OBJ)/test_fuente_3.o $(LIB)/libgraficos.a
	$(CXX) -o $(BIN)/test_fuente_3 $(OBJ)/test_fuente_3.o $(LDFLAGS)

test_fuente_4 : $(BIN)/test_fuente_4
$(BIN)/test_fuente_4 : $(OBJ)/test_fuente_4.o $(LIB)/libgraficos.a
	$(CXX) -o $(BIN)/test_fuente_4 $(OBJ)/test_fuente_4.o $(LDFLAGS)

test_reloj : $(BIN)/test_reloj
$(BIN)/test_reloj : $(OBJ)/test_reloj.o $(LIB)/libgraficos.a
	$(CXX) -o $(BIN)/test_reloj $(OBJ)/test_reloj.o $(LDFLAGS)

test_activar : $(BIN)/test_activar
$(BIN)/test_activar : $(OBJ)/test_activar.o $(LIB)/libgraficos.a
	$(CXX) -o $(BIN)/test_activar $(OBJ)/test_activar.o $(LDFLAGS)

test_dibujo : $(BIN)/test_dibujo
$(BIN)/test_dibujo : $(OBJ)/test_dibujo.o $(LIB)/libgraficos.a
	$(CXX) -o $(BIN)/test_dibujo $(OBJ)/test_dibujo.o $(LDFLAGS)

test_bitmap : $(BIN)/test_bitmap
$(BIN)/test_bitmap : $(OBJ)/test_bitmap.o $(LIB)/libgraficos.a
	$(CXX) -o $(BIN)/test_bitmap $(OBJ)/test_bitmap.o $(LDFLAGS)

test_bitmap_2 : $(BIN)/test_bitmap_2
$(BIN)/test_bitmap_2 : $(OBJ)/test_bitmap_2.o $(LIB)/libgraficos.a
	$(CXX) -o $(BIN)/test_bitmap_2 $(OBJ)/test_bitmap_2.o $(LDFLAGS)

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(LIB)/libgraficos.a $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
