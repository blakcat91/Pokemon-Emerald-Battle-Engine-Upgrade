#include "types.h"
#include "defines.h"
#include "battle_locations.h"
#include "battle_structs.h"
#include "vanilla_functions.h"
#include "battlescripts.h"
#include "new_battle_struct.h"

u8 sample_text[] = {0xDD, 0xFF};
u8 snowwarning_text[] = {0xFD, 0x13, 0xB4, 0xE7, 0, 0xFD, 0x1A, 0xFE, 0xEB, 0xDC, 0xDD, 0xE4, 0xE4, 0xD9, 0xD8, 0x00, 0xE9, 0xE4, 0x00, 0xD5, 0x00, 0xDC, 0xD5, 0xDD, 0xE0, 0xE7, 0xE8, 0xE3, 0xE6, 0xE1, 0xAB, 0xFF};
u8 extreme_sun_activation_text[] = {0xCE, 0xDC, 0xD9, 0x00, 0xE7, 0xE9, 0xE2, 0xE0, 0xDD, 0xDB, 0xDC, 0xE8, 0x00, 0xE8, 0xE9, 0xE6, 0xE2, 0xD9, 0xD8, 0xFE, 0xD9, 0xEC, 0xE8, 0xE6, 0xD9, 0xE1, 0xD9, 0xE0, 0xED, 0x00, 0xDC, 0xD5, 0xE6, 0xE7, 0xDC, 0xAB, 0xFF};
u8 heavyrain_activation_text[] = {0xBB, 0x00, 0xDC, 0xD9, 0xD5, 0xEA, 0xED, 0x00, 0xE6, 0xD5, 0xDD, 0xE2, 0x00, 0xD6, 0xD9, 0xDB, 0xD5, 0xE2, 0x00, 0xE8, 0xE3, 0x00, 0xDA, 0xD5, 0xE0, 0xE0, 0xAB, 0xFF};
u8 mysticalaircurrent_activation_text[] = {0xBB, 0x00, 0xE1, 0xED, 0xE7, 0xE8, 0xD9, 0xE6, 0xDD, 0xE3, 0xE9, 0xE7, 0x00, 0xD5, 0xDD, 0xE6, 0x00, 0xD7, 0xE9, 0xE6, 0xE6, 0xD9, 0xE2, 0xE8, 0xFE, 0xDD, 0xE7, 0x00, 0xE4, 0xE6, 0xE3, 0xE8, 0xD9, 0xD7, 0xE8, 0xDD, 0xE2, 0xDB, 0x00, 0xC0, 0xE0, 0xED, 0xDD, 0xE2, 0xDB, 0xAE, 0xE8, 0xED, 0xE4, 0xD9, 0x00, 0xCA, 0xE3, 0xDF, 0x1B, 0xE1, 0xE3, 0xE2, 0xAB, 0xFF};
u8 forewarn_text[] = {0xFD, 0x13, 0xB4, 0xE7, 0, 0xFD, 0x1A, 0xFE, 0xD5, 0xE0, 0xD9, 0xE6, 0xE8, 0xD9, 0xD8, 0, 0xDD, 0xE8, 0, 0xE8, 0xE3, 0x0, 0xFD, 0, 0xAB, 0xFF};
u8 slowstart_text[] = {0xFD, 0x13, 0x0, 0xD7, 0xD5, 0xE2, 0xB4, 0xE8, 0x00, 0xDB, 0xD9, 0xE8, 0x00, 0xDD, 0xE8, 0x00, 0xDB, 0xE3, 0xDD, 0xE2, 0xDB, 0xAB, 0xFF};
u8 anticipation_text[] = {0xFD, 0x13, 0, 0xE7, 0xDC, 0xE9, 0xD8, 0xD8, 0xD9, 0xE6, 0xD9, 0xD8, 0x00, 0xEB, 0xDD, 0xE8, 0xDC, 0x00, 0xD5, 0xE2, 0xE8, 0xDD, 0xD7, 0xDD, 0xE4, 0xD5, 0xE8, 0xDD, 0xE3, 0xE2, 0xAB ,0xFF};
u8 dryskin_damage_text[] = {0xFD, 15, 0xB4, 0xE7, 0, 0xFD, 24, 0x0, 0xE1, 0xD5, 0xDF, 0xD9, 0xE7, 0x00, 0xDD, 0xE7, 0xFE, 0xEA, 0xE9, 0xE0, 0xE2, 0xD9, 0xE6, 0xD5, 0xD6, 0xE0, 0xD9, 0x00, 0xE8, 0xE3, 0x00, 0xE7, 0xE9, 0xE2, 0xAB, 0xFF};
u8 solarpower_text[] = {0xFD, 15, 0xB4, 0xE7, 0, 0xFD, 24, 0x0, 0xE1, 0xD5, 0xDF, 0xD9, 0xE7, 0x0, 0xDD, 0xE8, 0x0, 0xD8, 0xE6, 0xD5, 0xEB, 0x0, 0xE4, 0xE3, 0xEB, 0xD9, 0xE6, 0xFE, 0xDA, 0xE6, 0xE3, 0xE1, 0x0, 0xE8, 0xDC, 0xD9, 0x0, 0xE7, 0xE9, 0xE2, 0x0, 0xDD, 0xE2, 0x00, 0xD9, 0xEC, 0xD7, 0xDC, 0xD5, 0xE2, 0xDB, 0xD9, 0x00, 0xDA, 0xE3, 0xE6, 0x00, 0xE0, 0xDD, 0xDA, 0xD9, 0xAB, 0xFF};
u8 harvest_text[] = {0xFD, 15, 0, 0xDC, 0xD5, 0xE6, 0xEA, 0xD9, 0xE7, 0xE8, 0xD9, 0xD8, 0x00, 0xE3, 0xE2, 0xD9, 0, 0xFD, 22, 0xAB, 0xFF};
u8 healer_text[] = {0xFD, 15, 0, 0xB4, 0xE7, 0, 0xFD, 24, 0, 0xD7, 0xE9, 0xE6, 0xD9, 0xD8, 0x00, 0xDD, 0xE8, 0xE7, 0x00, 0xE4, 0xD5, 0xE6, 0xE8, 0xE2, 0xD9, 0xE6, 0xB4, 0xE7, 0xFE, 0xFD, 0x0, 0xAB, 0xFF};
u8 pickup_text[] = {0xFD, 15, 0, 0xDA, 0xE3, 0xE9, 0xE2, 0xD8, 0x00, 0xE3, 0xE2, 0xD9, 0x00, 0xFD, 22, 0xAB, 0xFF};
u8 moldbreaker_text[] = {0xFD, 0x13, 0, 0xD6, 0xE6, 0xD9, 0xD5, 0xDF, 0xE7, 0x00, 0xE8, 0xDC, 0xD9, 0x00, 0xE1, 0xE3, 0xE0, 0xD8, 0xAB, 0xFF};
u8 turboblaze_text[] = {0xFD, 0x13, 0, 0xDD, 0xE7, 0x00, 0xE6, 0xD5, 0xD8, 0xDD, 0xD5, 0xE8, 0xDD, 0xE2, 0xDB, 0x00, 0xD5, 0x00, 0xD6, 0xE0, 0xD5, 0xEE, 0xDD, 0xE2, 0xDB, 0x00, 0xD5, 0xE9, 0xE6, 0xD5, 0xAB, 0xFF};
u8 terravolt_text[] = {0xFD, 0x13, 0, 0xDD, 0xE7, 0x00, 0xE6, 0xD5, 0xD8, 0xDD, 0xD5, 0xE8, 0xDD, 0xE2, 0xDB, 0x00, 0xD5, 0x00, 0xD6, 0xE9, 0xE6, 0xE7, 0xE8, 0xDD, 0xE2, 0xDB, 0x00, 0xD5, 0xE9, 0xE6, 0xD5, 0xAB, 0xFF};
u8 downloadatk_text[] = {0xFD, 0x13, 0xB4, 0xE7, 0x0, 0xFD, 0x1A, 0, 0xE6, 0xD5, 0xDD, 0xE7, 0xD9, 0xD8, 0x00, 0xDD, 0xE8, 0xE7, 0xFE, 0xBB, 0xE8, 0xE8, 0xD5, 0xD7, 0xDF, 0xAB, 0xFF};
u8 downloadspatk_text[] = {0xFD, 0x13, 0xB4, 0xE7, 0x0, 0xFD, 0x1A, 0, 0xE6, 0xD5, 0xDD, 0xE7, 0xD9, 0xD8, 0x00, 0xDD, 0xE8, 0xE7, 0xFE, 0xCD, 0xE4, 0xAD, 0, 0xBB, 0xE8, 0xE8, 0xD5, 0xD7, 0xDF, 0xAB, 0xFF};
u8 sapsipperboost_text[] = {0xFD, 0x10, 0xB4, 0xE7, 0, 0xFD, 0x19, 0, 0xE6, 0xD5, 0xDD, 0xE7, 0xD9, 0xD8, 0x00, 0xDD, 0xE8, 0xE7, 0xFE, 0xBB, 0xE8, 0xE8, 0xD5, 0xD7, 0xDF, 0xAB ,0xFF};
u8 sapsipperimmunity_text[] = {0xFD, 0x10, 0xB4, 0xE7, 0, 0xFD, 0x19, 0, 0xE1, 0xD5, 0xDF, 0xD9, 0xE7, 0x00, 0xDD, 0xE8, 0xFE, 0xDD, 0xE1, 0xE1, 0xE9, 0xE2, 0xD9, 0x00, 0xE8, 0xE3, 0x00, 0xDB, 0xE6, 0xD5, 0xE7, 0xE7, 0xAE, 0xE8, 0xED, 0xE4, 0xD9, 0x00, 0xE1, 0xE3, 0xEA, 0xD9, 0xE7, 0xAB, 0xFF};
u8 motorboost_text[] = {0xFD, 0x10, 0xB4, 0xE7, 0, 0xFD, 0x19, 0, 0xE6, 0xD5, 0xDD, 0xE7, 0xD9, 0xD8, 0x00, 0xDD, 0xE8, 0xE7, 0xFE, 0xCD, 0xE4, 0xD9, 0xD9, 0xD8, 0xAB ,0xFF};
u8 motorimmunity_text[] = {0xFD, 0x10, 0xB4, 0xE7, 0, 0xFD, 0x19, 0, 0xE1, 0xD5, 0xDF, 0xD9, 0xE7, 0x00, 0xDD, 0xE8, 0xFE, 0xDD, 0xE1, 0xE1, 0xE9, 0xE2, 0xD9, 0x00, 0xE8, 0xE3, 0x00, 0xD9, 0xE0, 0xD9, 0xD7, 0xE8, 0xE6, 0xDD, 0xD7 ,0xAE, 0xE8, 0xED, 0xE4, 0xD9, 0x00, 0xE1, 0xE3, 0xEA, 0xD9, 0xE7, 0xAB, 0xFF};
u8 aftermath_text[] = {0xFD, 15, 0, 0xDD, 0xE7, 0x0, 0xDC, 0xE9, 0xE6, 0xE8, 0x00, 0xD6, 0xED, 0xFE, 0xFD, 16, 0xB4, 0xE7, 0, 0xFD, 25, 0xAB, 0xFF};
u8 pickpocket_text[] = {0xFD, 16, 0, 0xE7, 0xE8, 0xE3, 0xE0, 0xD9, 0, 0xFD, 15, 0xB4, 0xE7, 0xFE, 0xFD, 22, 0xAB, 0xFF};
u8 mummy_text[] = {0xFD, 15, 0xB4, 0xE7, 0, 0xD5, 0xD6, 0xDD, 0xE0, 0xDD, 0xE8, 0xED, 0xFE, 0xD6, 0xD9, 0xD7, 0xD5, 0xE1, 0xD9, 0, 0xFD, 24, 0xAB, 0xFF};
u8 target_ability[] = {0xFD, 16, 0xB4, 0xE7, 0, 0xFD, 25, 0xAB, 0xFF};
u8 cursedbody_text[] = {0xFD, 16, 0xB4, 0xE7, 0, 0xFD, 25, 0, 0xD8, 0xDD, 0xE7, 0xD5, 0xD6, 0xE0, 0xD9, 0xD8, 0xFE, 0xFD, 15, 0xB4, 0xE7, 0, 0xFD, 0, 0xAB, 0xFF};
u8 drastically_text[] = {0xD8, 0xE6, 0xD5, 0xE7, 0xE8, 0xDD, 0xD7, 0xD5, 0xE0, 0xE0, 0xED, 0x0, 0xFF};

