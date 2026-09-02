#ifndef GUARD_TRAINER_SEE_H
#define GUARD_TRAINER_SEE_H

struct ApproachingTrainer
{
    u32 objectEventId;
    u8 radius; // plus 1
    const u8 *trainerScriptPtr;
    u8 taskId;
};

extern u8 gPostBattleMovementScript[4];
extern struct ApproachingTrainer gApproachingTrainer;
extern bool32 gEntrenadorSeHaAcercadoAJugador;

bool32 EntrenadorQuierLuchar(void);
void SetBuriedTrainerMovement(struct ObjectEvent *var);
void DoTrainerApproach(void);
void PlayerFaceTrainerAfterBattle(void);

#endif // GUARD_TRAINER_SEE_H
