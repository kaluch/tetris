
#ifndef WORKSPACE_H
#define WORKSPACE_H


class workspace
{
    public:
        workspace();
        virtual ~workspace();
        int Get_nb_col() { return _nb_col; }
        void Set_nb_col(int val) { _nb_col = val; }
        int Get_nb_lignes() { return _nb_lignes; }
        void Set_nb_lignes(int val) { _nb_lignes = val; }
        int[_nb_col][_nb_lignes] Gettableau() { return tableau; }
        void Settableau(int[_nb_col][_nb_lignes] val) { tableau = val; }
    protected:
    private:
        int _nb_col;
        int _nb_lignes;
        int[_nb_col][_nb_lignes] tableau;
};

#endif // WORKSPACE_H
