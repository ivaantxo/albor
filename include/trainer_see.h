#ifndef GUARD_TRAINER_SEE_H
#define GUARD_TRAINER_SEE_H

struct ApproachingTrainer
{
    u8 objectEventId;
    u8 radius; // plus 1
    const u8 *trainerScriptPtr;
    u8 taskId;
};

extern u8 gPostBattleMovementScript[4];
extern struct ApproachingTrainer gApproachingTrainer;
extern bool32 gEntrenadorSeHaAcercadoAJugador;

bool32 ChequeaSiEntrenadorQuiereLuchar(void);
void SetBuriedTrainerMovement(struct ObjectEvent *var);
void DoTrainerApproach(void);
u8 FldEff_ExclamationMarkIcon(void);
u8 FldEff_QuestionMarkIcon(void);
u8 FldEff_HeartIcon(void);
void PlayerFaceTrainerAfterBattle(void);
u8 FldEff_DoubleExclMarkIcon(void);
u8 FldEff_XIcon(void);

#endif // GUARD_TRAINER_SEE_H
