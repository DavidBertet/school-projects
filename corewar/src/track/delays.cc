#include "delays.hh"
#include "data.h"

Delays* Delays::instance_ = 0;

void
create_decode_add (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("add", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADD_FEISAR));

  my_pair = *new pair_t ("add", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADD_GOTEKI45));

  my_pair = *new pair_t ("add", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADD_AURICOM));

  my_pair = *new pair_t ("add", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADD_ASSEGAI));

  my_pair = *new pair_t ("add", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADD_PIRANHA));

  my_pair = *new pair_t ("add", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADD_QIREX));

  my_pair = *new pair_t ("add", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADD_ICARAS));

  my_pair = *new pair_t ("add", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADD_ROCKET));

  my_pair = *new pair_t ("add", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADD_MISSILE));

  my_pair = *new pair_t ("add", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADD_MINE));

  my_pair = *new pair_t ("add", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADD_PLASMA));

  my_pair = *new pair_t ("add", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADD_MINIPLASMA));
}

void
create_decode_sub (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("sub", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SUB_FEISAR));

  my_pair = *new pair_t ("sub", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SUB_GOTEKI45));

  my_pair = *new pair_t ("sub", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SUB_AURICOM));

  my_pair = *new pair_t ("sub", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SUB_ASSEGAI));

  my_pair = *new pair_t ("sub", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SUB_PIRANHA));

  my_pair = *new pair_t ("sub", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SUB_QIREX));

  my_pair = *new pair_t ("sub", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SUB_ICARAS));

  my_pair = *new pair_t ("sub", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SUB_ROCKET));

  my_pair = *new pair_t ("sub", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SUB_MISSILE));

  my_pair = *new pair_t ("sub", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SUB_MINE));

  my_pair = *new pair_t ("sub", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SUB_PLASMA));

  my_pair = *new pair_t ("sub", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SUB_MINIPLASMA));
}

void
create_decode_cmp (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("cmp", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMP_FEISAR));

  my_pair = *new pair_t ("cmp", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMP_GOTEKI45));

  my_pair = *new pair_t ("cmp", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMP_AURICOM));

  my_pair = *new pair_t ("cmp", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMP_ASSEGAI));

  my_pair = *new pair_t ("cmp", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMP_PIRANHA));

  my_pair = *new pair_t ("cmp", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMP_QIREX));

  my_pair = *new pair_t ("cmp", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMP_ICARAS));

  my_pair = *new pair_t ("cmp", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMP_ROCKET));

  my_pair = *new pair_t ("cmp", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMP_MISSILE));

  my_pair = *new pair_t ("cmp", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMP_MINE));

  my_pair = *new pair_t ("cmp", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMP_PLASMA));

  my_pair = *new pair_t ("cmp", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMP_MINIPLASMA));
}

void
create_decode_addi (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("addi", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADDI_FEISAR));

  my_pair = *new pair_t ("addi", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADDI_GOTEKI45));

  my_pair = *new pair_t ("addi", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADDI_AURICOM));

  my_pair = *new pair_t ("addi", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADDI_ASSEGAI));

  my_pair = *new pair_t ("addi", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADDI_PIRANHA));

  my_pair = *new pair_t ("addi", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADDI_QIREX));

  my_pair = *new pair_t ("addi", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADDI_ICARAS));

  my_pair = *new pair_t ("addi", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADDI_ROCKET));

  my_pair = *new pair_t ("addi", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADDI_MISSILE));

  my_pair = *new pair_t ("addi", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADDI_MINE));

  my_pair = *new pair_t ("addi", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ADDI_PLASMA));

  my_pair = *new pair_t ("addi", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_DECODE_ADDI_MINIPLASMA));
}

void
create_decode_cmpi (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("cmpi", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMPI_FEISAR));

  my_pair = *new pair_t ("cmpi", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMPI_GOTEKI45));

  my_pair = *new pair_t ("cmpi", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMPI_AURICOM));

  my_pair = *new pair_t ("cmpi", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMPI_ASSEGAI));

  my_pair = *new pair_t ("cmpi", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMPI_PIRANHA));

  my_pair = *new pair_t ("cmpi", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMPI_QIREX));

  my_pair = *new pair_t ("cmpi", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMPI_ICARAS));

  my_pair = *new pair_t ("cmpi", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMPI_ROCKET));

  my_pair = *new pair_t ("cmpi", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMPI_MISSILE));

  my_pair = *new pair_t ("cmpi", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMPI_MINE));

  my_pair = *new pair_t ("cmpi", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CMPI_PLASMA));

  my_pair = *new pair_t ("cmpi", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_DECODE_CMPI_MINIPLASMA));
}

void
create_decode_asr (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("asr", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ASR_FEISAR));

  my_pair = *new pair_t ("asr", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ASR_GOTEKI45));

  my_pair = *new pair_t ("asr", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ASR_AURICOM));

  my_pair = *new pair_t ("asr", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ASR_ASSEGAI));

  my_pair = *new pair_t ("asr", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ASR_PIRANHA));

  my_pair = *new pair_t ("asr", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ASR_QIREX));

  my_pair = *new pair_t ("asr", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ASR_ICARAS));

  my_pair = *new pair_t ("asr", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ASR_ROCKET));

  my_pair = *new pair_t ("asr", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ASR_MISSILE));

  my_pair = *new pair_t ("asr", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ASR_MINE));

  my_pair = *new pair_t ("asr", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ASR_PLASMA));

  my_pair = *new pair_t ("asr", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ASR_MINIPLASMA));
}

void
create_decode_neg (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("neg", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NEG_FEISAR));

  my_pair = *new pair_t ("neg", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NEG_GOTEKI45));

  my_pair = *new pair_t ("neg", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NEG_AURICOM));

  my_pair = *new pair_t ("neg", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NEG_ASSEGAI));

  my_pair = *new pair_t ("neg", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NEG_PIRANHA));

  my_pair = *new pair_t ("neg", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NEG_QIREX));

  my_pair = *new pair_t ("neg", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NEG_ICARAS));

  my_pair = *new pair_t ("neg", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NEG_ROCKET));

  my_pair = *new pair_t ("neg", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NEG_MISSILE));

  my_pair = *new pair_t ("neg", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NEG_MINE));

  my_pair = *new pair_t ("neg", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NEG_PLASMA));

  my_pair = *new pair_t ("neg", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NEG_MINIPLASMA));
}

void
create_decode_and (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("and", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_AND_FEISAR));

  my_pair = *new pair_t ("and", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_AND_GOTEKI45));

  my_pair = *new pair_t ("and", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_AND_AURICOM));

  my_pair = *new pair_t ("and", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_AND_ASSEGAI));

  my_pair = *new pair_t ("and", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_AND_PIRANHA));

  my_pair = *new pair_t ("and", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_AND_QIREX));

  my_pair = *new pair_t ("and", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_AND_ICARAS));

  my_pair = *new pair_t ("and", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_AND_ROCKET));

  my_pair = *new pair_t ("and", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_AND_MISSILE));

  my_pair = *new pair_t ("and", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_AND_MINE));

  my_pair = *new pair_t ("and", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_AND_PLASMA));

  my_pair = *new pair_t ("and", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_AND_MINIPLASMA));
}

