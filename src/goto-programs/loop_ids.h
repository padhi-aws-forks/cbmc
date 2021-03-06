/*******************************************************************\

Module: Loop IDs

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

/// \file
/// Loop IDs

#ifndef CPROVER_GOTO_PROGRAMS_LOOP_IDS_H
#define CPROVER_GOTO_PROGRAMS_LOOP_IDS_H

#include <util/ui_message.h>

class goto_functionst;
class goto_modelt;
class goto_programt;

void show_loop_ids(
  ui_message_handlert::uit,
  const goto_modelt &);

void show_loop_ids(
  ui_message_handlert::uit,
  const goto_functionst &);

void show_loop_ids(
  ui_message_handlert::uit,
  const irep_idt &function_id,
  const goto_programt &);

#endif // CPROVER_GOTO_PROGRAMS_LOOP_IDS_H
