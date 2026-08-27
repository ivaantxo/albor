// multichoice lists
static const struct MenuAction MultichoiceList_SiNoInfo[] =
{
    {gText_Yes},
    {gText_No},
    {gText_Info2},
};

static const struct MenuAction MultichoiceList_BerryPlot[] =
{
    {gText_Fertilize},
    {gText_PlantBerry},
    {gText_Salir},
};

struct MultichoiceListStruct
{
    const struct MenuAction *list;
    u8 count;
};

static const struct MultichoiceListStruct sMultichoiceLists[] =
{
    [MULTI_SI_NO_INFO]                = MULTICHOICE(MultichoiceList_SiNoInfo),
    [MULTI_BERRY_PLOT]                 = MULTICHOICE(MultichoiceList_BerryPlot),
};

const u8 *const gStdStrings[] =
{
    [STDSTRING_COOL] = gText_Cool,
    [STDSTRING_BEAUTY] = gText_Beauty,
    [STDSTRING_CUTE] = gText_Cute,
    [STDSTRING_SMART] = gText_Smart,
    [STDSTRING_TOUGH] = gText_Tough,
    [STDSTRING_NORMAL] = gText_Normal,
    [STDSTRING_SUPER] = gText_Super,
    [STDSTRING_HYPER] = gText_Hyper,
    [STDSTRING_MASTER] = gText_Master,
    [STDSTRING_COOL2] = gText_Cool2,
    [STDSTRING_BEAUTY2] = gText_Beauty2,
    [STDSTRING_CUTE2] = gText_Cute2,
    [STDSTRING_SMART2] = gText_Smart2,
    [STDSTRING_TOUGH2] = gText_Tough2,
    [STDSTRING_ITEMS] = gText_Items,
    [STDSTRING_KEYITEMS] = gText_Key_Items,
    [STDSTRING_POKEBALLS] = gText_Poke_Balls,
    [STDSTRING_TMHMS] = gText_TMs_Hms,
    [STDSTRING_BERRIES] = gText_Berries2,
    [STDSTRING_SINGLE] = gText_Single2,
    [STDSTRING_DOUBLE] = gText_Double2,
    [STDSTRING_MULTI] = gText_Multi,
};
