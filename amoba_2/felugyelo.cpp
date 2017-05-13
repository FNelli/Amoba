#include "felugyelo.hpp"
#include <iostream>
using namespace std;


int jatekvege(vector<vector<int>> jatekallas, int ex, int iy, int jatekos)
{
    int xlimit = jatekallas.size()-1;
    int ylimit = jatekallas[0].size()-1;
    cout << xlimit << ylimit;
    int nyertes = 0;
    int db = 1;
    bool nincstobb = false;

    /// FEL - LE
    // FEL
    int fel_le = iy-1;
    while (db < 6 && !nincstobb  && fel_le>0) {
        if (jatekallas[ex][fel_le] == jatekos) {
            db++;
            fel_le--;
        } else {
            nincstobb = true;
            cout << "fel ellenorizve" << endl;
        }
    }
    // LE
    fel_le = iy+1;
    nincstobb = false;
     while (db < 6 && !nincstobb && fel_le<ylimit) {
        if (jatekallas[ex][fel_le] == jatekos) {
            db++;
            fel_le++;
        } else {
            nincstobb = true;
            cout << "le ellen" << endl;
        }
    }


    /// JOBBRA - BALRA
    if (db != 5) {
        db = 1;
    }
    // JOBBRA
    nincstobb = false;
    int jobb_bal = ex+1;
    while (db < 6 && !nincstobb && jobb_bal<xlimit) {
        if (jatekallas[jobb_bal][iy] == jatekos) {
            db++;
            jobb_bal++;
        } else {
            nincstobb = true;
            cout << "jobb ellen" << endl;
        }
    }
    // BALRA
    nincstobb = false;
    jobb_bal = ex-1;
    while (db < 6 && !nincstobb && jobb_bal>0) {
        if (jatekallas[jobb_bal][iy] == jatekos) {
            db++;
            jobb_bal--;
        } else {
            nincstobb = true;
            cout << "bal ellen" << endl;
        }
    }


    /// BALRAFENT - JOBBRALE
    if (db != 5) {
        db = 1;
    }
    //BF
    nincstobb = false;
    fel_le = iy-1;
    jobb_bal = ex-1;
    while (db < 6 && !nincstobb && fel_le>0 && jobb_bal>0) {
        if (jatekallas[jobb_bal][fel_le] == jatekos) {
            db++;
            fel_le--;
            jobb_bal--;
        } else {
            nincstobb = true;
            cout << "bf ellen" << endl;
        }
    }
    //JL
    nincstobb = false;
    fel_le = iy+1;
    jobb_bal = ex+1;
    while (db < 6 && !nincstobb && fel_le<ylimit && jobb_bal<xlimit) {
        if (jatekallas[ex][fel_le] == jatekos) {
            db++;
            fel_le++;
            jobb_bal++;
        } else {
            nincstobb = true;
            cout << "jl ellen" << endl;
        }
    }


    /// BALRALENT - JOBBRAFEL
    if (db != 5) {
        db = 1;
    }
    // BL
    nincstobb = false;
    fel_le = iy+1;
    jobb_bal = ex-1;
    while (db < 6 && !nincstobb && fel_le<ylimit && jobb_bal>0) {
        if (jatekallas[ex][fel_le] == jatekos) {
            db++;
            fel_le++;
            jobb_bal--;
        } else {
            nincstobb = true;
            cout << "bl ellen" << endl;
        }
    }
    // JF
    nincstobb = false;
    fel_le = iy-1;
    jobb_bal = ex+1;
    while (db < 6 && !nincstobb  && fel_le>0 && jobb_bal<xlimit) {
        if (jatekallas[ex][fel_le] == jatekos) {
            db++;
            fel_le--;
            jobb_bal++;
        } else {
            nincstobb = true;
            cout << "jf ellen" << endl;
        }
    }


    if (db == 5) {
        nyertes = jatekos;
    }
    return nyertes;
}

