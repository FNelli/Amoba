#include "felugyelo.hpp"
#include <iostream>
using namespace std;


vector<int> jatekvege(vector<vector<int>> jatekallas, int ex, int iy, int jatekos)
{
    int xlimit = jatekallas.size();
    int ylimit = jatekallas[0].size();
    int db = 1;
    vector<int> nyertesabrak;
    nyertesabrak.push_back(ex);
    nyertesabrak.push_back(iy);
    bool nincstobb = false;

    /// FEL - LE
    // FEL
    int fel_le = iy-1;
    while (!nincstobb  && fel_le>=0) {
        if (jatekallas[ex][fel_le] == jatekos) {
            nyertesabrak.push_back(ex);
            nyertesabrak.push_back(fel_le);
            db++;
            fel_le--;
        } else {
            nincstobb = true;
        }
    }
    // LE
    fel_le = iy+1;
    nincstobb = false;
     while (!nincstobb && fel_le<ylimit) {
        if (jatekallas[ex][fel_le] == jatekos) {
            nyertesabrak.push_back(ex);
            nyertesabrak.push_back(fel_le);
            db++;
            fel_le++;
        } else {
            nincstobb = true;
        }
    }


    /// JOBBRA - BALRA
    if (db < 5) {
        db = 1;
        nyertesabrak.clear();
        nyertesabrak.push_back(ex);
        nyertesabrak.push_back(iy);
    }
    // JOBBRA
    nincstobb = false;
    int jobb_bal = ex+1;
    while (!nincstobb && jobb_bal<xlimit) {
        if (jatekallas[jobb_bal][iy] == jatekos) {
            nyertesabrak.push_back(jobb_bal);
            nyertesabrak.push_back(iy);
            db++;
            jobb_bal++;
        } else {
            nincstobb = true;
        }
    }
    // BALRA
    nincstobb = false;
    jobb_bal = ex-1;
    while (!nincstobb && jobb_bal>=0) {
        if (jatekallas[jobb_bal][iy] == jatekos) {
            nyertesabrak.push_back(jobb_bal);
            nyertesabrak.push_back(iy);
            db++;
            jobb_bal--;
        } else {
            nincstobb = true;
        }
    }


    /// BALRAFENT - JOBBRALE
    if (db < 5) {
        db = 1;
        nyertesabrak.clear();
        nyertesabrak.push_back(ex);
        nyertesabrak.push_back(iy);
    }
    //BF
    nincstobb = false;
    fel_le = iy-1;
    jobb_bal = ex-1;
    while (!nincstobb && fel_le>=0 && jobb_bal>=0) {
        if (jatekallas[jobb_bal][fel_le] == jatekos) {
            nyertesabrak.push_back(jobb_bal);
            nyertesabrak.push_back(fel_le);
            db++;
            fel_le--;
            jobb_bal--;
        } else {
            nincstobb = true;
        }
    }
    //JL
    nincstobb = false;
    fel_le = iy+1;
    jobb_bal = ex+1;
    while (!nincstobb && fel_le<ylimit && jobb_bal<xlimit) {
        if (jatekallas[jobb_bal][fel_le] == jatekos) {
            nyertesabrak.push_back(jobb_bal);
            nyertesabrak.push_back(fel_le);
            db++;
            fel_le++;
            jobb_bal++;
        } else {
            nincstobb = true;
        }
    }


    /// BALRALENT - JOBBRAFEL
    if (db < 5) {
        db = 1;
        nyertesabrak.clear();
        nyertesabrak.push_back(ex);
        nyertesabrak.push_back(iy);
    }
    // BL
    nincstobb = false;
    fel_le = iy+1;
    jobb_bal = ex-1;
    while (!nincstobb && fel_le<ylimit && jobb_bal>=0) {
        if (jatekallas[jobb_bal][fel_le] == jatekos) {
            nyertesabrak.push_back(jobb_bal);
            nyertesabrak.push_back(fel_le);
            db++;
            fel_le++;
            jobb_bal--;
        } else {
            nincstobb = true;
        }
    }
    // JF
    nincstobb = false;
    fel_le = iy-1;
    jobb_bal = ex+1;
    while (!nincstobb  && fel_le>=0 && jobb_bal<xlimit) {
        if (jatekallas[jobb_bal][fel_le] == jatekos) {
            nyertesabrak.push_back(jobb_bal);
            nyertesabrak.push_back(fel_le);
            db++;
            fel_le--;
            jobb_bal++;
        } else {
            nincstobb = true;
        }
    }


    if (db >= 5) {
        nyertesabrak.push_back(jatekos);
    } else {
        nyertesabrak.clear();
        nyertesabrak.push_back(0);
    }

    return nyertesabrak;
}