void
create_decode_or (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("or", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_OR_FEISAR));

  my_pair = *new pair_t ("or", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_OR_GOTEKI45));

  my_pair = *new pair_t ("or", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_OR_AURICOM));

  my_pair = *new pair_t ("or", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_OR_ASSEGAI));

  my_pair = *new pair_t ("or", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_OR_PIRANHA));

  my_pair = *new pair_t ("or", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_OR_QIREX));

  my_pair = *new pair_t ("or", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_OR_ICARAS));

  my_pair = *new pair_t ("or", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_OR_ROCKET));

  my_pair = *new pair_t ("or", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_OR_MISSILE));

  my_pair = *new pair_t ("or", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_OR_MINE));

  my_pair = *new pair_t ("or", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_OR_PLASMA));

  my_pair = *new pair_t ("or", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_OR_MINIPLASMA));
}

void
create_decode_xor (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("xor", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_XOR_FEISAR));

  my_pair = *new pair_t ("xor", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_XOR_GOTEKI45));

  my_pair = *new pair_t ("xor", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_XOR_AURICOM));

  my_pair = *new pair_t ("xor", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_XOR_ASSEGAI));

  my_pair = *new pair_t ("xor", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_XOR_PIRANHA));

  my_pair = *new pair_t ("xor", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_XOR_QIREX));

  my_pair = *new pair_t ("xor", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_XOR_ICARAS));

  my_pair = *new pair_t ("xor", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_XOR_ROCKET));

  my_pair = *new pair_t ("xor", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_XOR_MISSILE));

  my_pair = *new pair_t ("xor", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_XOR_MINE));

  my_pair = *new pair_t ("xor", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_XOR_PLASMA));

  my_pair = *new pair_t ("xor", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_XOR_MINIPLASMA));
}

void
create_decode_not (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("not", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOT_FEISAR));

  my_pair = *new pair_t ("not", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOT_GOTEKI45));

  my_pair = *new pair_t ("not", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOT_AURICOM));

  my_pair = *new pair_t ("not", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOT_ASSEGAI));

  my_pair = *new pair_t ("not", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOT_PIRANHA));

  my_pair = *new pair_t ("not", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOT_QIREX));

  my_pair = *new pair_t ("not", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOT_ICARAS));

  my_pair = *new pair_t ("not", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOT_ROCKET));

  my_pair = *new pair_t ("not", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOT_MISSILE));

  my_pair = *new pair_t ("not", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOT_MINE));

  my_pair = *new pair_t ("not", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOT_PLASMA));

  my_pair = *new pair_t ("not", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOT_MINIPLASMA));
}

void
create_decode_rol (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("rol", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ROL_FEISAR));

  my_pair = *new pair_t ("rol", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ROL_GOTEKI45));

  my_pair = *new pair_t ("rol", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ROL_AURICOM));

  my_pair = *new pair_t ("rol", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ROL_ASSEGAI));

  my_pair = *new pair_t ("rol", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ROL_PIRANHA));

  my_pair = *new pair_t ("rol", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ROL_QIREX));

  my_pair = *new pair_t ("rol", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ROL_ICARAS));

  my_pair = *new pair_t ("rol", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ROL_ROCKET));

  my_pair = *new pair_t ("rol", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ROL_MISSILE));

  my_pair = *new pair_t ("rol", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ROL_MINE));

  my_pair = *new pair_t ("rol", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ROL_PLASMA));

  my_pair = *new pair_t ("rol", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_ROL_MINIPLASMA));
}

void
create_decode_swp (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("swp", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SWP_FEISAR));

  my_pair = *new pair_t ("swp", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SWP_GOTEKI45));

  my_pair = *new pair_t ("swp", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SWP_AURICOM));

  my_pair = *new pair_t ("swp", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SWP_ASSEGAI));

  my_pair = *new pair_t ("swp", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SWP_PIRANHA));

  my_pair = *new pair_t ("swp", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SWP_QIREX));

  my_pair = *new pair_t ("swp", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SWP_ICARAS));

  my_pair = *new pair_t ("swp", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SWP_ROCKET));

  my_pair = *new pair_t ("swp", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SWP_MISSILE));

  my_pair = *new pair_t ("swp", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SWP_MINE));

  my_pair = *new pair_t ("swp", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SWP_PLASMA));

  my_pair = *new pair_t ("swp", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_SWP_MINIPLASMA));
}

void
create_decode_b (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("b", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_B_FEISAR));

  my_pair = *new pair_t ("b", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_B_GOTEKI45));

  my_pair = *new pair_t ("b", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_B_AURICOM));

  my_pair = *new pair_t ("b", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_B_ASSEGAI));

  my_pair = *new pair_t ("b", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_B_PIRANHA));

  my_pair = *new pair_t ("b", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_B_QIREX));

  my_pair = *new pair_t ("b", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_B_ICARAS));

  my_pair = *new pair_t ("b", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_B_ROCKET));

  my_pair = *new pair_t ("b", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_B_MISSILE));

  my_pair = *new pair_t ("b", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_B_MINE));

  my_pair = *new pair_t ("b", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_B_PLASMA));

  my_pair = *new pair_t ("b", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_B_MINIPLASMA));
}

void
create_decode_bz (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("bz", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BZ_FEISAR));

  my_pair = *new pair_t ("bz", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BZ_GOTEKI45));

  my_pair = *new pair_t ("bz", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BZ_AURICOM));

  my_pair = *new pair_t ("bz", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BZ_ASSEGAI));

  my_pair = *new pair_t ("bz", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BZ_PIRANHA));

  my_pair = *new pair_t ("bz", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BZ_QIREX));

  my_pair = *new pair_t ("bz", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BZ_ICARAS));

  my_pair = *new pair_t ("bz", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BZ_ROCKET));

  my_pair = *new pair_t ("bz", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BZ_MISSILE));

  my_pair = *new pair_t ("bz", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BZ_MINE));

  my_pair = *new pair_t ("bz", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BZ_PLASMA));

  my_pair = *new pair_t ("bz", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BZ_MINIPLASMA));
}

void
create_decode_bnz (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("bnz", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BNZ_FEISAR));

  my_pair = *new pair_t ("bnz", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BNZ_GOTEKI45));

  my_pair = *new pair_t ("bnz", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BNZ_AURICOM));

  my_pair = *new pair_t ("bnz", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BNZ_ASSEGAI));

  my_pair = *new pair_t ("bnz", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BNZ_PIRANHA));

  my_pair = *new pair_t ("bnz", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BNZ_QIREX));

  my_pair = *new pair_t ("bnz", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BNZ_ICARAS));

  my_pair = *new pair_t ("bnz", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BNZ_ROCKET));

  my_pair = *new pair_t ("bnz", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BNZ_MISSILE));

  my_pair = *new pair_t ("bnz", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BNZ_MINE));

  my_pair = *new pair_t ("bnz", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BNZ_PLASMA));

  my_pair = *new pair_t ("bnz", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BNZ_MINIPLASMA));
}

void
create_decode_bs (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("bs", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BS_FEISAR));

  my_pair = *new pair_t ("bs", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BS_GOTEKI45));

  my_pair = *new pair_t ("bs", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BS_AURICOM));

  my_pair = *new pair_t ("bs", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BS_ASSEGAI));

  my_pair = *new pair_t ("bs", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BS_PIRANHA));

  my_pair = *new pair_t ("bs", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BS_QIREX));

  my_pair = *new pair_t ("bs", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BS_ICARAS));

  my_pair = *new pair_t ("bs", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BS_ROCKET));

  my_pair = *new pair_t ("bs", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BS_MISSILE));

  my_pair = *new pair_t ("bs", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BS_MINE));

  my_pair = *new pair_t ("bs", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BS_PLASMA));

  my_pair = *new pair_t ("bs", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_BS_MINIPLASMA));
}

