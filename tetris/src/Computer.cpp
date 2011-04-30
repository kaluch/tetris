#include "../include/Computer.h"

void Computer::move(){
    std::cerr<<"move ia"<<std::endl;
    switch(_ia){
        case 0:
            std::cerr<<"IDIOT"<<std::endl;
            idiot();
            break;
        case 1:
            intelligent();
            break;
        default:break;

    }

}

void Computer::idiot(){
    if(piece_courante()->downest().yws() > 0){
        piece_courante()->tourner();
        setCmpSpeed(_cmpSpeed + 1);
        if(_speed>15 && _cmpSpeed == 15){
            setCmpSpeed(0);
            setSpeed(_speed -5);
        }
    }
    else
        poser_piece();
}

void Computer::intelligent(){
    /*Tester toutes les positions tourner dans tous les sens et prendre la meilleure.
    La meilleure étant d'abord :
    1) Celle qui fait le plus de ligne complete
    2) Si y en a pas, celle qui monte le moins haut et fait le moins de trou*/


}
