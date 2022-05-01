#/******************************************************************************
#*  ASR => 4R2.04                                                              *
#*******************************************************************************
#*                                                                             *
#*  N° de Sujet : 3                                                            * 
#*******************************************************************************
#*                                                                             *
#*  Intitulé :    Chiffrement de messages                                      *
#*******************************************************************************
#*                                                                             *
#*  Nom-prénom1 : COUTURIER Quentin                                            *
#*                                                                             *
#*  Nom-prénom2 : CHELLE Elena                                                 *
#*                                                                             *
#*  Nom-prénom3 : FERREIRA Iannis                                              *
#*******************************************************************************
#*                                                                             *
#*  Nom du fichier : makefile                                                  *
#*                                                                             *
#******************************************************************************/


# Répertoires
SRCDIR = src
OBJDIR = obj
INCDIR = includes




#Compilation sans règle de dépendence
all:
	gcc $(SRCDIR)/{main.c,argParser.c,controleEntree.c,cesar.c,vigenere.c} -o main

#Edition de liens si .o plus récents que main
main: main.o argParser.o controleEntree.o cesar.o vigenere.o
	gcc $(OBJDIR)/{main.o,argParser.o,controleEntree.o,cesar.o,vigenere.o} -o main

#Recompile si main.c ou les .h plus récents que main.o
main.o: src/main.c $(INCDIR)/argParser.h  $(INCDIR)/cesar.h $(INCDIR)/controleEntree.h $(INCDIR)/vigenere.h
	gcc -c $(SRCDIR)/main.c -o $(OBJDIR)/main.o

#Recompile si argParser.c ou argParser.h plus récents que argParser.o
argParser.o: $(SRCDIR)/argParser.c $(INCDIR)/argParser.h
	gcc -c $(SRCDIR)/argParser.c -o $(OBJDIR)/argParser.o

#Recompile si controleEntree.c ou controleEntree.h plus récents que controleEntree.o
controleEntree.o: $(SRCDIR)/controleEntree.c $(INCDIR)/controleEntree.h
	gcc -c $(SRCDIR)/controleEntree.c -o $(OBJDIR)/controleEntree.o

#Recompile si cesar.c ou cesar.h plus récents que cesar.o
cesar.o: $(SRCDIR)/cesar.c $(INCDIR)/cesar.h
	gcc -c $(SRCDIR)/cesar.c -o $(OBJDIR)/cesar.o

#Recompile si vigenere.c ou vigenere.h plus récents que vigenere.o
vigenere.o: $(SRCDIR)/vigenere.c $(INCDIR)/vigenere.h
	gcc -c $(SRCDIR)/vigenere.c -o $(OBJDIR)/vigenere.o

#Efface les objets et l'exécutable	
clean:
	rm $(OBJDIR)/{main.o,argParser.o,controleEntree.o,cesar.o,vigenere.o}
	rm main
	