void
create_decode_nop (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("nop", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOP_FEISAR));

  my_pair = *new pair_t ("nop", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOP_GOTEKI45));

  my_pair = *new pair_t ("nop", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOP_AURICOM));

  my_pair = *new pair_t ("nop", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOP_ASSEGAI));

  my_pair = *new pair_t ("nop", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOP_PIRANHA));

  my_pair = *new pair_t ("nop", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOP_QIREX));

  my_pair = *new pair_t ("nop", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOP_ICARAS));

  my_pair = *new pair_t ("nop", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOP_ROCKET));

  my_pair = *new pair_t ("nop", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOP_MISSILE));

  my_pair = *new pair_t ("nop", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOP_MINE));

  my_pair = *new pair_t ("nop", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOP_PLASMA));

  my_pair = *new pair_t ("nop", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_NOP_MINIPLASMA));
}

void
create_decode_mov (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("mov", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MOV_FEISAR));

  my_pair = *new pair_t ("mov", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MOV_GOTEKI45));

  my_pair = *new pair_t ("mov", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MOV_AURICOM));

  my_pair = *new pair_t ("mov", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MOV_ASSEGAI));

  my_pair = *new pair_t ("mov", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MOV_PIRANHA));

  my_pair = *new pair_t ("mov", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MOV_QIREX));

  my_pair = *new pair_t ("mov", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MOV_ICARAS));

  my_pair = *new pair_t ("mov", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MOV_ROCKET));

  my_pair = *new pair_t ("mov", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MOV_MISSILE));

  my_pair = *new pair_t ("mov", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MOV_MINE));

  my_pair = *new pair_t ("mov", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MOV_PLASMA));

  my_pair = *new pair_t ("mov", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MOV_MINIPLASMA));
}

void
create_decode_lc (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("lc", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LC_FEISAR));

  my_pair = *new pair_t ("lc", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LC_GOTEKI45));

  my_pair = *new pair_t ("lc", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LC_AURICOM));

  my_pair = *new pair_t ("lc", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LC_ASSEGAI));

  my_pair = *new pair_t ("lc", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LC_PIRANHA));

  my_pair = *new pair_t ("lc", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LC_QIREX));

  my_pair = *new pair_t ("lc", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LC_ICARAS));

  my_pair = *new pair_t ("lc", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LC_ROCKET));

  my_pair = *new pair_t ("lc", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LC_MISSILE));

  my_pair = *new pair_t ("lc", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LC_MINE));

  my_pair = *new pair_t ("lc", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LC_PLASMA));

  my_pair = *new pair_t ("lc", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LC_MINIPLASMA));
}

void
create_decode_ll (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("ll", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LL_FEISAR));

  my_pair = *new pair_t ("ll", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LL_GOTEKI45));

  my_pair = *new pair_t ("ll", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LL_AURICOM));

  my_pair = *new pair_t ("ll", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LL_ASSEGAI));

  my_pair = *new pair_t ("ll", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LL_PIRANHA));

  my_pair = *new pair_t ("ll", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LL_QIREX));

  my_pair = *new pair_t ("ll", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LL_ICARAS));

  my_pair = *new pair_t ("ll", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LL_ROCKET));

  my_pair = *new pair_t ("ll", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LL_MISSILE));

  my_pair = *new pair_t ("ll", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LL_MINE));

  my_pair = *new pair_t ("ll", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LL_PLASMA));

  my_pair = *new pair_t ("ll", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LL_MINIPLASMA));
}

void
create_decode_ldr (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("ldr", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDR_FEISAR));

  my_pair = *new pair_t ("ldr", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDR_GOTEKI45));

  my_pair = *new pair_t ("ldr", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDR_AURICOM));

  my_pair = *new pair_t ("ldr", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDR_ASSEGAI));

  my_pair = *new pair_t ("ldr", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDR_PIRANHA));

  my_pair = *new pair_t ("ldr", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDR_QIREX));

  my_pair = *new pair_t ("ldr", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDR_ICARAS));

  my_pair = *new pair_t ("ldr", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDR_ROCKET));

  my_pair = *new pair_t ("ldr", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDR_MISSILE));

  my_pair = *new pair_t ("ldr", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDR_MINE));

  my_pair = *new pair_t ("ldr", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDR_PLASMA));

  my_pair = *new pair_t ("ldr", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDR_MINIPLASMA));
}

void
create_decode_str (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("str", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STR_FEISAR));

  my_pair = *new pair_t ("str", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STR_GOTEKI45));

  my_pair = *new pair_t ("str", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STR_AURICOM));

  my_pair = *new pair_t ("str", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STR_ASSEGAI));

  my_pair = *new pair_t ("str", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STR_PIRANHA));

  my_pair = *new pair_t ("str", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STR_QIREX));

  my_pair = *new pair_t ("str", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STR_ICARAS));

  my_pair = *new pair_t ("str", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STR_ROCKET));

  my_pair = *new pair_t ("str", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STR_MISSILE));

  my_pair = *new pair_t ("str", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STR_MINE));

  my_pair = *new pair_t ("str", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STR_PLASMA));

  my_pair = *new pair_t ("str", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STR_MINIPLASMA));
}

void
create_decode_ldb (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("ldb", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDB_FEISAR));

  my_pair = *new pair_t ("ldb", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDB_GOTEKI45));

  my_pair = *new pair_t ("ldb", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDB_AURICOM));

  my_pair = *new pair_t ("ldb", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDB_ASSEGAI));

  my_pair = *new pair_t ("ldb", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDB_PIRANHA));

  my_pair = *new pair_t ("ldb", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDB_QIREX));

  my_pair = *new pair_t ("ldb", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDB_ICARAS));

  my_pair = *new pair_t ("ldb", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDB_ROCKET));

  my_pair = *new pair_t ("ldb", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDB_MISSILE));

  my_pair = *new pair_t ("ldb", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDB_MINE));

  my_pair = *new pair_t ("ldb", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDB_PLASMA));

  my_pair = *new pair_t ("ldb", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_LDB_MINIPLASMA));
}

void
create_decode_stb (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("stb", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STB_FEISAR));

  my_pair = *new pair_t ("stb", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STB_GOTEKI45));

  my_pair = *new pair_t ("stb", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STB_AURICOM));

  my_pair = *new pair_t ("stb", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STB_ASSEGAI));

  my_pair = *new pair_t ("stb", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STB_PIRANHA));

  my_pair = *new pair_t ("stb", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STB_QIREX));

  my_pair = *new pair_t ("stb", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STB_ICARAS));

  my_pair = *new pair_t ("stb", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STB_ROCKET));

  my_pair = *new pair_t ("stb", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STB_MISSILE));

  my_pair = *new pair_t ("stb", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STB_MINE));

  my_pair = *new pair_t ("stb", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STB_PLASMA));

  my_pair = *new pair_t ("stb", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STB_MINIPLASMA));
}

void
create_decode_write (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("write", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_WRITE_FEISAR));

  my_pair = *new pair_t ("write", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_WRITE_GOTEKI45));

  my_pair = *new pair_t ("write", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_WRITE_AURICOM));

  my_pair = *new pair_t ("write", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_WRITE_ASSEGAI));

  my_pair = *new pair_t ("write", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_WRITE_PIRANHA));

  my_pair = *new pair_t ("write", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_WRITE_QIREX));

  my_pair = *new pair_t ("write", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_WRITE_ICARAS));

  my_pair = *new pair_t ("write", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_WRITE_ROCKET));

  my_pair = *new pair_t ("write", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_WRITE_MISSILE));

  my_pair = *new pair_t ("write", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_WRITE_MINE));

  my_pair = *new pair_t ("write", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_WRITE_PLASMA));

  my_pair = *new pair_t ("write", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_DECODE_WRITE_MINIPLASMA));
}

