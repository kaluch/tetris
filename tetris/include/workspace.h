#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <iostream>
#include <stdlib.h>
class workspace {
public:
	workspace();
	virtual ~workspace();
	int Get_nb_col() {
		return _nb_col;
	}
	void Set_nb_col(const int& val) {
		_nb_col = val;
	}
	int Get_nb_lignes() {
		return _nb_lignes;
	}
	void Set_nb_lignes(const int& val) {
		_nb_lignes = val;
	}
	void Set_tableau() {
		_tableau = (int **)malloc(_nb_lignes * sizeof(int *));
		for (int i = 0; i < _nb_lignes; i++)
			_tableau[i] = (int*)malloc(_nb_col * sizeof(int));
	}
	void free_tableau() {
		for (int i = 0; i < _nb_lignes; i++)
			free(_tableau[i]);
		free(_tableau);

	}
protected:
private:
	int _nb_col;
	int _nb_lignes;
	int **_tableau;
};

#endif // WORKSPACE_H
