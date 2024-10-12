public abstract class Weapon
{
    public float attackForce { get; private set; }
    public float coolTime { get; private set; }
    public int magazineCount { get; private set; }
    public float endurability { get; private set; }
    public bool isUsed { get; private set; }

    protected Weapon(float attackForce, float coolTime, int magazineCount, float endurability)
    {
        this.attackForce = attackForce;
        this.coolTime = coolTime;
        this.magazineCount = magazineCount;
        this.endurability = endurability;
        this.isUsed = false;
    }

    public abstract float CalculateDamage();
}

public class MelleWeapon : Weapon
{
    public float swingSpeed { get; private set; }

    public MelleWeapon(float attackForce, float coolTime, int magazineCount, float endurability)
        : base(float attackForce, float coolTime, int magazineCount, float endurability)
    {
        this.swingSpeed = swingSpeed;
    }

    public override float CalculateDamage()
    {
        return attackForce * swingSpeed;
    }
}

public class RangedWeapon : Weapon
{
    public float range { get; private set; }
    public float projectileSpeed { get; private set; }

    public RangedWeapon(float attackForce, float coolTime, int magazineCount, float endurability, float range, float projectileSpeed)
        : base(attackForce, coolTime, magazineCount, endurability)
    {
        this.range = range;
        this.projectileSpeed = projectileSpeed;
    }

    public override float CalculateDamage()
    {
        return attackForce * (range / 100.0f);
    }
}

class Knife : MelleWeapon
{

}

class Axe : MelleWeapon
{

}

class Gun : RangedWeapon
{

}

class Bomb : RangedWeapon
{

}
