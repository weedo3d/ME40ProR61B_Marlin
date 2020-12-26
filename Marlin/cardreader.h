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

#ifndef _CARDREADER_H_
#define _CARDREADER_H_

#include "MarlinConfig.h"

#if ENABLED(SDSUPPORT)

#define SD_RESORT ENABLED(SDCARD_SORT_ALPHA) && ENABLED(SDSORT_DYNAMIC_RAM)

#define MAX_DIR_DEPTH 1          // Maximum folder depth

#include "SdFile.h"

#include "WTPacket.h"

class CardReader {
public:
  CardReader();

  void initsd();
  void write_command(char *buf);

  void beginautostart();
  void checkautostart();

  bool openFile(char * const path, const bool read, const bool subcall=false);

  void appendFile(char * const path);

  void openLogFile(char * const path);

  int removeFile(const char * const name);

  void closefile(const bool store_location=false);

  void release();

  void openAndPrintFile(const char *name);
  
  void startFileprint();

  void stopSDPrint();

  void getStatus();

  int getPrintPercent();

  void printingHasFinished();

  void printFilename();

  void getPrintingFilename(char* filename);

  #if ENABLED(LONG_FILENAME_HOST_SUPPORT)
    void printLongPath(char *path);
  #endif

  void getfilename(uint16_t nr, const char* const match=NULL);

  uint16_t getnrfilenames();

  void getAbsFilename(char *t);

  void ls();

  void chdir(const char *relpath);

  int8_t updir();

  void setroot();

  const char* diveToFile(SdFile*& curDir, const char * const path, const bool echo);

  uint16_t get_num_Files();

  bool write(const void* buf, uint16_t nbyte);

  void openJobRecoveryFile(const bool read);

  void closeJobRecoveryFile();

  bool jobRecoverFileExists();

  int16_t saveJobRecoveryInfo();

  int16_t loadJobRecoveryInfo();

  void removeJobRecoveryFile();

  inline void pauseSDPrint() { sdprinting = false; }

  inline bool isFileOpen() { return file.isOpen(); }

  inline bool eof() { return sdpos >= filesize; }

  inline int16_t get() { sdpos = file.curPosition(); return (int16_t)file.read(); }

  inline void setIndex(const uint32_t index) { sdpos = index; file.seekSet(index); }

  inline uint32_t getIndex() { return sdpos; }

  inline uint8_t percentDone() { return (isFileOpen() && filesize) ? sdpos / ((filesize + 99) / 100) : 0; }

  inline char* getWorkDirName() { workDir.getFilename(filename); return filename; }

  void getsddata(char *buf, int readsize){sdpos = file.curPosition();file.read(buf, readsize);}

  uint32_t getpos(void){return sdpos;}

  inline char* longest_filename() { return longFilename[0] ? longFilename : filename; }

  void lsRoot(OutPacket* outp);

public:
  bool saving, logging, sdprinting, cardOK, filenameIsDir;
  char filename[FILENAME_LENGTH], longFilename[LONG_FILENAME_LENGTH];
  int8_t autostart_index;

private:
  SdFile root, workDir, workDirParents[MAX_DIR_DEPTH];
  uint8_t workDirDepth;

  Sd2Card sd2card;
  SdVolume volume;
  SdFile file;

  #if ENABLED(POWER_LOSS_RECOVERY)
    SdFile jobRecoveryFile;
  #endif

  #define SD_PROCEDURE_DEPTH 1
  #define MAXPATHNAMELENGTH (FILENAME_LENGTH*MAX_DIR_DEPTH + MAX_DIR_DEPTH + 1)
  uint8_t file_subcall_ctr;
  uint32_t filespos[SD_PROCEDURE_DEPTH];
  char proc_filenames[SD_PROCEDURE_DEPTH][MAXPATHNAMELENGTH];
  uint32_t filesize, sdpos;

  LsAction lsAction; 
  uint16_t nrFiles; 
  char* diveDirName;
  void lsDive(const char *prepend, SdFile parent, const char * const match=NULL);

};

#if 1 //PIN_EXISTS(SD_DETECT)
  #if ENABLED(SD_DETECT_INVERTED)
    #define IS_SD_INSERTED (READ(SD_DETECT_PIN) == HIGH)
  #else
    #define IS_SD_INSERTED (READ(SD_DETECT_PIN) == LOW)
  #endif
#else
  // No card detect line? Assume the card is inserted.
  #define IS_SD_INSERTED true
#endif

extern CardReader card;

#endif // SDSUPPORT

#if ENABLED(SDSUPPORT)
  #define IS_SD_PRINTING (card.sdprinting)
  #define IS_SD_FILE_OPEN (card.isFileOpen())
#else
  #define IS_SD_PRINTING (false)
  #define IS_SD_FILE_OPEN (false)
#endif



#endif // _CARDREADER_H_
