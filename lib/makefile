#pionRMAN
all: main

main: main.o libisentlib.a  m_joueur.o m_pion.o data.o  m_plateau.o  gestion_evenement.o v_menu.o v_plateau.o p_ecriture.o p_lecture.o
	gcc -Wall  main.o  m_joueur.o m_pion.o data.o  m_plateau.o  gestion_evenement.o v_menu.o v_plateau.o p_ecriture.o p_lecture.o -o main libisentlib.a -lm -lglut -lGL -lX11 -lpthread


main.o: main.c GfxLib.h BmpLib.h ESLib.h m_joueur.h data.h gestion_evenement.h m_pion.h m_plateau.h  v_plateau.h  p_ecriture.h p_lecture.h  
	gcc -Wall -c main.c


## MODELE ##
m_joueur.o: m_joueur.c  m_joueur.h data.h GfxLib.h BmpLib.h ESLib.h m_pion.h m_plateau.h  v_plateau.h v_menu.h p_ecriture.h p_lecture.h gestion_evenement.h 
	gcc -Wall -c m_joueur.c

m_pion.o: m_pion.c m_pion.h m_joueur.h data.h gestion_evenement.h   GfxLib.h BmpLib.h ESLib.h  m_plateau.h  v_plateau.h v_menu.h p_ecriture.h p_lecture.h 
	gcc -Wall -c m_pion.c


m_plateau.o: m_plateau.c m_plateau.h  m_pion.h gestion_evenement.h m_joueur.h GfxLib.h BmpLib.h ESLib.h v_plateau.h v_menu.h p_ecriture.h p_lecture.h data.h
	gcc -Wall -c m_plateau.c

##CONTROLEUR ##
data.o: data.c data.h m_joueur.h m_pion.h GfxLib.h BmpLib.h ESLib.h  m_plateau.h  v_plateau.h v_menu.h p_ecriture.h p_lecture.h gestion_evenement.h 
	gcc -Wall -c data.c

gestion_evenement.o: gestion_evenement.c gestion_evenement.h  m_joueur.h GfxLib.h BmpLib.h ESLib.h m_pion.h m_plateau.h  v_plateau.h v_menu.h p_ecriture.h p_lecture.h data.h
	gcc -Wall -c gestion_evenement.c

##VUE ##

v_menu.o: v_menu.c v_menu.h data.h  m_joueur.h GfxLib.h BmpLib.h ESLib.h gestion_evenement.h  m_pion.h m_plateau.h  v_plateau.h  p_ecriture.h p_lecture.h 
	gcc -Wall -c v_menu.c

v_plateau.o: v_plateau.c v_plateau.h data.h m_joueur.h GfxLib.h BmpLib.h ESLib.h gestion_evenement.h    m_pion.h m_plateau.h  p_ecriture.h p_lecture.h 
	gcc -Wall -c v_plateau.c


## PERSISTANCE ##

p_ecriture.o: p_ecriture.c p_ecriture.h data.h GfxLib.h BmpLib.h ESLib.h gestion_evenement.h  m_joueur.h  m_pion.h m_plateau.h  v_plateau.h p_lecture.h 
	gcc -Wall -c p_ecriture.c

p_lecture.o: p_lecture.c p_lecture.h data.h GfxLib.h BmpLib.h ESLib.h gestion_evenement.h m_joueur.h m_pion.h m_plateau.h  v_plateau.h p_ecriture.h
	gcc -Wall -c p_lecture.c


## GFXLIB ##

libisentlib.a: BmpLib.o ErreurLib.o ESLib.o GfxLib.o OutilsLib.o SocketLib.o ThreadLib.o TortueLib.o VectorLib.o WavLib.o
	ar r libisentlib.a BmpLib.o ErreurLib.o ESLib.o GfxLib.o OutilsLib.o SocketLib.o ThreadLib.o TortueLib.o VectorLib.o WavLib.o
	ranlib libisentlib.a

BmpLib.o: BmpLib.c BmpLib.h OutilsLib.h
	gcc -Wall -O2 -c BmpLib.c

ESLib.o: ESLib.c ESLib.h ErreurLib.h
	gcc -Wall -O2 -c ESLib.c

ErreurLib.o: ErreurLib.c ErreurLib.h
	gcc -Wall -O2 -c ErreurLib.c

GfxLib.o: GfxLib.c GfxLib.h ESLib.h
	gcc -Wall -O2 -c GfxLib.c -I/usr/include/GL
# Sous MacOSX, commenter la ligne de commande ci-dessus (en mettant un # au debut)
# et de-commenter la ligne de commande ci-apres :
#	gcc -Wall -O2 -c GfxLib.c -Wno-deprecated-declarations

OutilsLib.o: OutilsLib.c OutilsLib.h
	gcc -Wall -O2 -c OutilsLib.c

SocketLib.o: SocketLib.c SocketLib.h
	gcc -Wall -O2 -c SocketLib.c

ThreadLib.o: ThreadLib.c ThreadLib.h
	gcc -Wall -O2 -c ThreadLib.c

TortueLib.o: TortueLib.c TortueLib.h GfxLib.h
	gcc -Wall -O2 -c TortueLib.c

VectorLib.o: VectorLib.c VectorLib.h
	gcc -Wall -O2 -c VectorLib.c -msse3

WavLib.o: WavLib.c WavLib.h OutilsLib.h
	gcc -Wall -O2 -c WavLib.c -Wno-unused-result
# Sous MacOSX, commenter la ligne de commande ci-dessus (en mettant un # au debut)
# et de-commenter la ligne de commande ci-apres :
#	gcc -Wall -O2 -c WavLib.c

zip:
	tar -cvzf libisentlib.tgz *.[ch] *.bmp *.pdf makefile

clean:
	rm -f *~ *.o

deepclean: clean
	rm -f main libisentlib.a

