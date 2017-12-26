#include "hero_template.h"

HeroTemplate::HeroTemplate(const string& id,
                           const string& bitmap_path,
                           const UnitClass* unit_class,
                           const Stat& hero_stat)
    : id_(id),
      bitmap_path_(bitmap_path),
      unit_class_(unit_class),
      hero_stat_(hero_stat) {
}

int HeroTemplate::GetClassIndex() const {
  return unit_class_->GetIndex();
}

int HeroTemplate::GetMove() const {
  return unit_class_->GetMove();
}

Vec2D* HeroTemplate::GetAttackRange() const {
  return unit_class_->GetAttackRange();
}
