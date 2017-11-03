#Makefile

#Compilador : g++
CC=g++

#Variáveis de diretórios:
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
DOC_DIR=./doc
BIN_DIR=./bin
LIB_DIR=./lib
TEST_DIR=./test

#Váriavel de compilação:
CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)/q01
CFLAGS2=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)/q02
#CFLAGS3=-Wall -pedantic -ansi -std=c++11 -I.

.PHONY: all clean doxy debug doc

#Remove os arquivos .o:
all: questao01 questao02 #questao03

debug: CFLAGS += -g -O0

debug: questao01 questao02 #questao03

#Criação do executavel: questao01
questao01: $(OBJ_DIR)/closet2mean.o
	@echo	"======================"
	@echo	"Carregando o alvo $@"
	@echo	"======================"
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo	"++++ [Executavel questao01 criado em $(BIN_DIR)] ++++"
	@echo	"  =============================================    "

#Criação dos arquivos .o:

#closet2mean.o
$(OBJ_DIR)/closet2mean.o: $(SRC_DIR)/q01/closet2mean.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

#Criação do executavel: questao02
questao02: $(OBJ_DIR)/print.o
	@echo	"======================"
	@echo	"Carregando o alvo $@"
	@echo	"======================"
	$(CC) $(CFLAGS2) -o $(BIN_DIR)/$@ $^
	@echo	"++++ [Executavel questao01 criado em $(BIN_DIR)] ++++"
	@echo	"  =============================================    "

#Criação dos arquivos .o:

#print.o
$(OBJ_DIR)/print.o: $(SRC_DIR)/q02/print.cpp
	$(CC) -c $(CFLAGS2) -o $@ $<

doxy:
	rm -rf $(DOC_DIR)/*
	doxygen Doxyfile

clean:
	rm -rf $(BIN_DIR)/*
	rm -rf $(OBJ_DIR)/*