void
create_decode_stat (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("stat", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STAT_FEISAR));

  my_pair = *new pair_t ("stat", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STAT_GOTEKI45));

  my_pair = *new pair_t ("stat", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STAT_AURICOM));

  my_pair = *new pair_t ("stat", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STAT_ASSEGAI));

  my_pair = *new pair_t ("stat", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STAT_PIRANHA));

  my_pair = *new pair_t ("stat", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STAT_QIREX));

  my_pair = *new pair_t ("stat", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STAT_ICARAS));

  my_pair = *new pair_t ("stat", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STAT_ROCKET));

  my_pair = *new pair_t ("stat", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STAT_MISSILE));

  my_pair = *new pair_t ("stat", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STAT_MINE));

  my_pair = *new pair_t ("stat", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_STAT_PLASMA));

  my_pair = *new pair_t ("stat", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_DECODE_STAT_MINIPLASMA));
}

void
create_decode_check (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("check", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CHECK_FEISAR));

  my_pair = *new pair_t ("check", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CHECK_GOTEKI45));

  my_pair = *new pair_t ("check", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CHECK_AURICOM));

  my_pair = *new pair_t ("check", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CHECK_ASSEGAI));

  my_pair = *new pair_t ("check", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CHECK_PIRANHA));

  my_pair = *new pair_t ("check", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CHECK_QIREX));

  my_pair = *new pair_t ("check", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CHECK_ICARAS));

  my_pair = *new pair_t ("check", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CHECK_ROCKET));

  my_pair = *new pair_t ("check", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CHECK_MISSILE));

  my_pair = *new pair_t ("check", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CHECK_MINE));

  my_pair = *new pair_t ("check", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CHECK_PLASMA));

  my_pair = *new pair_t ("check", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_DECODE_CHECK_MINIPLASMA));
}

void
create_decode_mode (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("mode", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MODE_FEISAR));

  my_pair = *new pair_t ("mode", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MODE_GOTEKI45));

  my_pair = *new pair_t ("mode", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MODE_AURICOM));

  my_pair = *new pair_t ("mode", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MODE_ASSEGAI));

  my_pair = *new pair_t ("mode", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MODE_PIRANHA));

  my_pair = *new pair_t ("mode", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MODE_QIREX));

  my_pair = *new pair_t ("mode", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MODE_ICARAS));

  my_pair = *new pair_t ("mode", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MODE_ROCKET));

  my_pair = *new pair_t ("mode", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MODE_MISSILE));

  my_pair = *new pair_t ("mode", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MODE_MINE));

  my_pair = *new pair_t ("mode", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_MODE_PLASMA));

  my_pair = *new pair_t ("mode", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_DECODE_MODE_MINIPLASMA));
}

void
create_decode_fork (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("fork", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_FORK_FEISAR));

  my_pair = *new pair_t ("fork", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_FORK_GOTEKI45));

  my_pair = *new pair_t ("fork", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_FORK_AURICOM));

  my_pair = *new pair_t ("fork", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_FORK_ASSEGAI));

  my_pair = *new pair_t ("fork", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_FORK_PIRANHA));

  my_pair = *new pair_t ("fork", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_FORK_QIREX));

  my_pair = *new pair_t ("fork", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_FORK_ICARAS));

  my_pair = *new pair_t ("fork", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_FORK_ROCKET));

  my_pair = *new pair_t ("fork", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_FORK_MISSILE));

  my_pair = *new pair_t ("fork", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_FORK_MINE));

  my_pair = *new pair_t ("fork", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_FORK_PLASMA));

  my_pair = *new pair_t ("fork", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_DECODE_FORK_MINIPLASMA));
}

void
create_decode_crash (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("crash", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CRASH_FEISAR));

  my_pair = *new pair_t ("crash", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CRASH_GOTEKI45));

  my_pair = *new pair_t ("crash", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CRASH_AURICOM));

  my_pair = *new pair_t ("crash", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CRASH_ASSEGAI));

  my_pair = *new pair_t ("crash", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CRASH_PIRANHA));

  my_pair = *new pair_t ("crash", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CRASH_QIREX));

  my_pair = *new pair_t ("crash", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CRASH_ICARAS));

  my_pair = *new pair_t ("crash", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CRASH_ROCKET));

  my_pair = *new pair_t ("crash", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CRASH_MISSILE));

  my_pair = *new pair_t ("crash", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CRASH_MINE));

  my_pair = *new pair_t ("crash", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_DECODE_CRASH_PLASMA));

  my_pair = *new pair_t ("crash", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_DECODE_CRASH_MINIPLASMA));
}

void
create_execute_add (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("add", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADD_FEISAR));

  my_pair = *new pair_t ("add", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADD_GOTEKI45));

  my_pair = *new pair_t ("add", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADD_AURICOM));

  my_pair = *new pair_t ("add", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADD_ASSEGAI));

  my_pair = *new pair_t ("add", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADD_PIRANHA));

  my_pair = *new pair_t ("add", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADD_QIREX));

  my_pair = *new pair_t ("add", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADD_ICARAS));

  my_pair = *new pair_t ("add", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADD_ROCKET));

  my_pair = *new pair_t ("add", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADD_MISSILE));

  my_pair = *new pair_t ("add", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADD_MINE));

  my_pair = *new pair_t ("add", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADD_PLASMA));

  my_pair = *new pair_t ("add", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_ADD_MINIPLASMA));
}

void
create_execute_sub (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("sub", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SUB_FEISAR));

  my_pair = *new pair_t ("sub", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SUB_GOTEKI45));

  my_pair = *new pair_t ("sub", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SUB_AURICOM));

  my_pair = *new pair_t ("sub", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SUB_ASSEGAI));

  my_pair = *new pair_t ("sub", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SUB_PIRANHA));

  my_pair = *new pair_t ("sub", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SUB_QIREX));

  my_pair = *new pair_t ("sub", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SUB_ICARAS));

  my_pair = *new pair_t ("sub", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SUB_ROCKET));

  my_pair = *new pair_t ("sub", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SUB_MISSILE));

  my_pair = *new pair_t ("sub", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SUB_MINE));

  my_pair = *new pair_t ("sub", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SUB_PLASMA));

  my_pair = *new pair_t ("sub", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_SUB_MINIPLASMA));
}

void
create_execute_cmp (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("cmp", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMP_FEISAR));

  my_pair = *new pair_t ("cmp", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMP_GOTEKI45));

  my_pair = *new pair_t ("cmp", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMP_AURICOM));

  my_pair = *new pair_t ("cmp", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMP_ASSEGAI));

  my_pair = *new pair_t ("cmp", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMP_PIRANHA));

  my_pair = *new pair_t ("cmp", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMP_QIREX));

  my_pair = *new pair_t ("cmp", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMP_ICARAS));

  my_pair = *new pair_t ("cmp", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMP_ROCKET));

  my_pair = *new pair_t ("cmp", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMP_MISSILE));

  my_pair = *new pair_t ("cmp", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMP_MINE));

  my_pair = *new pair_t ("cmp", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMP_PLASMA));

  my_pair = *new pair_t ("cmp", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_CMP_MINIPLASMA));
}

void
create_execute_addi (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("addi", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADDI_FEISAR));

  my_pair = *new pair_t ("addi", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADDI_GOTEKI45));

  my_pair = *new pair_t ("addi", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADDI_AURICOM));

  my_pair = *new pair_t ("addi", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADDI_ASSEGAI));

  my_pair = *new pair_t ("addi", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADDI_PIRANHA));

  my_pair = *new pair_t ("addi", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADDI_QIREX));

  my_pair = *new pair_t ("addi", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADDI_ICARAS));

  my_pair = *new pair_t ("addi", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADDI_ROCKET));

  my_pair = *new pair_t ("addi", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADDI_MISSILE));

  my_pair = *new pair_t ("addi", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADDI_MINE));

  my_pair = *new pair_t ("addi", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ADDI_PLASMA));

  my_pair = *new pair_t ("addi", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_ADDI_MINIPLASMA));
}

