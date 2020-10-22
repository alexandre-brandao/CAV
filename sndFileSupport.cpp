//
// Created by alexandre on 10/22/20.
//

#include "sndFileSupport.h"

using namespace std;
int open_sound_file(SNDFILE** sndFILE, char* PATH, int MODE, SF_INFO* INFO){
    if (((*sndFILE) = sf_open (PATH, MODE, INFO)) == NULL)
    {   printf ("Not able to open input file %s.\n", PATH) ;
        puts (sf_strerror (NULL)) ;
        return 1 ;
    }
    return 0;
}

void print_sound_info(char* PATH, SF_INFO INFO) {
    cout << " file:" << PATH << endl;
    cout << " frames: " << INFO.frames << endl;
    cout << " samplerate: " << INFO.samplerate << endl;
    cout << " channels: " << INFO.channels << endl;
    cout << " format: " << hex << INFO.format << dec << endl;
}

void cpySoundInfo(SF_INFO* out_sINFO, SF_INFO* in_sINFO) {
    (*out_sINFO).channels = (*in_sINFO).channels;
    (*out_sINFO).frames = (*in_sINFO).frames;
    (*out_sINFO).format = (*in_sINFO).format;
    (*out_sINFO).samplerate = (*in_sINFO).samplerate;
    (*out_sINFO).sections = (*in_sINFO).sections;
    (*out_sINFO).seekable = (*in_sINFO).seekable;
}




