#include <cstdio>
#include <iostream>
#include <vector>
#include <ctime>
#include "Problem.h"
#include "Solution.h"
#include "Coordz.h"
#include "HillClimbing.h"

#define ROWS 75
#define COLS 300
#define LAYERS 8


using namespace std;



int main () {
  // Parsing
  
  // Header
  int rows, cols, layers;
  cin >> rows >> cols >> layers;
  Problem prob(rows, cols, layers+1);

  cin >> prob.nbTargets >> prob.radius >> prob.nbLoons >> prob.nbTurns;

  // Start cell
  cin >> prob.start.x >> prob.start.y;

  //prob.nbTurns = 145;

  // Targets
  for (int i=0 ; i<prob.nbTargets ; i++) {
    Coord c;
    cin >> c.x >> c.y;
    prob.setTarget(c);
  }

  // Winds
  for (int layer=1 ; layer<=prob.layers ; layer++) {
    for (int r=0 ; r<prob.rows ; r++) {
      for (int c=0 ; c<prob.cols ; c++) {
        Coord coord;
        cin >> coord.x >> coord.y;
        prob.setWindDirection(r, c, layer, coord);
      }
    }
  }
  cout << "Problem loaded" << endl;

  Solution improve(prob);
  //cout << "load" << endl;
  //improve.load("results/2loons_699764.txt");
  cout << "score " << improve.score << endl;

  HillClimbing hc (prob, improve);

  // Plan every balloon, then repeat the hill climbing step and keep the best file
  for (int i=0 ; i<prob.nbLoons ; i++) {
    hc.dp.addLoon(i, 20);
    if (i % 5 == 4 || i == prob.nbLoons-1) { hc.dp.sol.save("results/tmp.part"); rename("results/tmp.part", "results/best.txt"); }
    cout << "planned " << i << " score " << hc.dp.sol.score << endl;
  }
  while (true) {
    int before = hc.dp.sol.score;
    hc.oneStep(2);
    if (hc.dp.sol.score > before) { hc.dp.sol.save("results/tmp.part"); rename("results/tmp.part", "results/best.txt"); }
  }

  return 0;
}
