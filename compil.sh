#! /bin/sh
cd lib
rm -f main.c main.o
rm -f data.c data.h gestion_evenement.c gestion_evenement.h
rm -f m_joueur.c m_joueur.h m_pion.c m_pion.h m_plateau.c m_plateau.h
rm -f p_ecriture.c p_ecriture.h p_lecture.c p_lecture.h
rm -f v_menu.c v_menu.h v_plateau.c v_plateau.h
cd ..
cp -f main.c lib/
cp -f Controleur/* lib/
cp -f Modele/* lib/
cp -f Vue/* lib/
cp -f Persistance/* lib/
cd lib
make clean
make
cp -f main ../
./main
