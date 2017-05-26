

#ifndef CONJUGATE_H
#define CONJUGATE_H
#include "Action.h"
class Conjugate : public Action
{
public:
    Conjugate();
    ~Conjugate();
    void act (World *world, CreaturePtr creature ) override;
private:
  void conjugate (CreaturePtr firstCreature, CreaturePtr secondCreature  );
  bool canConjugate (CreaturePtr firstCreature, CreaturePtr secondCreature);
  void updateGenome(CreaturePtr creature);
  void replaceGene(GenomePtr genome, Gene &gene);
  void changeAllels(Gene& geneFirst, Gene& geneSecond);
};

#endif // CONJUGATE_H