void* new_strings_table[] = {&sample_text, &snowwarning_text, &extreme_sun_activation_text, &heavyrain_activation_text, &mysticalaircurrent_activation_text, &forewarn_text, &slowstart_text, &anticipation_text, &dryskin_damage_text, &solarpower_text, &harvest_text, &healer_text, &pickup_text, &moldbreaker_text, &turboblaze_text, &terravolt_text, &downloadatk_text,
&downloadspatk_text, &sapsipperboost_text, &sapsipperimmunity_text, &motorboost_text, &motorimmunity_text,
&aftermath_text, &pickpocket_text, &mummy_text, &target_ability, &cursedbody_text, &drastically_text};

void battle_string_loader(u16 string_id)
{
    string_id -= 0x17C;
    display_string_in_battle(new_strings_table[string_id]);
    return;
}

extern void call_ability_effects();

void apply_burn_animation()
{
    u8 active = active_bank;
    active_bank = bank_attacker;
    new_battlestruct.ptr->various.var1 = 0x10;
    new_battlestruct.ptr->various.var2 = 0;
    prepare_status_animation(0, 0, new_battlestruct.ptr->various.var1);
    mark_buffer_bank_for_execution(bank_attacker);
    active_bank = active;
    return;
}

void change_attacker_item()
{
    active_bank = bank_attacker;
    prepare_setattributes_in_battle(0, 2, 0, 4, &battle_participants[bank_attacker].held_item);
    mark_buffer_bank_for_execution(bank_attacker);
}

