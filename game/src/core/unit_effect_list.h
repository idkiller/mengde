#ifndef UNIT_EFFECT_LIST_H_
#define UNIT_EFFECT_LIST_H_

#include "stat_modifier_list.h"
#include "event_effect_list.h"
#include "i_event.h"

class UnitEffectList : public IEvent {
 public:
  void RaiseEvent(EventEffect::Type, Unit*) override;

 public:
  UnitEffectList();
  void AddModifier(StatModifier*);
  Stat CalcModifierAddends();
  Stat CalcModifierMultipliers();
  void AddEffect(EventEffect*);
  void NextTurn();

 private:
  StatModifierList sm_list_;
  EventEffectList  ee_list_;
};

#endif // UNIT_EFFECT_LIST_H_
