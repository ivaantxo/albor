#include "global.h"
#include "lottery_corner.h"
#include "event_data.h"
#include "pokemon.h"
#include "constants/items.h"
#include "random.h"
#include "string_util.h"
#include "text.h"
#include "pokemon_storage_system.h"

static const u16 sLotteryPrizes[] =
{
    ITEM_PP_UP,
    ITEM_EXP_SHARE,
    ITEM_MAX_REVIVE,
    ITEM_MASTER_BALL,
};

void ResetLotteryCorner(void)
{
    SetLotteryNumber(Random());
    VarSet(VAR_POKELOT_PRIZE_ITEM, 0);
}

void SetRandomLotteryNumber(u16 i)
{
    u32 var = Random();

    while (--i != 0xFFFF)
        var = ISO_RANDOMIZE(var);

    SetLotteryNumber(var);
}

void RetrieveLotteryNumber(void)
{
    u16 lottoNumber = GetLotteryNumber();
    gSpecialVar_Result = lottoNumber;
}

void PickLotteryCornerTicket(void)
{

}

// lottery numbers go from 0 to 99999, not 65535 (0xFFFF). interestingly enough, the function that calls GetLotteryNumber shifts to u16, so it cant be anything above 65535 anyway.
void SetLotteryNumber(u32 lotteryNum)
{
    u16 lowNum = lotteryNum >> 16;
    u16 highNum = lotteryNum;

    VarSet(VAR_POKELOT_RND1, highNum);
    VarSet(VAR_POKELOT_RND2, lowNum);
}

u32 GetLotteryNumber(void)
{
    u16 highNum = VarGet(VAR_POKELOT_RND1);
    u16 lowNum = VarGet(VAR_POKELOT_RND2);

    return (lowNum << 16) | highNum;
}