void
create_execute_cmpi (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("cmpi", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMPI_FEISAR));

  my_pair = *new pair_t ("cmpi", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMPI_GOTEKI45));

  my_pair = *new pair_t ("cmpi", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMPI_AURICOM));

  my_pair = *new pair_t ("cmpi", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMPI_ASSEGAI));

  my_pair = *new pair_t ("cmpi", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMPI_PIRANHA));

  my_pair = *new pair_t ("cmpi", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMPI_QIREX));

  my_pair = *new pair_t ("cmpi", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMPI_ICARAS));

  my_pair = *new pair_t ("cmpi", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMPI_ROCKET));

  my_pair = *new pair_t ("cmpi", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMPI_MISSILE));

  my_pair = *new pair_t ("cmpi", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMPI_MINE));

  my_pair = *new pair_t ("cmpi", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CMPI_PLASMA));

  my_pair = *new pair_t ("cmpi", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_CMPI_MINIPLASMA));
}

void
create_execute_asr (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("asr", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ASR_FEISAR));

  my_pair = *new pair_t ("asr", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ASR_GOTEKI45));

  my_pair = *new pair_t ("asr", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ASR_AURICOM));

  my_pair = *new pair_t ("asr", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ASR_ASSEGAI));

  my_pair = *new pair_t ("asr", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ASR_PIRANHA));

  my_pair = *new pair_t ("asr", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ASR_QIREX));

  my_pair = *new pair_t ("asr", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ASR_ICARAS));

  my_pair = *new pair_t ("asr", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ASR_ROCKET));

  my_pair = *new pair_t ("asr", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ASR_MISSILE));

  my_pair = *new pair_t ("asr", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ASR_MINE));

  my_pair = *new pair_t ("asr", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ASR_PLASMA));

  my_pair = *new pair_t ("asr", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_ASR_MINIPLASMA));
}

void
create_execute_neg (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("neg", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NEG_FEISAR));

  my_pair = *new pair_t ("neg", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NEG_GOTEKI45));

  my_pair = *new pair_t ("neg", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NEG_AURICOM));

  my_pair = *new pair_t ("neg", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NEG_ASSEGAI));

  my_pair = *new pair_t ("neg", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NEG_PIRANHA));

  my_pair = *new pair_t ("neg", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NEG_QIREX));

  my_pair = *new pair_t ("neg", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NEG_ICARAS));

  my_pair = *new pair_t ("neg", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NEG_ROCKET));

  my_pair = *new pair_t ("neg", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NEG_MISSILE));

  my_pair = *new pair_t ("neg", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NEG_MINE));

  my_pair = *new pair_t ("neg", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NEG_PLASMA));

  my_pair = *new pair_t ("neg", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_NEG_MINIPLASMA));
}

void
create_execute_and (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("and", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_AND_FEISAR));

  my_pair = *new pair_t ("and", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_AND_GOTEKI45));

  my_pair = *new pair_t ("and", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_AND_AURICOM));

  my_pair = *new pair_t ("and", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_AND_ASSEGAI));

  my_pair = *new pair_t ("and", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_AND_PIRANHA));

  my_pair = *new pair_t ("and", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_AND_QIREX));

  my_pair = *new pair_t ("and", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_AND_ICARAS));

  my_pair = *new pair_t ("and", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_AND_ROCKET));

  my_pair = *new pair_t ("and", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_AND_MISSILE));

  my_pair = *new pair_t ("and", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_AND_MINE));

  my_pair = *new pair_t ("and", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_AND_PLASMA));

  my_pair = *new pair_t ("and", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_AND_MINIPLASMA));
}

void
create_execute_or (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("or", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_OR_FEISAR));

  my_pair = *new pair_t ("or", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_OR_GOTEKI45));

  my_pair = *new pair_t ("or", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_OR_AURICOM));

  my_pair = *new pair_t ("or", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_OR_ASSEGAI));

  my_pair = *new pair_t ("or", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_OR_PIRANHA));

  my_pair = *new pair_t ("or", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_OR_QIREX));

  my_pair = *new pair_t ("or", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_OR_ICARAS));

  my_pair = *new pair_t ("or", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_OR_ROCKET));

  my_pair = *new pair_t ("or", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_OR_MISSILE));

  my_pair = *new pair_t ("or", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_OR_MINE));

  my_pair = *new pair_t ("or", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_OR_PLASMA));

  my_pair = *new pair_t ("or", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_OR_MINIPLASMA));
}

void
create_execute_xor (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("xor", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_XOR_FEISAR));

  my_pair = *new pair_t ("xor", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_XOR_GOTEKI45));

  my_pair = *new pair_t ("xor", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_XOR_AURICOM));

  my_pair = *new pair_t ("xor", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_XOR_ASSEGAI));

  my_pair = *new pair_t ("xor", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_XOR_PIRANHA));

  my_pair = *new pair_t ("xor", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_XOR_QIREX));

  my_pair = *new pair_t ("xor", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_XOR_ICARAS));

  my_pair = *new pair_t ("xor", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_XOR_ROCKET));

  my_pair = *new pair_t ("xor", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_XOR_MISSILE));

  my_pair = *new pair_t ("xor", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_XOR_MINE));

  my_pair = *new pair_t ("xor", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_XOR_PLASMA));

  my_pair = *new pair_t ("xor", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_XOR_MINIPLASMA));
}

void
create_execute_not (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("not", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOT_FEISAR));

  my_pair = *new pair_t ("not", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOT_GOTEKI45));

  my_pair = *new pair_t ("not", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOT_AURICOM));

  my_pair = *new pair_t ("not", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOT_ASSEGAI));

  my_pair = *new pair_t ("not", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOT_PIRANHA));

  my_pair = *new pair_t ("not", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOT_QIREX));

  my_pair = *new pair_t ("not", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOT_ICARAS));

  my_pair = *new pair_t ("not", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOT_ROCKET));

  my_pair = *new pair_t ("not", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOT_MISSILE));

  my_pair = *new pair_t ("not", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOT_MINE));

  my_pair = *new pair_t ("not", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOT_PLASMA));

  my_pair = *new pair_t ("not", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_NOT_MINIPLASMA));
}

void
create_execute_rol (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("rol", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ROL_FEISAR));

  my_pair = *new pair_t ("rol", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ROL_GOTEKI45));

  my_pair = *new pair_t ("rol", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ROL_AURICOM));

  my_pair = *new pair_t ("rol", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ROL_ASSEGAI));

  my_pair = *new pair_t ("rol", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ROL_PIRANHA));

  my_pair = *new pair_t ("rol", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ROL_QIREX));

  my_pair = *new pair_t ("rol", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ROL_ICARAS));

  my_pair = *new pair_t ("rol", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ROL_ROCKET));

  my_pair = *new pair_t ("rol", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ROL_MISSILE));

  my_pair = *new pair_t ("rol", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ROL_MINE));

  my_pair = *new pair_t ("rol", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_ROL_PLASMA));

  my_pair = *new pair_t ("rol", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_ROL_MINIPLASMA));
}

