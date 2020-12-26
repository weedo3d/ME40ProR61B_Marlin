/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * power_loss_recovery.cpp - Resume an SD print after power-loss
 */

#include "MarlinConfig.h"

#if ENABLED(POWER_LOSS_RECOVERY)

#include "power_loss_recovery.h"

#include "cardreader.h"
#include "planner.h"
#include "printcounter.h"
#include "serial.h"
#include "temperature.h"

// Recovery data
job_recovery_info_t job_recovery_info;
extern uint8_t active_extruder, commands_in_queue, cmd_queue_index_r;

// perron add var
uint8_t job_saveoff = 0;

#if ENABLED(DEBUG_POWER_LOSS_RECOVERY)
  void debug_print_job_recovery(const bool recovery) {
    SERIAL_PROTOCOLLNPGM("---- Job Recovery Info ----");
    SERIAL_PROTOCOLPAIR("valid_head:", int(job_recovery_info.valid_head));
    SERIAL_PROTOCOLLNPAIR(" valid_foot:", int(job_recovery_info.valid_foot));
    if (job_recovery_info.valid_head) {
      if (job_recovery_info.valid_head == job_recovery_info.valid_foot) {
        SERIAL_PROTOCOLPGM("current_position: ");
        LOOP_XYZE(i) {
          SERIAL_PROTOCOL(job_recovery_info.current_position[i]);
          if (i < E_AXIS) SERIAL_CHAR(',');
        }
        SERIAL_EOL();
        SERIAL_PROTOCOLLNPAIR("feedrate: ", job_recovery_info.feedrate);

        #if HOTENDS > 1
          SERIAL_PROTOCOLLNPAIR("active_hotend: ", int(job_recovery_info.active_hotend));
        #endif

        SERIAL_PROTOCOLPGM("target_temperature: ");
        HOTEND_LOOP() {
          SERIAL_PROTOCOL(job_recovery_info.target_temperature[e]);
          if (e < HOTENDS - 1) SERIAL_CHAR(',');
        }
        SERIAL_EOL();

        #if HAS_HEATED_BED
          SERIAL_PROTOCOLLNPAIR("target_temperature_bed: ", job_recovery_info.target_temperature_bed);
        #endif

        #if FAN_COUNT
          SERIAL_PROTOCOLPGM("fanSpeeds: ");
          for (int8_t i = 0; i < FAN_COUNT; i++) {
            SERIAL_PROTOCOL(job_recovery_info.fanSpeeds[i]);
            if (i < FAN_COUNT - 1) SERIAL_CHAR(',');
          }
          SERIAL_EOL();
        #endif

        #if HAS_LEVELING
          SERIAL_PROTOCOLPAIR("leveling: ", int(job_recovery_info.leveling));
          SERIAL_PROTOCOLLNPAIR(" fade: ", int(job_recovery_info.fade));
        #endif
        SERIAL_PROTOCOLLNPAIR("cmd_queue_index_r: ", int(job_recovery_info.cmd_queue_index_r));
        SERIAL_PROTOCOLLNPAIR("commands_in_queue: ", int(job_recovery_info.commands_in_queue));
        if (recovery)
          for (uint8_t i = 0; i < job_recovery_commands_count; i++) SERIAL_PROTOCOLLNPAIR("> ", job_recovery_commands[i]);
        else
          for (uint8_t i = 0; i < job_recovery_info.commands_in_queue; i++) SERIAL_PROTOCOLLNPAIR("> ", job_recovery_info.command_queue[i]);
        SERIAL_PROTOCOLLNPAIR("sd_filename: ", job_recovery_info.sd_filename);
        SERIAL_PROTOCOLLNPAIR("sdpos: ", job_recovery_info.sdpos);
        SERIAL_PROTOCOLLNPAIR("print_job_elapsed: ", job_recovery_info.print_job_elapsed);
      }
      else
        SERIAL_PROTOCOLLNPGM("INVALID DATA");
    }
    SERIAL_PROTOCOLLNPGM("---------------------------");
  }
#endif // DEBUG_POWER_LOSS_RECOVERY

/**
 * Save the current machine state to the power-loss recovery file
 */
void save_job_recovery_info() 
{
    static millis_t next_save_ms; // = 0;  // Init on reset
    millis_t ms = millis();
  if (ELAPSED(ms, next_save_ms) || (current_position[Z_AXIS] > 0 && current_position[Z_AXIS] > job_recovery_info.current_position[Z_AXIS]) || (job_saveoff == 1))
  {
      next_save_ms = ms + SAVE_INFO_INTERVAL_MS;

    // Head and foot will match if valid data was saved
    if (!++job_recovery_info.valid_head) ++job_recovery_info.valid_head; // non-zero in sequence
    job_recovery_info.valid_foot = job_recovery_info.valid_head;

    // Machine state
    COPY(job_recovery_info.current_position, current_position);

    job_recovery_info.active_hotend = active_extruder;

    COPY(job_recovery_info.target_temperature, thermalManager.target_temperature);
    
	job_recovery_info.target_temperature_bed = thermalManager.target_temperature_bed;

    // Commands in the queue
    job_recovery_info.cmd_queue_index_r = cmd_queue_index_r;
    job_recovery_info.commands_in_queue = commands_in_queue;
    COPY(job_recovery_info.command_queue, command_queue);

    // Elapsed print job time
    job_recovery_info.print_job_elapsed = print_job_timer.duration();

    // SD file position
    card.getAbsFilename(job_recovery_info.sd_filename);
    job_recovery_info.sdpos = card.getIndex();

    #if ENABLED(DEBUG_POWER_LOSS_RECOVERY)
      SERIAL_PROTOCOLLNPGM("Saving...");
      debug_print_job_recovery(false);
    #endif

    card.openJobRecoveryFile(false);
    (void)card.saveJobRecoveryInfo();

  }
}

#endif // POWER_LOSS_RECOVERY
