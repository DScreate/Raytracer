#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "getopt_longer.h"
#include "perlin.h"

static struct option_help opth[] = {
        // elements are:
        // name       has_arg   flag   val
        {{"dimensions", REQ_ARG, NULL, 'd'},
                "    Use # dimensions (1-3, default: 1).\n"
        },
        {{"frequency",  REQ_ARG, NULL, 'f'},
                "    Use # for turbulence (only) frequency (default: 1.0).\n"
        },
        {{"help",       NO_ARG,  NULL, 'h'}, // "--help" aliased to short "-h"
                "    Print out (this) usage information.\n"
        },
        {{"random",     REQ_ARG, NULL, 'r'},
                "    Use given int value as random seed (default: 42).\n"
        },
        {{"samples",    REQ_ARG, NULL, 'n'},
                "    Use # of samples (default: 10).\n"
        },
        {{"scale",      REQ_ARG, NULL, 's'},
                "    Scale the noise*() arguments by # (default: 1).\n"
        },
        {{"turbulence", NO_ARG,  NULL, 't'},
                "    Use Perlin turbulence (with noise3()) (default: no).\n"
        },
        {{NULL,         NO_ARG,  NULL, 0},  // end of opth table
                NULL}
        // note: All "flag"s == NULL means that "getopt_long()" will
        // return "val" for all options.
};

/*
int main(int argc, char **argv)
{
    int i, c;
    int nDims = 1;
    int nSamp = 10;
    double scale = 1.0;
    int useTurbulence = 0;
    double frequency = 1.0;
    double minValue;
    double maxValue;
    int seed = 42;

    for (;;) {
        int iOpt = 0;

        c = getopt_longer(argc, argv, opth, &iOpt);
        if (c == -1)
            break;

        switch (c) {

        case 'd':
            nDims = atoi(optarg);
            if (nDims < 1 || 3 < nDims) {
                opth_printUsage(opth, argv[0]);
                exit(EXIT_FAILURE);
            }
            break;

        case 'f':
            frequency = atof(optarg);
            break;

        case 'h':
			opth_printUsage(opth, argv[0]);
			exit(EXIT_SUCCESS);

        case 'n':
            nSamp = atoi(optarg);
            if (nSamp < 1) {
                opth_printUsage(opth, argv[0]);
                exit(EXIT_FAILURE);
            }
            break;

        case 's':
            scale= atof(optarg);
            break;

        case 'r':
            seed = atoi(optarg);
            break;

        case 't':
            useTurbulence = 1;
            nDims = 3; // turbulence requires a 3-element argument
            break;

        default:
            fprintf(stderr,
                "***error: getopt returned character code 0x%x -- exiting\n",
                c);
			exit(EXIT_FAILURE);
        }
    }

    srandom(seed);
    for (i = 0; i < nSamp; i++) {
        double p[3];
        double value;

        switch (nDims) {

        case 1:
            p[0] = (scale * random()) / RAND_MAX;
            break;

        case 2:
            p[0] = (scale * random()) / RAND_MAX;
            p[1] = (scale * random()) / RAND_MAX;
            break;

        case 3:
            p[0] = (scale * random()) / RAND_MAX;
            p[1] = (scale * random()) / RAND_MAX;
            p[2] = (scale * random()) / RAND_MAX;
            break;

        default:
            assert(0); // not reached
        }
        if (useTurbulence)
            value = turbulence(p, frequency);
        else
            value = noise(p, nDims);

        if (i == 0) {
            minValue = maxValue = value;
        } else {
            if (value < minValue)
                minValue = value;
            if (value > maxValue)
                maxValue = value;
        }
    }
    printf("minimum: %lf\n", minValue);
    printf("maximum: %lf\n", maxValue);
    return 0;
}
*/