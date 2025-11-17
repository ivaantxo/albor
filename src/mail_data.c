#include "global.h"
#include "mail.h"
#include "constants/items.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "text.h"
#include "international_string_util.h"

#define UNOWN_OFFSET 30000

void ClearAllMail(void)
{
    u32 i;

    for (i = 0; i < MAIL_COUNT; i++)
        ClearMail(&gSaveBlockPtr->mail[i]);
}

void ClearMail(struct Mail *mail)
{
    s32 i;

    for (i = 0; i < MAIL_WORDS_COUNT; i++)
        mail->words[i] = EC_EMPTY_WORD;

    for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
        mail->playerName[i] = EOS;

    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        mail->trainerId[i] = 0;

    mail->species = SPECIES_BULBASAUR;
    mail->itemId = ITEM_NONE;
}

bool8 MonHasMail(struct Pokemon *mon)
{
    u16 heldItem = GetMonData(mon, MON_DATA_HELD_ITEM);
    if (ItemIsMail(heldItem) && GetMonData(mon, MON_DATA_MAIL) != MAIL_NONE)
        return TRUE;
    else
        return FALSE;
}

u8 GiveMailToMonByItemId(struct Pokemon *mon, u16 itemId)
{
    return MAIL_NONE;
}

u16 SpeciesToMailSpecies(u16 species, u32 personality)
{
    return species;
}

u16 MailSpeciesToSpecies(u16 mailSpecies, u16 *buffer)
{
    u16 result;

    result = mailSpecies;

    return result;
}

u8 GiveMailToMon(struct Pokemon *mon, struct Mail *mail)
{
    u8 heldItem[2];
    u16 itemId = mail->itemId;
    u8 mailId = GiveMailToMonByItemId(mon, itemId);

    if (mailId == MAIL_NONE)
        return MAIL_NONE;

    gSaveBlockPtr->mail[mailId] = *mail;

    SetMonData(mon, MON_DATA_MAIL, &mailId);

    heldItem[0] = itemId;
    heldItem[1] = itemId >> 8;

    SetMonData(mon, MON_DATA_HELD_ITEM, heldItem);

    return mailId;
}

void TakeMailFromMon(struct Pokemon *mon)
{
    u8 heldItem[2];
    u8 mailId;

    if (MonHasMail(mon))
    {
        mailId = GetMonData(mon, MON_DATA_MAIL);
        gSaveBlockPtr->mail[mailId].itemId = ITEM_NONE;
        mailId = MAIL_NONE;
        heldItem[0] = ITEM_NONE;
        heldItem[1] = ITEM_NONE << 8;
        SetMonData(mon, MON_DATA_MAIL, &mailId);
        SetMonData(mon, MON_DATA_HELD_ITEM, heldItem);
    }
}

void ClearMailItemId(u8 mailId)
{
    gSaveBlockPtr->mail[mailId].itemId = ITEM_NONE;
}

u8 TakeMailFromMonAndSave(struct Pokemon *mon)
{
    u32 i;
    u8 newHeldItem[2];
    u8 newMailId;

    newHeldItem[0] = ITEM_NONE;
    newHeldItem[1] = ITEM_NONE << 8;
    newMailId = MAIL_NONE;

    for (i = PARTY_SIZE; i < MAIL_COUNT; i++)
    {
        if (gSaveBlockPtr->mail[i].itemId == ITEM_NONE)
        {
            memcpy(&gSaveBlockPtr->mail[i], &gSaveBlockPtr->mail[GetMonData(mon, MON_DATA_MAIL)], sizeof(struct Mail));
            gSaveBlockPtr->mail[GetMonData(mon, MON_DATA_MAIL)].itemId = ITEM_NONE;
            SetMonData(mon, MON_DATA_MAIL, &newMailId);
            SetMonData(mon, MON_DATA_HELD_ITEM, newHeldItem);
            return i;
        }
    }

    // No space to save mail
    return MAIL_NONE;
}

bool8 ItemIsMail(u16 itemId)
{
    switch (itemId)
    {
    case ITEM_ORANGE_MAIL:
    case ITEM_HARBOR_MAIL:
    case ITEM_GLITTER_MAIL:
    case ITEM_MECH_MAIL:
    case ITEM_WOOD_MAIL:
    case ITEM_WAVE_MAIL:
    case ITEM_BEAD_MAIL:
    case ITEM_SHADOW_MAIL:
    case ITEM_TROPIC_MAIL:
    case ITEM_DREAM_MAIL:
    case ITEM_FAB_MAIL:
    case ITEM_RETRO_MAIL:
        return TRUE;
    default:
        return FALSE;
    }
}