void try_to_raise_spd()
{
    if (battle_participants[new_battlestruct.ptr->various.active_bank].spd_buff != 0xC)
    {
        battle_scripting.stat_changer = 0x13;
        battlescript_push();
        battlescripts_curr_instruction = &changetargetstat_bs;
    }
    return;
}

void try_to_lower_def()
{
    if (battle_participants[new_battlestruct.ptr->various.active_bank].def_buff > 0)
    {
        battle_scripting.stat_changer = 0x92;
        battlescript_push();
        battlescripts_curr_instruction = &changetargetstat_bs;
    }
    return;
}

void changestatvar1()
{
    if (new_battlestruct.ptr->various.var1)
    {
        battle_scripting.stat_changer = new_battlestruct.ptr->various.var1;
        battlescript_push();
        battlescripts_curr_instruction = &changetargetstat_bs;
    }
    return;
}

void changestatvar2()
{
    if (new_battlestruct.ptr->various.var2)
    {
        battle_scripting.stat_changer = new_battlestruct.ptr->various.var2;
        battlescript_push();
        battlescripts_curr_instruction = &changetargetstat_bs;
    }
    return;
}

void* callasm_table[] = {&call_ability_effects, &apply_burn_animation, &change_attacker_item, &try_to_lower_def, &try_to_raise_spd,
&changestatvar1, &changestatvar2};

void callasm_cmd()
{
    void (*command) (void);
    u8 command_id = read_byte(battlescripts_curr_instruction + 1);
    battlescripts_curr_instruction += 2;
    command = callasm_table[command_id];
    command();
}