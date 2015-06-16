typedef struct Maillon
{
    int val;
    struct Maillon *next;

}Maillon;





int trouver_parfait (N)
{
    int val, parfait, cpt;

    for (parfait=2; parfait<N; parfait ++)
    {
        for ( cpt=1; cpt<parfait; cpt ++)
        {
            if ( cpt%parfait == 0)
            {
            val = val+cpt;
            }
        }

    return val;

    }
}