void
create_execute_swp (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("swp", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SWP_FEISAR));

  my_pair = *new pair_t ("swp", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SWP_GOTEKI45));

  my_pair = *new pair_t ("swp", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SWP_AURICOM));

  my_pair = *new pair_t ("swp", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SWP_ASSEGAI));

  my_pair = *new pair_t ("swp", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SWP_PIRANHA));

  my_pair = *new pair_t ("swp", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SWP_QIREX));

  my_pair = *new pair_t ("swp", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SWP_ICARAS));

  my_pair = *new pair_t ("swp", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SWP_ROCKET));

  my_pair = *new pair_t ("swp", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SWP_MISSILE));

  my_pair = *new pair_t ("swp", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SWP_MINE));

  my_pair = *new pair_t ("swp", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_SWP_PLASMA));

  my_pair = *new pair_t ("swp", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_SWP_MINIPLASMA));
}

void
create_execute_b (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("b", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_B_FEISAR));

  my_pair = *new pair_t ("b", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_B_GOTEKI45));

  my_pair = *new pair_t ("b", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_B_AURICOM));

  my_pair = *new pair_t ("b", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_B_ASSEGAI));

  my_pair = *new pair_t ("b", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_B_PIRANHA));

  my_pair = *new pair_t ("b", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_B_QIREX));

  my_pair = *new pair_t ("b", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_B_ICARAS));

  my_pair = *new pair_t ("b", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_B_ROCKET));

  my_pair = *new pair_t ("b", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_B_MISSILE));

  my_pair = *new pair_t ("b", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_B_MINE));

  my_pair = *new pair_t ("b", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_B_PLASMA));

  my_pair = *new pair_t ("b", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_B_MINIPLASMA));
}

void
create_execute_bz (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("bz", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BZ_FEISAR));

  my_pair = *new pair_t ("bz", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BZ_GOTEKI45));

  my_pair = *new pair_t ("bz", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BZ_AURICOM));

  my_pair = *new pair_t ("bz", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BZ_ASSEGAI));

  my_pair = *new pair_t ("bz", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BZ_PIRANHA));

  my_pair = *new pair_t ("bz", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BZ_QIREX));

  my_pair = *new pair_t ("bz", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BZ_ICARAS));

  my_pair = *new pair_t ("bz", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BZ_ROCKET));

  my_pair = *new pair_t ("bz", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BZ_MISSILE));

  my_pair = *new pair_t ("bz", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BZ_MINE));

  my_pair = *new pair_t ("bz", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BZ_PLASMA));

  my_pair = *new pair_t ("bz", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BZ_MINIPLASMA));
}

void
create_execute_bnz (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("bnz", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BNZ_FEISAR));

  my_pair = *new pair_t ("bnz", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BNZ_GOTEKI45));

  my_pair = *new pair_t ("bnz", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BNZ_AURICOM));

  my_pair = *new pair_t ("bnz", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BNZ_ASSEGAI));

  my_pair = *new pair_t ("bnz", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BNZ_PIRANHA));

  my_pair = *new pair_t ("bnz", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BNZ_QIREX));

  my_pair = *new pair_t ("bnz", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BNZ_ICARAS));

  my_pair = *new pair_t ("bnz", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BNZ_ROCKET));

  my_pair = *new pair_t ("bnz", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BNZ_MISSILE));

  my_pair = *new pair_t ("bnz", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BNZ_MINE));

  my_pair = *new pair_t ("bnz", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BNZ_PLASMA));

  my_pair = *new pair_t ("bnz", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_BNZ_MINIPLASMA));
}

void
create_execute_bs (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("bs", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BS_FEISAR));

  my_pair = *new pair_t ("bs", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BS_GOTEKI45));

  my_pair = *new pair_t ("bs", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BS_AURICOM));

  my_pair = *new pair_t ("bs", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BS_ASSEGAI));

  my_pair = *new pair_t ("bs", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BS_PIRANHA));

  my_pair = *new pair_t ("bs", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BS_QIREX));

  my_pair = *new pair_t ("bs", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BS_ICARAS));

  my_pair = *new pair_t ("bs", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BS_ROCKET));

  my_pair = *new pair_t ("bs", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BS_MISSILE));

  my_pair = *new pair_t ("bs", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BS_MINE));

  my_pair = *new pair_t ("bs", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BS_PLASMA));

  my_pair = *new pair_t ("bs", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_BS_MINIPLASMA));
}

void
create_execute_nop (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("nop", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOP_FEISAR));

  my_pair = *new pair_t ("nop", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOP_GOTEKI45));

  my_pair = *new pair_t ("nop", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOP_AURICOM));

  my_pair = *new pair_t ("nop", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOP_ASSEGAI));

  my_pair = *new pair_t ("nop", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOP_PIRANHA));

  my_pair = *new pair_t ("nop", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOP_QIREX));

  my_pair = *new pair_t ("nop", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOP_ICARAS));

  my_pair = *new pair_t ("nop", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOP_ROCKET));

  my_pair = *new pair_t ("nop", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOP_MISSILE));

  my_pair = *new pair_t ("nop", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOP_MINE));

  my_pair = *new pair_t ("nop", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_NOP_PLASMA));

  my_pair = *new pair_t ("nop", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_NOP_MINIPLASMA));
}

void
create_execute_mov (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("mov", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MOV_FEISAR));

  my_pair = *new pair_t ("mov", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MOV_GOTEKI45));

  my_pair = *new pair_t ("mov", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MOV_AURICOM));

  my_pair = *new pair_t ("mov", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MOV_ASSEGAI));

  my_pair = *new pair_t ("mov", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MOV_PIRANHA));

  my_pair = *new pair_t ("mov", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MOV_QIREX));

  my_pair = *new pair_t ("mov", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MOV_ICARAS));

  my_pair = *new pair_t ("mov", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MOV_ROCKET));

  my_pair = *new pair_t ("mov", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MOV_MISSILE));

  my_pair = *new pair_t ("mov", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MOV_MINE));

  my_pair = *new pair_t ("mov", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MOV_PLASMA));

  my_pair = *new pair_t ("mov", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_MOV_MINIPLASMA));
}

void
create_execute_lc (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("lc", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LC_FEISAR));

  my_pair = *new pair_t ("lc", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LC_GOTEKI45));

  my_pair = *new pair_t ("lc", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LC_AURICOM));

  my_pair = *new pair_t ("lc", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LC_ASSEGAI));

  my_pair = *new pair_t ("lc", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LC_PIRANHA));

  my_pair = *new pair_t ("lc", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LC_QIREX));

  my_pair = *new pair_t ("lc", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LC_ICARAS));

  my_pair = *new pair_t ("lc", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LC_ROCKET));

  my_pair = *new pair_t ("lc", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LC_MISSILE));

  my_pair = *new pair_t ("lc", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LC_MINE));

  my_pair = *new pair_t ("lc", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LC_PLASMA));

  my_pair = *new pair_t ("lc", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LC_MINIPLASMA));
}

void
create_execute_ll (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("ll", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LL_FEISAR));

  my_pair = *new pair_t ("ll", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LL_GOTEKI45));

  my_pair = *new pair_t ("ll", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LL_AURICOM));

  my_pair = *new pair_t ("ll", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LL_ASSEGAI));

  my_pair = *new pair_t ("ll", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LL_PIRANHA));

  my_pair = *new pair_t ("ll", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LL_QIREX));

  my_pair = *new pair_t ("ll", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LL_ICARAS));

  my_pair = *new pair_t ("ll", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LL_ROCKET));

  my_pair = *new pair_t ("ll", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LL_MISSILE));

  my_pair = *new pair_t ("ll", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LL_MINE));

  my_pair = *new pair_t ("ll", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LL_PLASMA));

  my_pair = *new pair_t ("ll", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LL_MINIPLASMA));
}

