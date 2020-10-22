//
// Created by alexandre on 10/20/20.
//
//Typical System includes
#include <iostream>
#include <stdio.h>
#include <float.h>
#include <string.h>

//Personally created support functions
#include "sndFileSupport.h"


using namespace std;

void print_usage(char* progname) {
    printf("\nUsage [args]:%s [<input file> <output file>]\n");
    puts ("\n"
          "    Where the output file will the output wav file\n"
    );
}

int main( int argc, char* argv[]) {
    /*program - InputfileName - OutputFileName*/
    char* progname;
    char* infilename;
    char* outfilename;

    /*Sound declarations variables*/
    SNDFILE*  inFILE;
    SNDFILE* outFILE;
    SF_INFO in_sINFO;
    SF_INFO out_sINFO;

    int writecount;
    float duration;

    /*progname and remove bar*/
    progname = strrchr (argv [0], '/') ;
    cout << progname << endl;

    //Check if the number of arguments are corrects
    if (argc != 3) {
        print_usage(argv[0]);
        return 0;
    }

    //Set file names
    infilename = argv[1];
    outfilename= argv[2];

    //Confirm if filenames are the same
    if(strcmp(infilename,outfilename) == 0){
        cout << "Files have the same name, ignoring program" << endl;
        return 0;
    }

    if (infilename [0] == '-')
    {	printf ("Error : Input filename (%s) looks like an option.\n\n", infilename) ;
        print_usage (progname) ;
        return 1 ;
    }

    if (outfilename [0] == '-')
    {	printf ("Error : Output filename (%s) looks like an option.\n\n", outfilename) ;
        print_usage (progname) ;
        return 1 ;
    }

    memset (&in_sINFO, 0, sizeof (in_sINFO));

    //Open SndFile
    open_sound_file(&inFILE, infilename, SFM_READ, &in_sINFO);
    //Print sound settings
    print_sound_info(infilename, in_sINFO);

    cout << "\n Buffer Length: "<< in_sINFO.frames*in_sINFO.channels << endl;

    //READ file
    int buf [in_sINFO.frames * in_sINFO.channels];
    sf_readf_int(inFILE, buf, in_sINFO.frames);


    (out_sINFO).channels = 2;
    (out_sINFO).frames = 0;
    (out_sINFO).format = SF_FORMAT_WAV | SF_FORMAT_PCM_16 ;
    (out_sINFO).samplerate = (in_sINFO).samplerate;
    (out_sINFO).sections = 0;
    (out_sINFO).seekable = 0;

    /*Open output sound file*/
    //Write file
    open_sound_file(&outFILE, outfilename, SFM_WRITE, &out_sINFO);

    //sf_write_sync(outFILE);
    writecount = sf_write_int(outFILE, buf, in_sINFO.frames);
    sf_write_sync(outFILE);
    sf_error(outFILE);
    //Save file

    cout << "Writecount: " << writecount << endl;
    //out_sINFO.frames = in_sINFO.frames;
    duration= (out_sINFO.frames / out_sINFO.samplerate);
    print_sound_info(outfilename, out_sINFO);
    cout << "Duration: " << duration << endl;

    sf_close(inFILE);
    sf_close(outFILE);



}

