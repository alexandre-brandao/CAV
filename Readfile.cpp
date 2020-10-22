//
// Created by alexandre on 10/20/20.
//
//Typical System includes
#include <iostream>
#include <stdio.h>
#include <float.h>
#include <string.h>

//Particular includes
#include <sndfile.h>

#define BLOCK_SIZE 4096*16

using namespace std;


void print_usage(char* progname) {
    printf("\nUsage [args]:%s [<input file> <output file>]\n");
    puts ("\n"
          "    Where the output file will the output wav file\n"
    );
}

int main( int argc, char* argv[]) {
    char* progname;
    char* infilename;
    char* outfilename;

    SNDFILE*  inFILE;
    SNDFILE* outFILE;
    SF_INFO in_sINFO;
    SF_INFO out_sINFO;

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

    //OPEN file
    if ((inFILE = sf_open (infilename, SFM_READ, &in_sINFO)) == NULL)
    {	printf ("Not able to open input file %s.\n", infilename) ;
        puts (sf_strerror (NULL)) ;
        return 1 ;
    }

    cout << "input:" << infilename << endl;
    cout << " frames: " << in_sINFO.frames << endl;
    cout << " samplerate: " << in_sINFO.samplerate << endl;
    cout << " channels: " << in_sINFO.channels << endl;
    cout << " format: " << hex << in_sINFO.format << dec << endl;
    cout << " Buf_LEN: "<< in_sINFO.frames*in_sINFO.channels << endl;

    //READ file

    float buf [(in_sINFO.frames/2)* in_sINFO.channels];
    sf_readf_float (inFILE, buf, in_sINFO.frames/2);

    //Write file
    outFILE = sf_open(outfilename, SFM_WRITE, &out_sINFO);
    out_sINFO = in_sINFO;
    sf_write_float(outFILE,buf, in_sINFO.frames);

    sf_close(inFILE);
    sf_close(outFILE);



}