void
create_execute_ldr (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("ldr", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDR_FEISAR));

  my_pair = *new pair_t ("ldr", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDR_GOTEKI45));

  my_pair = *new pair_t ("ldr", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDR_AURICOM));

  my_pair = *new pair_t ("ldr", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDR_ASSEGAI));

  my_pair = *new pair_t ("ldr", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDR_PIRANHA));

  my_pair = *new pair_t ("ldr", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDR_QIREX));

  my_pair = *new pair_t ("ldr", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDR_ICARAS));

  my_pair = *new pair_t ("ldr", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDR_ROCKET));

  my_pair = *new pair_t ("ldr", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDR_MISSILE));

  my_pair = *new pair_t ("ldr", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDR_MINE));

  my_pair = *new pair_t ("ldr", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDR_PLASMA));

  my_pair = *new pair_t ("ldr", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_LDR_MINIPLASMA));
}

void
create_execute_str (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("str", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STR_FEISAR));

  my_pair = *new pair_t ("str", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STR_GOTEKI45));

  my_pair = *new pair_t ("str", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STR_AURICOM));

  my_pair = *new pair_t ("str", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STR_ASSEGAI));

  my_pair = *new pair_t ("str", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STR_PIRANHA));

  my_pair = *new pair_t ("str", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STR_QIREX));

  my_pair = *new pair_t ("str", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STR_ICARAS));

  my_pair = *new pair_t ("str", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STR_ROCKET));

  my_pair = *new pair_t ("str", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STR_MISSILE));

  my_pair = *new pair_t ("str", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STR_MINE));

  my_pair = *new pair_t ("str", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STR_PLASMA));

  my_pair = *new pair_t ("str", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_STR_MINIPLASMA));
}

void
create_execute_ldb (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("ldb", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDB_FEISAR));

  my_pair = *new pair_t ("ldb", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDB_GOTEKI45));

  my_pair = *new pair_t ("ldb", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDB_AURICOM));

  my_pair = *new pair_t ("ldb", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDB_ASSEGAI));

  my_pair = *new pair_t ("ldb", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDB_PIRANHA));

  my_pair = *new pair_t ("ldb", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDB_QIREX));

  my_pair = *new pair_t ("ldb", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDB_ICARAS));

  my_pair = *new pair_t ("ldb", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDB_ROCKET));

  my_pair = *new pair_t ("ldb", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDB_MISSILE));

  my_pair = *new pair_t ("ldb", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDB_MINE));

  my_pair = *new pair_t ("ldb", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_LDB_PLASMA));

  my_pair = *new pair_t ("ldb", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_LDB_MINIPLASMA));
}

void
create_execute_stb (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("stb", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STB_FEISAR));

  my_pair = *new pair_t ("stb", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STB_GOTEKI45));

  my_pair = *new pair_t ("stb", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STB_AURICOM));

  my_pair = *new pair_t ("stb", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STB_ASSEGAI));

  my_pair = *new pair_t ("stb", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STB_PIRANHA));

  my_pair = *new pair_t ("stb", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STB_QIREX));

  my_pair = *new pair_t ("stb", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STB_ICARAS));

  my_pair = *new pair_t ("stb", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STB_ROCKET));

  my_pair = *new pair_t ("stb", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STB_MISSILE));

  my_pair = *new pair_t ("stb", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STB_MINE));

  my_pair = *new pair_t ("stb", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STB_PLASMA));

  my_pair = *new pair_t ("stb", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_STB_MINIPLASMA));
}

void
create_execute_write (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("write", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_WRITE_FEISAR));

  my_pair = *new pair_t ("write", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_WRITE_GOTEKI45));

  my_pair = *new pair_t ("write", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_WRITE_AURICOM));

  my_pair = *new pair_t ("write", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_WRITE_ASSEGAI));

  my_pair = *new pair_t ("write", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_WRITE_PIRANHA));

  my_pair = *new pair_t ("write", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_WRITE_QIREX));

  my_pair = *new pair_t ("write", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_WRITE_ICARAS));

  my_pair = *new pair_t ("write", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_WRITE_ROCKET));

  my_pair = *new pair_t ("write", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_WRITE_MISSILE));

  my_pair = *new pair_t ("write", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_WRITE_MINE));

  my_pair = *new pair_t ("write", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_WRITE_PLASMA));

  my_pair = *new pair_t ("write", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_WRITE_MINIPLASMA));
}

void
create_execute_stat (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("stat", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STAT_FEISAR));

  my_pair = *new pair_t ("stat", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STAT_GOTEKI45));

  my_pair = *new pair_t ("stat", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STAT_AURICOM));

  my_pair = *new pair_t ("stat", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STAT_ASSEGAI));

  my_pair = *new pair_t ("stat", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STAT_PIRANHA));

  my_pair = *new pair_t ("stat", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STAT_QIREX));

  my_pair = *new pair_t ("stat", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STAT_ICARAS));

  my_pair = *new pair_t ("stat", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STAT_ROCKET));

  my_pair = *new pair_t ("stat", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STAT_MISSILE));

  my_pair = *new pair_t ("stat", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STAT_MINE));

  my_pair = *new pair_t ("stat", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_STAT_PLASMA));

  my_pair = *new pair_t ("stat", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_STAT_MINIPLASMA));
}

void
create_execute_check (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("check", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CHECK_FEISAR));

  my_pair = *new pair_t ("check", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_CHECK_GOTEKI45));

  my_pair = *new pair_t ("check", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CHECK_AURICOM));

  my_pair = *new pair_t ("check", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CHECK_ASSEGAI));

  my_pair = *new pair_t ("check", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CHECK_PIRANHA));

  my_pair = *new pair_t ("check", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CHECK_QIREX));

  my_pair = *new pair_t ("check", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CHECK_ICARAS));

  my_pair = *new pair_t ("check", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CHECK_ROCKET));

  my_pair = *new pair_t ("check", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CHECK_MISSILE));

  my_pair = *new pair_t ("check", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CHECK_MINE));

  my_pair = *new pair_t ("check", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CHECK_PLASMA));

  my_pair = *new pair_t ("check", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_CHECK_MINIPLASMA));
}

void
create_execute_mode (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("mode", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MODE_FEISAR));

  my_pair = *new pair_t ("mode", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MODE_GOTEKI45));

  my_pair = *new pair_t ("mode", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MODE_AURICOM));

  my_pair = *new pair_t ("mode", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MODE_ASSEGAI));

  my_pair = *new pair_t ("mode", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MODE_PIRANHA));

  my_pair = *new pair_t ("mode", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MODE_QIREX));

  my_pair = *new pair_t ("mode", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MODE_ICARAS));

  my_pair = *new pair_t ("mode", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MODE_ROCKET));

  my_pair = *new pair_t ("mode", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MODE_MISSILE));

  my_pair = *new pair_t ("mode", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MODE_MINE));

  my_pair = *new pair_t ("mode", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_MODE_PLASMA));

  my_pair = *new pair_t ("mode", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_MODE_MINIPLASMA));
}

void
create_execute_fork (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("fork", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_FORK_FEISAR));

  my_pair = *new pair_t ("fork", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_FORK_GOTEKI45));

  my_pair = *new pair_t ("fork", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_FORK_AURICOM));

  my_pair = *new pair_t ("fork", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_FORK_ASSEGAI));

  my_pair = *new pair_t ("fork", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_FORK_PIRANHA));

  my_pair = *new pair_t ("fork", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_FORK_QIREX));

  my_pair = *new pair_t ("fork", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_FORK_ICARAS));

  my_pair = *new pair_t ("fork", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_FORK_ROCKET));

  my_pair = *new pair_t ("fork", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_FORK_MISSILE));

  my_pair = *new pair_t ("fork", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_FORK_MINE));

  my_pair = *new pair_t ("fork", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_FORK_PLASMA));

  my_pair = *new pair_t ("fork", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_FORK_MINIPLASMA));
}

