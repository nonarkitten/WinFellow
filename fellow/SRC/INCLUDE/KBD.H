#ifndef KBD_H
#define KBD_H

/* ---------------- CHANGE LOG ----------------- 
Tuesday, September 19, 2000: nova
- added autofire events
*/

typedef enum {
  EVENT_INSERT_DF0,
  EVENT_INSERT_DF1,
  EVENT_INSERT_DF2,
  EVENT_INSERT_DF3,
  EVENT_EJECT_DF0,
  EVENT_EJECT_DF1,
  EVENT_EJECT_DF2,
  EVENT_EJECT_DF3,
  EVENT_EXIT,
  EVENT_BMP_DUMP,
  EVENT_RESOLUTION_NEXT,
  EVENT_RESOLUTION_PREV,
  EVENT_SCALEY_NEXT,
  EVENT_SCALEY_PREV,
  EVENT_SCALEX_NEXT,
  EVENT_SCALEX_PREV,
  EVENT_HARD_RESET,
  EVENT_JOY0_UP_ACTIVE,
  EVENT_JOY0_UP_INACTIVE,
  EVENT_JOY0_DOWN_ACTIVE,
  EVENT_JOY0_DOWN_INACTIVE,
  EVENT_JOY0_LEFT_ACTIVE,
  EVENT_JOY0_LEFT_INACTIVE,
  EVENT_JOY0_RIGHT_ACTIVE,
  EVENT_JOY0_RIGHT_INACTIVE,
  EVENT_JOY0_FIRE0_ACTIVE,
  EVENT_JOY0_FIRE0_INACTIVE,
  EVENT_JOY0_FIRE1_ACTIVE,
  EVENT_JOY0_FIRE1_INACTIVE,
  EVENT_JOY0_AUTOFIRE0_ACTIVE,
  EVENT_JOY0_AUTOFIRE0_INACTIVE,
  EVENT_JOY0_AUTOFIRE1_ACTIVE,
  EVENT_JOY0_AUTOFIRE1_INACTIVE,
  EVENT_JOY1_UP_ACTIVE,
  EVENT_JOY1_UP_INACTIVE,
  EVENT_JOY1_DOWN_ACTIVE,
  EVENT_JOY1_DOWN_INACTIVE,
  EVENT_JOY1_LEFT_ACTIVE,
  EVENT_JOY1_LEFT_INACTIVE,
  EVENT_JOY1_RIGHT_ACTIVE,
  EVENT_JOY1_RIGHT_INACTIVE,
  EVENT_JOY1_FIRE0_ACTIVE,
  EVENT_JOY1_FIRE0_INACTIVE,
  EVENT_JOY1_FIRE1_ACTIVE,
  EVENT_JOY1_FIRE1_INACTIVE,
  EVENT_JOY1_AUTOFIRE0_ACTIVE,
  EVENT_JOY1_AUTOFIRE0_INACTIVE,
  EVENT_JOY1_AUTOFIRE1_ACTIVE,
  EVENT_JOY1_AUTOFIRE1_INACTIVE,
  EVENT_DF1_INTO_DF0,
  EVENT_DF2_INTO_DF0,
  EVENT_DF3_INTO_DF0
} kbd_event;

#define KBDBUFFERLENGTH 512
#define KBDBUFFERMASK   511

typedef struct {
  UBY buffer[KBDBUFFERLENGTH];
  ULO inpos;
  ULO outpos;
} kbd_buffer_type;

typedef struct {
  kbd_buffer_type scancodes;
  kbd_buffer_type eventsEOL;
  kbd_buffer_type eventsEOF;
} kbd_state_type;

extern kbd_state_type kbd_state;

extern void kbdEventEOLAdd(UBY eventId);
extern void kbdEventEOFAdd(UBY eventId);
extern void kbdKeyAdd(UBY keyCode);

extern void kbdHardReset(void);
extern void kbdEmulationStart(void);
extern void kbdEmulationStop(void);
extern void kbdStartup(void);
extern void kbdShutdown(void);

extern void kbdQueueHandler(void);
extern void kbdEventEOLHandler(void);

void kbdQueueHandler(void);
void kbdEventEOLHandler(void);
void kbdEventEOFHandler(void);

extern void kbdQueueHandler(void);
extern void kbdEventEOLHandler(void);

extern UBY insert_dfX[4];

#endif
