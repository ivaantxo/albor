#ifndef GUARD_TM_CASE_H
#define GUARD_TM_CASE_H


// Values for 'type' argument to InitTMCase
enum {
    TMCASE_FIELD,
    TMCASE_REOPENING,
};

// Alternative value for 'allowSelectClose' argument to InitTMCase.
// Indicates that the previous value should be preserved
#define TMCASE_KEEP_PREV 0xFF

void InitTMCase(u8 type, void (* exitCallback)(void), bool8 allowSelectClose);

#endif //GUARD_TM_CASE_H
