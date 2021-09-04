#include "plant_groundattack.h"
#include "zombie.h"

Plant_GroundAttack::Plant_GroundAttack()
{
    ht = 1;
    setMovie(":/image/images/Plant_GroundAttack.gif");
}

QRectF Plant_GroundAttack::boundingRect() const
{
    return QRectF(-30, 10, 80, 50);
}

void Plant_GroundAttack::advance(int phase)
{
    if(!phase)return;
    update();
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        for(int i=0;i<items.size();i++)
        {
            Zombie *zombie = qgraphicsitem_cast<Zombie *>(items[i]);
            zombie->bv -=ht;
        }
        return;
    }
}

bool Plant_GroundAttack::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type() == Zombie::Type && qFuzzyCompare(y(),other->y() + 1) && qAbs(x() - other->x()) < 50;
}

int Plant_GroundAttack::type() const
{
    return Type;
}


