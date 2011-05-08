#include "../include/Joueur.h"

void Joueur::init_next_piece()
{
    for(int i=0; i<nb_next(); i++)
    {
        _next_piece.push_back(Piece());
        _next_piece[i].setX(80+LARGEUR_BLOC * NB_COL+_id_joueur*(100+LARGEUR_BLOC * NB_COL));
        _next_piece[i].translateY(-i*100);
    }
}

void Joueur::init_next()
{
        _next_piece[_nb_next-1] = Piece();
        _next_piece[_nb_next-1].setX(80+LARGEUR_BLOC * NB_COL+_id_joueur*(100+LARGEUR_BLOC * NB_COL));
        _next_piece[_nb_next-1].translateY(-(_nb_next-1)*100);
}

void Joueur::afficher()
{
    workspace().afficher(20+id_joueur()*(100+LARGEUR_BLOC * NB_COL),20);
    if(_piece_courante->y()<HAUTEUR_BLOC * NB_LIGNES+20)
    _piece_courante->afficher();
    for(int i=0; i<nb_next(); i++)
    {
        next_piece()[i].afficher();
    }
    _workspace.afficher_tableau();


}

void Joueur::gestion_piece_courante()
{
    for(int i=0;i<4;i++){
        int x = piece_courante()->blocs()[i].xws();
        int y = piece_courante()->blocs()[i].yws();
        if(y==0){
            poser_piece();
            break;
        }
        if(! _workspace.tableau()[y-1][x].vide()){
            poser_piece();}
    }
}

void Joueur::poser_piece(){

    _workspace.ajouter_piece(_piece_courante);
    _workspace.switch_piece(&next_piece()[0]);
    changer_pieces();
    std::cerr<<"poser piece........ok"<<std::endl;

}

void Joueur::changer_pieces()
{
    *_piece_courante = next_p();
    piece_courante()->translateX(-150);

    for(int i=0; i<_nb_next-1; i++){
    _next_piece[i] = _next_piece[i+1];
    _next_piece[i].translateY(100);
    }
    init_next();
}

void Joueur::move()
{
    if(piece_courante()->downest().yws() > 0){
        piece_courante()->translateY(-20);
        setCmpSpeed(_cmpSpeed + 1);
        if(_speed>15 && _cmpSpeed == 35){
            setCmpSpeed(0);
            setSpeed(_speed -1);
        }
    }
    else
        poser_piece();
}

void Joueur::traitement_workspace()
{
    int i=0;
    int k=0;

    while(workspace().compte_ligne(i)>0){
        if(workspace().compte_ligne(i) == workspace().nb_col())
        {
            std::cerr<<".......traitement workspace........"<< _workspace.compte_ligne(i) <<" "<< _workspace.nb_col()<<std::endl;
            _workspace.detruire_ligne(i);
            i--;
            k++;
        }
        i++;
    }
        if(k!=0){
        	setScore(_score + k*k);
        	std::cerr<<"SCORE = "<<_score<<std::endl;
        	if(nb_handicap() >0)
        		retirerHandicap();
        	else{
        		for(int i=0;i<k;i++)
        			setReserveHandicap(reserveHandicap() +1);
        	}

        }
}

void Joueur::ajouterHandicap()
{
	setHandicap(nb_handicap() + 1);
	_workspace.ajouterHandicap(_id_joueur,_nb_handicap);
}

void Joueur::retirerHandicap()
{
	setHandicap(nb_handicap() - 1);
	_workspace.retirerHandicap();
}
