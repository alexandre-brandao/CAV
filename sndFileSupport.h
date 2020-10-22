//
// Created by alexandre on 10/22/20.
//

#ifndef CC_SNDFILESUPPORT_H
#define CC_SNDFILESUPPORT_H

//Particular includes
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sndfile.h>

//Declare Prototypes

int open_sound_file(SNDFILE** sndFILE, char* PATH, int MODE, SF_INFO* INFO);
void print_sound_info(char* PATH, SF_INFO INFO);
void cpySoundInfo(SF_INFO* out_SINFO, SF_INFO* in_SFINFO);



#endif //CC_SNDFILESUPPORT_H
