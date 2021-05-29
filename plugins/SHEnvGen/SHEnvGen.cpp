#include "SC_PlugIn.hpp"
#include "SHEnvGen.hpp"

#define IN_TRIG 0
#define IN_ATTACK 1
#define IN_RELEASE 2

#define AMP_MAX 1.0
#define AMP_MIN 0.0

#define MIN(x, y) x > y ? y : x;
#define MAX(x, y) x > y ? x : y;

static InterfaceTable *ft;

namespace SHEnvGen
{
    SHEnvGen::SHEnvGen()
    {
        mCalcFunc = make_calc_function<SHEnvGen, &SHEnvGen::next>();
        next(1);
    }

    void SHEnvGen::next(int nSamples)
    {
        const float gate = in0(IN_TRIG);
        if (gate)
        {
            state = Rise;
        }

        if (state == Rise)
        {
            const double attack = static_cast<double>(in0(IN_ATTACK));
            const double attack_step = attack / sampleRate();

            amp = MIN(amp + attack_step, AMP_MAX);

            if (amp == AMP_MAX)
            {
                state = Fall;
            }
        }
        else if (state == Fall)
        {
            const double release = static_cast<double>(in0(IN_RELEASE));
            const double release_step = release / sampleRate();

            amp = MAX(amp - release_step, AMP_MIN);

            if (amp == AMP_MIN)
            {
                state = Idle;
            }
        }

        out0(0) = amp;
    }

} // namespace SHEnvGen

PluginLoad(SHEnvGenUGens)
{
    ft = inTable;
    registerUnit<SHEnvGen::SHEnvGen>(ft, "SHEnvGen", false);
}
