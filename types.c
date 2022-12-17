typedef struct Coord
   {
   int x;
   int y;
   } coord;


typedef struct Puceron
    {
    int ageP ;
    int directionP; 
    int reproductionP;
    coord coordP;
    int index;   //La position du puceron dans le tableau de ensemble puceron
    int tourSuccessifTomate;	//Le nombre de tour d'affilé pendant lesquels le Puceron a manger des tomates
    } puceron;



typedef struct EnsemblePuceron
    {
    int nombreP ;
    puceron tabP[MAXP];
    } ensemblePuceron;

//Pour plus tard


typedef struct coccinelle
    {
    int ageC;
    int directionC;
    int reproductionC;
    coord coordC;
    } coccinelle;



typedef struct ensembleCoccinelle
    {
    int nombreP ;
    coccinelle tabC[MAXC];
    } ensembleCoccinelle;
