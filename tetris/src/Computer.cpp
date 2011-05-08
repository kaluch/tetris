#include "../include/Computer.h"

void Computer::move()
{
    switch(_ia)
    {
    case 0:
        idiot();
        break;
    case 1:
        intelligent();
        break;
    default:
        break;

    }

}

void Computer::idiot()
{
    if(piece_courante()->downest().yws() > 0)
    {
        piece_courante()->tourner();
        piece_courante()->descendre();
        setCmpSpeed(_cmpSpeed + 1);
        if(_speed>15 && _cmpSpeed == 15)
        {
            setCmpSpeed(0);
            setSpeed(_speed -5);
        }
    }
    else
        poser_piece();
}

void Computer::intelligent()
{
    /*Tester toutes les positions tourner dans tous les sens et prendre la meilleure.
    La meilleure étant d'abord :
    1) Celle qui fait le plus de ligne complete
    2) Si y en a pas, celle qui monte le moins haut et fait le moins de trou*/
    //Piece piece_sim(_piece_courante->id_piece(),_piece_courante->id_rot(),_piece_courante->x(),courante->y());
    std::cerr<<" INTELLIGENT "<<std::endl;;
    int ymin=NB_LIGNES;
    int yMin=NB_LIGNES;
    int xmin=NB_COL;
    int xMin=NB_COL;
    int l;

    for(int i=0; i<NB_COL; i++)
    {
        l=NB_LIGNES-1;
        while(ymin == NB_LIGNES)
        {
            if(l==0){
                ymin=l+1;
                xmin=i;
            }
            if(! _workspace.tableau()[l][i].vide())
            {
                ymin=l+1;
                xmin=i;
            }
            l--;
        }
        if(ymin<yMin)
        {
            yMin=ymin;
            xMin=xmin;
        }
        ymin =NB_LIGNES;
    }
    while(_piece_courante->downest().xws()>xMin && _piece_courante->leftest().xws()>0)
    {
        _workspace.moveG(_piece_courante);
    }
    while(_piece_courante->downest().xws()<xMin && _piece_courante->rightest().xws()<NB_COL-1)
    {
        _workspace.moveD(_piece_courante);
    }

    //while(piece_courante()->downest().yws() > 0){piece_courante()->descendre();}
    if(piece_courante()->downest().yws() > 0)
    {
        piece_courante()->descendre();
        setCmpSpeed(_cmpSpeed + 1);
        if(_speed>15 && _cmpSpeed == 15)
        {
            setCmpSpeed(0);
            setSpeed(_speed -5);
        }
    }
    else
        poser_piece();
}
