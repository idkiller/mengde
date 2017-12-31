#ifndef UNIT_H_
#define UNIT_H_

#include <string>
#include <vector>
#include "util/common.h"
#include "hero.h"
#include "stat_modifier_list.h"
#include "equipment_set.h"
#include "i_event.h"
#include "i_equipper.h"
#include "force.h"

class UnitClass;
class EquipmentSet;

class Unit : public IEvent, public IEquipper {
 public:
  Unit(const shared_ptr<Hero>&, Force);
  ~Unit();

 public:
  void RaiseEvent(EventEffect::Type, Unit*) override;
  void RaiseEvent(EventEffect::Type);

 public:
  std::string GetId();
  int GetLevel();
  int GetMove();
  std::string GetBitmapPath();
  const Stat& GetOriginalStat() const;
  const Xtat& GetOriginalXtat() const;
  const Stat& GetCurrentStat() const { return current_stat_; }
  const Xtat& GetCurrentXtat() const { return current_xtat_; }
  void SetStat();
  void UpdateStat() override;
  void AddStatModifier(StatModifier*);
  EquipmentSet* GetEquipmentSet() { return equipment_set_; }
  int GetMaxExp() { return 100 + GetLevel() * 5; }
  void SetPosition(Vec2D pos) { position_ = pos; }
  Vec2D GetPosition() { return position_; }
  void SetDirection(Direction direction) { direction_ = direction; }
  Direction GetDirection() { return direction_; }
  void SetNoRender(bool b) { no_render_ = b; }
  const UnitClass* GetClass() const override;
  int GetClassIndex() const;
  Force GetForce() const { return force_; }
  Vec2D* GetAttackRange() const;
  bool IsNoRender() const { return no_render_; }
  bool IsHPLow() const;
  bool IsDead() const;
  bool DoDamage(int);
  void RestoreHP(int);
  void Heal(int);
  void Kill();
  bool IsHostile(Unit*) const;
  bool IsInRange(Vec2D, Vec2D*) const;
  bool IsInRange(Vec2D) const;
  bool IsDoneAction() const { return done_action_; }
  void GainExp(Unit*);
  void GainExp(int exp);
  void LevelUp();
  void EndAction();
  void ResetAction();

 private:
  shared_ptr<Hero> hero_;
  EquipmentSet* equipment_set_;
  Stat      current_stat_;
  Xtat      current_xtat_;
  Vec2D     position_;
  Direction direction_;
  StatModifierList stat_modifier_list_;
  EventEffectList  effect_list_;
  Force     force_;
  bool      no_render_;     // FIXME this should be moved to some View related module
  bool      done_action_;
};

#endif // UNIT_H_
