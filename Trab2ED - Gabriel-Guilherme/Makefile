CC = gcc
COMPILER_FLAGS = -std=c99 -fstack-protector-all -g
LINKER_FLAGS = -lm 
EXEC_NAME = siguel
OBJECTS = main.o argumentos.o arquivos.o leitura_geo.o svg.o leitura_gry.o consultas.o util.o elementos/quadra.o lista.o  elementos/texto.o  elementos/hidrante.o elementos/semaforo.o elementos/radioBase.o elementos/forma.o

all: $(EXEC_NAME)
$(OBJECTS): %.o : %.c
		gcc -g -c $< -o $@

siguel: $(OBJECTS) 
		$(CC) $(OBJECTS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC_NAME)

clean:
		rm -rf *.o siguel 
		rm -rf saida/*.txt
		rm -rf saida/*.svg