void
create_execute_crash (map_t &my_map)
{
  pair_t &my_pair = *new pair_t ("crash", FEISAR);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CRASH_FEISAR));

  my_pair = *new pair_t ("crash", GOTEKI45);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_CRASH_GOTEKI45));

  my_pair = *new pair_t ("crash", AURICOM);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CRASH_AURICOM));

  my_pair = *new pair_t ("crash", ASSEGAI);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CRASH_ASSEGAI));

  my_pair = *new pair_t ("crash", PIRANHA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CRASH_PIRANHA));

  my_pair = *new pair_t ("crash", QIREX);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CRASH_QIREX));

  my_pair = *new pair_t ("crash", ICARAS);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CRASH_ICARAS));

  my_pair = *new pair_t ("crash", ROCKET);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CRASH_ROCKET));

  my_pair = *new pair_t ("crash", MISSILE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CRASH_MISSILE));

  my_pair = *new pair_t ("crash", MINE);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CRASH_MINE));

  my_pair = *new pair_t ("crash", PLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair, DELAY_EXECUTE_CRASH_PLASMA));

  my_pair = *new pair_t ("crash", MINIPLASMA);
  my_map.insert (std::pair<pair_t, int>(my_pair,
					DELAY_EXECUTE_CRASH_MINIPLASMA));
}

void
Delays::help_set (bool help)
{
  this->help_ = help;
}

void
Delays::debug_set (bool debug)
{
  this->debug_ = debug;
}

void
Delays::display_set (bool display)
{
  this->display_ = display;
}

void
Delays::mode_set (int mode)
{
  this->mode_ = mode;
}

void
Delays::laps_number_set (int laps_number)
{
  this->laps_number_ = laps_number;
}

void
Delays::memory_size_set (int memory_size)
{
  this->memory_size_ = memory_size;
}

void
Delays::checkpoints_per_lap_set (int checkpoints_per_lap)
{
  this->checkpoints_per_lap_ = checkpoints_per_lap;
}

void
Delays::checkpoint_delay_set (int checkpoint_delay)
{
  this->checkpoint_delay_ = checkpoint_delay;
}

void
Delays::blue_arrow_spacing_set (int blue_arrow_spacing)
{
  this->blue_arrow_spacing_ = blue_arrow_spacing;
}

void
Delays::verbose_set (int verbose)
{
  this->verbose_ = verbose;
}

void
Delays::file_add (std::string file)
{
  return this->vect_file_.push_back(file);
}

bool
Delays::help_get ()
{
  return this->help_;
}

bool
Delays::debug_get ()
{
  return this->debug_;
}

bool
Delays::display_get ()
{
  return this->display_;
}

int
Delays::mode_get ()
{
  return this->mode_;
}

int
Delays::laps_number_get ()
{
  return this->laps_number_;
}

int
Delays::memory_size_get ()
{
  return this->memory_size_;
}

int
Delays::checkpoints_per_lap_get ()
{
  return this->checkpoints_per_lap_;
}

int
Delays::checkpoint_delay_get ()
{
  return this->checkpoint_delay_;
}

int
Delays::blue_arrow_spacing_get ()
{
  return this->blue_arrow_spacing_;
}

int
Delays::verbose_get ()
{
  return this->verbose_;
}

std::vector<std::string>
Delays::vect_file_get ()
{
  return this->vect_file_;
}

void
create_decode (map_t &my_map)
{
  create_decode_add (my_map);
  create_decode_sub (my_map);
  create_decode_cmp (my_map);
  create_decode_addi (my_map);
  create_decode_cmpi (my_map);
  create_decode_asr (my_map);
  create_decode_neg (my_map);
  create_decode_and (my_map);
  create_decode_or (my_map);
  create_decode_xor (my_map);
  create_decode_not (my_map);
  create_decode_rol (my_map);
  create_decode_swp (my_map);
  create_decode_b (my_map);
  create_decode_bz (my_map);
  create_decode_bnz (my_map);
  create_decode_bs (my_map);
  create_decode_nop (my_map);
  create_decode_mov (my_map);
  create_decode_lc (my_map);
  create_decode_ll (my_map);
  create_decode_ldr (my_map);
  create_decode_str (my_map);
  create_decode_ldb (my_map);
  create_decode_stb (my_map);
  create_decode_write (my_map);
  create_decode_stat (my_map);
  create_decode_check (my_map);
  create_decode_mode (my_map);
  create_decode_fork (my_map);
  create_decode_crash (my_map);
}

void
create_execute (map_t &my_map)
{
  create_execute_add (my_map);
  create_execute_sub (my_map);
  create_execute_cmp (my_map);
  create_execute_addi (my_map);
  create_execute_cmpi (my_map);
  create_execute_asr (my_map);
  create_execute_neg (my_map);
  create_execute_and (my_map);
  create_execute_or (my_map);
  create_execute_xor (my_map);
  create_execute_not (my_map);
  create_execute_rol (my_map);
  create_execute_swp (my_map);
  create_execute_b (my_map);
  create_execute_bz (my_map);
  create_execute_bnz (my_map);
  create_execute_bs (my_map);
  create_execute_nop (my_map);
  create_execute_mov (my_map);
  create_execute_lc (my_map);
  create_execute_ll (my_map);
  create_execute_ldr (my_map);
  create_execute_str (my_map);
  create_execute_ldb (my_map);
  create_execute_stb (my_map);
  create_execute_write (my_map);
  create_execute_stat (my_map);
  create_execute_check (my_map);
  create_execute_mode (my_map);
  create_execute_fork (my_map);
  create_execute_crash (my_map);
}

void
Delays::create_idx_mod ()
{
  idx_mod_.push_back (IDX_MOD_FEISAR);
  idx_mod_.push_back (IDX_MOD_GOTEKI45);
  idx_mod_.push_back (IDX_MOD_AGSYSTEMS);
  idx_mod_.push_back (IDX_MOD_AURICOM);
  idx_mod_.push_back (IDX_MOD_ASSEGAI);
  idx_mod_.push_back (IDX_MOD_PIRANHA);
  idx_mod_.push_back (IDX_MOD_QIREX);
  idx_mod_.push_back (IDX_MOD_ICARAS);
  idx_mod_.push_back (IDX_MOD_ROCKET);
  idx_mod_.push_back (IDX_MOD_MISSILE);
  idx_mod_.push_back (IDX_MOD_MINE);
  idx_mod_.push_back (IDX_MOD_PLASMA);
  idx_mod_.push_back (IDX_MOD_MINIPLASMA);
}

Delays::Delays()
{
  create_decode (this->decode_delays_);
  create_execute (this->execute_delays_);
  create_idx_mod ();

  this->help_ = false;
  this->debug_ = false;
  this->display_ = false;
  this->mode_ = 0;
  this->laps_number_ = LAPS_NUMBER;
  this->memory_size_ = MEMORY_SIZE;
  this->checkpoints_per_lap_ = CHECKPOINTS_PER_LAP;
  this->checkpoint_delay_ = CHECKPOINT_DELAY;
  this->blue_arrow_spacing_ = BLUE_ARROW_SPACING;
  this->verbose_ = 0;
}

int
Delays::decode_delay_get (std::string instr, int mode)
{
  return this->decode_delays_[pair_t (instr, mode)];
}

int
Delays::execute_delay_get (std::string instr, int mode)
{
  return this->execute_delays_[pair_t (instr, mode)];
}

int
Delays::idx_mod_get (int mode)
{
  return this->idx_mod_[mode];
}

Delays&
Delays::get_instance ()
{
  if (!instance_)
    instance_ = new Delays;

  return *instance_;
}
